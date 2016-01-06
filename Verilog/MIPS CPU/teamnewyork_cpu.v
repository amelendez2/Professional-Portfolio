// Sign extender
module signextend(input wire [15:0] inputVal, output wire [31:0] outputVal);

    assign outputVal = { {16{inputVal[15]}}, inputVal };

endmodule

// 32-bit 2 to 1 Multiplexer
module twotoonemux(input wire [31:0] input1, input wire [31:0] input2, input wire sel, output wire [31:0] outputval);

    assign outputval = (sel == 0) ? input1 : input2;

endmodule

// 5-bit 2 to 1 Multiplexer
module twotoonemux_5bit(input wire [4:0] input1, input wire [4:0] input2, input wire sel, output wire [4:0] outputval);

    assign outputval = (sel == 0) ? input1 : input2;

endmodule

// Arithmetic Logic Unit
module alu(input wire [31:0] op1,input wire [31:0] op2,input wire [3:0] ctrl,output wire [31:0] result);

    assign result = (ctrl == 4'b0000) ? (op1 & op2) : ((ctrl == 4'b0001) ? (op1 | op2) : 
        ((ctrl == 4'b0010) ? (op1 + op2) : ((ctrl == 4'b0110) ? (op1 - op2) : 
        ((ctrl == 4'b0111) ? ((op1 < op2) ? 1 : 0) : ((ctrl == 4'b1100) ? (~(op1 | op2)) : (op1 + op2)) ) ) ) );

endmodule

