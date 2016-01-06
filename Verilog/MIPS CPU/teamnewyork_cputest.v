module cpu_test_bench;
   
    reg _reset; 
    reg _clock; 
    reg [31:0] _instrword;
    reg _newinstr;
    mipscpu myCPU(_reset, _clock, _instrword, _newinstr);
    
    // Initialize registers
    
    initial
        begin
            _clock =0;
        end
    
    always
      begin
     #1 _clock = ~ _clock;
      end
    
    initial
        begin
          $dumpfile("mipscpu.vcd");
		  $dumpvars(0,cpu_test_bench);    			
          $monitor("a = %d, \nb = %d, \nc = %d, \nd = %d, \nreg0 = %d, \nreg1 = %d, \nreg2 = %d, \nreg3 = %d, \nreg4 = %d, \nreg5 = %d.", myCPU.mydatamem.memory[0], myCPU.mydatamem.memory[1], myCPU.mydatamem.memory[2], myCPU.myregisterfile.register[4], myCPU.myregisterfile.register[0], myCPU.myregisterfile.register[1], myCPU.myregisterfile.register[2], myCPU.myregisterfile.register[3],myCPU.myregisterfile.register[4], myCPU.myregisterfile.register[5]);  
        _reset = 1;
        #20  
        //myCPU.myregisterfile.register[0] =0;
        myCPU.mydatamem.memory[0] = 10; // a = 10
        myCPU.mydatamem.memory[1] = 22; // b = 22
        myCPU.mydatamem.memory[2] = 6; // c = 6
        
		#20
        _instrword = 32'b10001100000000010000000000000000;
        _newinstr = 0;
        #1 _newinstr = 1;
        #10 _newinstr = 0;
        

        #10;
        //Checkin instruction 
         //$display("%d", myCPU.mycontrolpathcomb.opcode);
         //$display("%d", myCPU.myregisterfile.readReg1);
         //$display("%d", myCPU.myregisterfile.readReg2);
         //$display("%d", myCPU.mysignextend.inputVal);

         //Checking Signals
         //$display("Checking Signals");
         //$display("%d", myCPU.mycontrolpathfsm._MemRead);
         //$display("%d", myCPU.mycontrolpathfsm._MemWrite);
         //$display("%d", myCPU.mycontrolpathfsm._RegWrite);

         //Checking Memory Module
         //$display("Checking Data");
         //$display("%d", myCPU.mydatamem.memRead);
         //$display("%d", myCPU._aluctrl);

         //Checking ALU
         //$display("Checking ALU");
         //$display("%d", myCPU.myalu.op1);
         //$display("%d", myCPU.myalu.op2);
         // $display("%d", myCPU.myalu.ctrl);
         // $display("%d", myCPU.myalu.result);
         //$display("%d", myCPU.myalucontrol.aluOp);
         //$display("%d", myCPU.myalucontrol.aluctrl);

         //Checking Register File
         //$display("Checking Register File");
         //$display("%d", myCPU.myregisterfile.readReg1);
         //$display("%d", myCPU.myregisterfile.readReg2);
         //$display("%d", myCPU.myregisterfile.regWrite);
         //$display("%d", myCPU.myregisterfile.readData1);
         //$display("%d", myCPU.myregisterfile.register[1]);
         
        _instrword = 32'b10001100000000100000000000000001;
        
        _newinstr = 0;
        #1 _newinstr = 1;
        #10 _newinstr = 0;
        
        #10;

         _instrword = 32'b10001100000000110000000000000010;

        
        _newinstr = 0;
        #1 _newinstr = 1;
        #1 _newinstr = 0;
        
        #10;

        _instrword = 32'b00000000001000100010100000100000;

        _newinstr = 0;
        #1 _newinstr = 1;
        #1 _newinstr = 0;
        
        #10;

        _instrword = 32'b00000000101000110010000000100010;

        _newinstr = 0;
        #1 _newinstr = 1;
        #1 _newinstr = 0;
        
        #10;
          
        //////////////
		
		#20  
        //myCPU.myregisterfile.register[0] =0;
        myCPU.mydatamem.memory[0] = 8; // a = 10
        myCPU.mydatamem.memory[1] = 2; // b = 22
        myCPU.mydatamem.memory[2] = 3; // c = 6
        
		#20
        _instrword = 32'b10001100000000010000000000000000;
        _newinstr = 0;
        #1 _newinstr = 1;
        #10 _newinstr = 0;
        

        #10;
		_instrword = 32'b10001100000000100000000000000001;
        
        _newinstr = 0;
        #1 _newinstr = 1;
        #10 _newinstr = 0;
        
        #10;

         _instrword = 32'b10001100000000110000000000000010;

        
        _newinstr = 0;
        #1 _newinstr = 1;
        #1 _newinstr = 0;
        
        #10;

        _instrword = 32'b00000000001000100010100000100000;

        _newinstr = 0;
        #1 _newinstr = 1;
        #1 _newinstr = 0;
        
        #10;

        _instrword = 32'b00000000101000110010000000100010;

        _newinstr = 0;
        #1 _newinstr = 1;
        #1 _newinstr = 0;
        
        #10;
		/////////////////////////
		#20  
        //myCPU.myregisterfile.register[0] =0;
        myCPU.mydatamem.memory[0] = 1024; // a = 10
        myCPU.mydatamem.memory[1] = 2056; // b = 22
        myCPU.mydatamem.memory[2] = 3000; // c = 6
        
		#20
        _instrword = 32'b10001100000000010000000000000000;
        _newinstr = 0;
        #1 _newinstr = 1;
        #10 _newinstr = 0;
        

        #10;
		_instrword = 32'b10001100000000100000000000000001;
        
        _newinstr = 0;
        #1 _newinstr = 1;
        #10 _newinstr = 0;
        
        #10;

         _instrword = 32'b10001100000000110000000000000010;

        
        _newinstr = 0;
        #1 _newinstr = 1;
        #1 _newinstr = 0;
        
        #10;

        _instrword = 32'b00000000001000100010100000100000;

        _newinstr = 0;
        #1 _newinstr = 1;
        #1 _newinstr = 0;
        
        #10;

        _instrword = 32'b00000000101000110010000000100010;

        _newinstr = 0;
        #1 _newinstr = 1;
        #1 _newinstr = 0;
        
        #10;
		////////////////////
		#20  
        //myCPU.myregisterfile.register[0] =0;
        myCPU.mydatamem.memory[0] = 1000000000; // a = 10
        myCPU.mydatamem.memory[1] = 2000000000; // b = 22
        myCPU.mydatamem.memory[2] = 500000000; // c = 6
        
		#20
        _instrword = 32'b10001100000000010000000000000000;
        _newinstr = 0;
        #1 _newinstr = 1;
        #10 _newinstr = 0;
        

        #10;
		_instrword = 32'b10001100000000100000000000000001;
        
        _newinstr = 0;
        #1 _newinstr = 1;
        #10 _newinstr = 0;
        
        #10;

         _instrword = 32'b10001100000000110000000000000010;

        
        _newinstr = 0;
        #1 _newinstr = 1;
        #1 _newinstr = 0;
        
        #10;

        _instrword = 32'b00000000001000100010100000100000;

        _newinstr = 0;
        #1 _newinstr = 1;
        #1 _newinstr = 0;
        
        #10;

        _instrword = 32'b00000000101000110010000000100010;

        _newinstr = 0;
        #1 _newinstr = 1;
        #1 _newinstr = 0;
        
        #10;


        

    $finish;
    end            
endmodule