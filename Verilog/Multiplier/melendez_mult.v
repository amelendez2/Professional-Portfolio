module multiplier (rst, clk, multiplier, multiplicand, product);
//-------- Inputs ----------
	input rst, clk;
	input [31:0] multiplier, multiplicand;
	wire [31:0] multiplier, multiplicand;
	output [63:0] product;
	reg [63:0] product;
	reg [63:0] internal_multiplicand;
	reg [31:0] internal_multiplier;
	reg [5:0] count;
	reg [3:0] state;

//---------- States --------
	parameter [3:0] init = 2'b00, add = 2'b01, shift = 2'b10, done = 2'b11;
	
//---------- Main ----------
	always @(posedge clk)
      if (rst == 1) begin					// Begin FSM on reset
			state <= init;				// Send to initial state
        end else begin
			case (state)				// Loop through states
				init: begin
					count <= 0; product <= 0; 
					internal_multiplier <= multiplier; 
					internal_multiplicand <= multiplicand;			//Initialize our variables
                   
					if (multiplier[0] == 1) begin
						state <= add;				// set state as add if lsb is 1
					end else if (multiplier[0] == 0)
						state <= shift;				// set state shift if lsb is 0
				end
				
				add: begin
					product = product + internal_multiplicand;			// product initially 0, add the multiplicand to the product if we go into this state
					state <= shift;										// Done with add now we need to shift
				end
				
				shift: begin
					internal_multiplier = internal_multiplier >> 1;		// Shift logic right by 1 for multiplier, this will help check for add
					internal_multiplicand = internal_multiplicand << 1;	// Shift logic left by 1 for next add phase
					count = count + 1;										// count every time we shift, if we shift 32 times this is the end of multiply since 32 bit
                  if (((internal_multiplier [0] == 1) && (count < 32)))	// Check lsb for either add or shift
						state <= add;
                  else if(((internal_multiplier [0] == 0) && (count < 32)))
						state <= shift;
					else if (count >= 32) begin									// If shift 32 we have exhausted our multiplier of all bits so go to done
						state <= done;
					end
				end
				
				done: begin														// Loop infinitely in done state until reset                 
                  if(rst == 1) begin
					state <= init;
					end else if(rst == 0) begin
					state <= done;
                  end
                end
				
				default: begin
					state <= init;
				end
				
			endcase
		end
endmodule
						