// ALU Control
module alucontrol(input wire [5:0] func, input wire [1:0] aluOp, output wire [3:0] aluctrl);

    reg [3:0] ialuctrl;    
        
  always @(aluOp, func)        // If Opcode indicates an R-type format or LW/SW
    begin
        if ((func == 6'b100000) | aluOp == 2'b00) begin        // If func is add, send Add signal through aluctrl
            ialuctrl <= 4'b0010;
        end else if (func == 6'b100010) begin                // If func is sub, send Sub signal through aluctrl
            ialuctrl <= 4'b0110;
        end else if (func == 6'b100100) begin                // If func is and, send AND signal through aluctrl
            ialuctrl <= 4'b0000;
        end else if (func == 6'b100101) begin                // If func is or, send OR signal through aluctrl
            ialuctrl <= 4'b0001;
        end else if (func == 6'b101010) begin                // If func is set on less than, send signal through aluctrl
            ialuctrl <= 4'b0111;
        end
    end
     
    assign aluctrl = ialuctrl; 
     
endmodule

// Register File
module registerfile(input wire rst, input wire [4:0] readReg1, input wire [4:0] readReg2, input wire [4:0] writeReg, 
    input wire [31:0] writeData, input wire regWrite, output reg [31:0] readData1, output reg [31:0] readData2);

    // Register file
    reg [31:0] register[31:0];

    integer i;

    always @(posedge rst)
    begin
        for(i=0;i<32;i=i+1)
        begin
            register[i] = 0;
        end
    end

    always @(readReg1)
    begin
        readData1 = register[readReg1];
        //readData1 = 1;
    end

    always @(readReg2)
    begin
        readData2 = register[readReg2];
    end

    always @(posedge regWrite)
    begin
        if(writeReg != 0)
            register[writeReg] = writeData;
    end

endmodule

// Data Memory
module datamem(input wire rst, input wire [6:0] memAddr, input wire memRead, input wire memWrite, 
    input wire [31:0] writeData, output reg [31:0] readData);

    // Memory
    reg [31:0] memory[127:0];

    integer i;

    always @(posedge rst)
    begin
        for(i=0;i<128;i=i+1)
        begin
            memory[i] = 0;
        end
    end

    always @(posedge memRead)
    begin
        readData = memory[memAddr];
    end

    always @(posedge memWrite)
    begin
        memory[memAddr] = writeData;
    end

endmodule

// FSM portion of Control Path (RegWrite, MemRead, MemWrite)
module controlpathfsm(input wire rst, input wire clk, input wire newInstruction, input wire [5:0] opcode, 
                        output reg _RegWrite, output reg _MemRead, output reg _MemWrite);
  reg [2:0] control_path_state;  

    //Reset control path
    always @(posedge rst)
        begin
            control_path_state = 0;
            _RegWrite = 0;
            _MemRead  = 0;
            _MemWrite = 0;
        end                  

    //Reset control path
    always @(posedge newInstruction)
        begin
            control_path_state = 0;
            _RegWrite = 0;
            _MemRead  = 0;
            _MemWrite = 0;
        end 


    //Next State Logic 
     always @(posedge clk)
        begin
            //switch state of control path 
            case(control_path_state)  
                0: begin 
                  control_path_state= 3'b001;
                  
                  end
                1: control_path_state= 3'b010;
                2: control_path_state = (opcode ==0 ) ? 3'b100 : 3'b011;    
                
                //JUMP to Write Back Stage if SUB,AND,ADD instruction
                3: begin

                        _MemRead  = (opcode == 35) ? 1 : 0;
                        _MemWrite = (opcode == 43) ? 1:  0;
                        
                        control_path_state =3'b100; 

                   end

                4: begin
                        _RegWrite = (opcode == 43 ) ? 0 : 1; 
                        control_path_state = 3'b000;
                   end
                
            endcase
        end  

endmodule

// Combinational logic portion of Control Path (MemToReg, RegDst, ALUSrc, ALUOp)
module controlpathcomb(input wire [5:0] opcode, output wire _MemToReg, 
                    output wire _RegDst, output wire _ALUSrc, output wire [1:0] _ALUOp);
                    
                  //  lw 35 sw 43

reg [5:0] OpCode;
reg MemToReg, RegDst, ALUSrc;
reg [1:0] ALUOp;
  
always@(opcode)
begin
  if (opcode==0)
         // arithmetic and logic operations
      begin    
              MemToReg = 1;
              RegDst = 1;
              ALUSrc = 0;
              ALUOp = 2'b10;
          end

    //load word
  else if(opcode ==35) 
      begin
             MemToReg = 0;
              RegDst = 0;
            ALUSrc = 1;
            ALUOp = 2'b00;
        end

    //store word
  else if(opcode ==43)
      begin
            MemToReg = 1;
              RegDst =  0 ;
              ALUSrc =  1 ;
              ALUOp =  2'b00 ;
      end

  end

// Set the output wires to our register values
assign _MemToReg = MemToReg; 
assign _RegDst = RegDst;
assign _ALUSrc = ALUSrc;
assign _ALUOp = ALUOp;

endmodule

// The entire CPU without PC, instruction memory, and branch circuit
module mipscpu(input wire reset, input wire clock, input wire [31:0] instrword, input wire newinstr);

wire RegWrite;
wire MemRead;
wire MemWrite;
wire MemToReg;
wire RegDst; 
wire ALUSrc; 
wire [1:0] ALUOp;
wire [31:0] _readData1;
wire [31:0] _readData2;
wire [31:0] _outputval;
wire [31:0] _readData;
wire [31:0] _result;
wire [31:0] outputval_muxa;
wire [31:0] outputval_muxb;
wire [4:0] outputval_mux5;
wire [3:0] _aluctrl;

//----------------- Instantiate each module and connect wires between modules -----------------------------
controlpathfsm mycontrolpathfsm(reset, clock, newinstr, instrword [31:26], RegWrite, MemRead, MemWrite);
controlpathcomb mycontrolpathcomb(instrword[31:26], MemToReg, RegDst, ALUSrc, ALUOp);
registerfile myregisterfile(reset, instrword[25:21], instrword[20:16], outputval_mux5, outputval_muxb, RegWrite, _readData1, _readData2);

signextend mysignextend(instrword[15:0], _outputval);
twotoonemux mytwotoonemuxa(_readData2, _outputval, ALUSrc, outputval_muxa);
twotoonemux mytwotoonemuxb(_readData, _result, MemToReg, outputval_muxb);
twotoonemux_5bit mytwotoonemux_5bit(instrword[20:16], instrword[15:11], RegDst, outputval_mux5);
alu myalu(_readData1, outputval_muxa, _aluctrl, _result);
alucontrol myalucontrol(instrword[5:0], ALUOp, _aluctrl);

datamem mydatamem(reset, _result[6:0], MemRead, MemWrite, _readData2, _readData);


endmodule