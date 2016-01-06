// ------- ALU Module -------
module alu(
	input wire [31:0] op1, 
	input wire [31:0] op2, 
	input wire [3:0] ctrl, 
	output reg [31:0] result
	);
//-------- States --------
parameter AND = 4'b0000, OR = 4'b0001, add = 4'b0010, subtract = 4'b0110, setonlessthan = 4'b0111, NOR = 4'b1100;

//-------- Outputs of ALU ------
  always @(op1, op2, ctrl)
	// Based off of our ctrl signal we move to needed function
	if(ctrl[3:0] == AND) begin
		result = op1 & op2;
    end else if(ctrl[3:0] == OR) begin
		result = op1 | op2;
	end else if(ctrl[3:0] == add) begin
		result = op1 + op2;
	end else if(ctrl[3:0] == subtract) begin
		result = op1 - op2;
	end else if(ctrl[3:0] == setonlessthan) begin	
		result = (op1 < op2) ? 1:0;					//If less than set to 1 else set to 0
	end else if(ctrl[3:0] == NOR) begin
        result = ~(op1 | op2);						// If either bit is 1 output 0 else 1
	end
	
endmodule
//----------------------------------------------------------

//----- 2 to 1 Multiplexer ----------
module twotoonemux(
	input wire [31:0] input1, 
	input wire [31:0] input2, 
	input wire sel, 
	output wire [31:0] outputval
	);
//------- Assign statement -------
/*------- if sel is 0 outputval will send input1 through
*-------- else if its 1 input 2 goes through*/
	assign outputval = sel ? input2 : input1;		
	
endmodule
//------------------------------------------------------------

//-------- Register File --------------
module registerfile(
	input wire [4:0] readReg1, 
	input wire [4:0] readReg2, 
	input wire [4:0] writeReg,
	input wire [31:0] writeData, 
	input wire regWrite, 
	output reg [31:0] readData1,
	output reg [31:0] readData2
	);

//-------- Register -------------
reg [31:0] regmem [0:31];

//-------- Main --------------
assign readData1 = regmem[readReg1];		//Grabs the 5 bit value from readReg and accesses that register
assign readData2 = regmem[readReg2];		// within the register file then sets readData to the value of that register
  always @(regWrite)						// When regWrite signal, send value of writeData to the register accessed by writeReg
    regmem[writeReg]=writeData;
	
endmodule
//------------------------------------------------------------


//--------- 16 to 32 bit sign extender -----------------------
module signextend(
	input wire [15:0] inputVal, 
	output wire [31:0] outputVal
	);
	
  assign outputVal = {{16{inputVal[15]}}, inputVal};	//concatenates 16 bits onto our input and replicates the MSB 
	
endmodule


