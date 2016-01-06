module multiplier_tb;
	//----- Inputs and Outputs -------
	reg [31:0] multiplier, multiplicand;
	wire [63:0] product;
	reg clk, rst;
  //------- Instantiate our multiplier module -------
  multiplier mymultiplier(rst, clk, multiplier, multiplicand, product);		
  
  //--------- initialize clock and reset ---------
  initial
    begin
      clk = 0;				
      rst = 0;     
    end
  
  	initial forever
      #1 clk = ~ clk;			// Set clk to to change every 1 time increment
        
	initial
		begin
			rst = 1;
          	
          $dumpfile("multiplier.vcd");				// Create dump file
		  $dumpvars(0,multiplier_tb);    			// This will check from 0 to the end of our module
          $monitor("multiplier = %d, multiplicand = %d, product = %d.", multiplier, multiplicand, product);		// This will display our variable and product to check multiply
			
			multiplier = 3;		multiplicand = 5;				// The following lines are test values that we send into the module
			#50 multiplier = 100;	multiplicand = 100;
			#50 multiplier = 41;	multiplicand = 1;
          	#50 multiplier = 1000000000;	multiplicand = 250;				// Check large numbers
			#50 multiplier = 32'hffffffff;	multiplicand = 32'hffffffff;		//Check large numbers
			#150
          	rst = 0;
			$finish;
		end
endmodule