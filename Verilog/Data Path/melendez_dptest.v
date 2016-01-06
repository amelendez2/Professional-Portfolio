module muxtest;

reg [31:0] input1, input2;
reg sel;
wire [31:0] outputval;

twotoonemux mymux(
	input1, 
	input2, 
	sel, 
	outputval
	);

initial
	begin
		//---- Test is the mux sends input1 or input2 based on the selection switch
		$dumpfile("twotoonemux.vcd");
		$dumpvars(0,muxtest);    			
		$monitor("input1 = %h, input2 = %h, sel = %d, outputval = %h.", input1, input2, sel, outputval);
		input1 = 32'hffff;
		input2 = 32'heeee;
		sel = 1;
		
		#20 
		$finish;
		
	end
endmodule


module signextendtest;

reg [15:0] inputVal;
wire [31:0] outputVal;

signextend mysignextend(
	inputVal, 
	outputVal
	);
	
initial
	begin
		//-------- inputVal will be sign extended to 32 bits whether it's a 1 or a 0 at the MSB
		$dumpfile("signextend.vcd");
		$dumpvars(0,signextendtest);    			
		$monitor("inputVal = %b, outputVal = %b.", inputVal, outputVal);
		inputVal = 16'b1000000000000001;
		
		#20 
		$finish;
		
	end
endmodule
	
	
module regfiletest;

reg [4:0] readReg1;
reg [4:0] readReg2; 
reg [4:0] writeReg;
reg [31:0] writeData; 
reg regWrite;
wire [31:0] readData1;
wire [31:0] readData2;

registerfile myregisterfile(
	readReg1, 
	readReg2, 
	writeReg,
	writeData, 
	regWrite, 
	readData1,
	readData2
	);

initial
	begin
		//---- Initially we write data into a register then we read that register to ensure that value is saved
		$dumpfile("registerfile.vcd");
		$dumpvars(0,regfiletest);    			
		$monitor("readReg1 = %d, readReg2 = %d,writeData = %h, writeReg = %d, regWrite = %d, readData1 = %h, readData2 = %h. ",
		readReg1, readReg2, writeData, writeReg, regWrite, readData1, readData2);
		
		writeReg = 3;
		regWrite = 1;
		writeData = 12;
		#20
		#20 readReg1 = 1; readReg2 = 3;
		
		
		#20 
		$finish;
		
	end
endmodule	


module alutest;

	reg [31:0] op1; 
	reg [31:0] op2; 
	reg [3:0] ctrl; 
	wire [31:0] result;

alu myalu(
	op1, 
	op2, 
	ctrl, 
	result
	);

initial
	begin
		//---- We test each part of our ALU. As the ctrl switch changes it will perform the desired function
		$dumpfile("alu.vcd");
		$dumpvars(0,alutest);    			
		$monitor("op1 = %d, op2 = %d,ctrl = %h, result = %d.", op1, op2, ctrl, result);
		
		op1 = 32'b10101101; op2 = 32'b11011110; ctrl = 0;		// And
		#40 op1 = 32'b00001101; op2 = 32'b10001000; ctrl = 1;	// Or
      	#40 op1 = 5; op2 = 4; ctrl = 2;							// Add
      	#40 op1 = 25; op2 = 13; ctrl = 3;						// Subtract
      	#40 op1 = 8; op2 = 7; ctrl = 7;							// Set on less than op1>op2, then op1<op2
      	#40 op1 = 41; op2 = 48; ctrl = 7;
      	#40 op1 = 32'b10101101; op2 = 32'b11011110; ctrl = 12;	// NOR
		$finish;
		
	end
endmodule	
	
	
	
	
	