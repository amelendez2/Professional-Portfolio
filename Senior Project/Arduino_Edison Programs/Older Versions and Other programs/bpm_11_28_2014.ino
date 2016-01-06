#include <ColorLED.h>

ColorLED CL(255,255,255,3,5,9);
//-------This program will be used to calculate pulse

//-----INIT------
int pulse_in = A0;        // ADC record analog register
int pulse_value;          // Stores value from ADC
int ledPin3 = 3;          // Select Red pin in
int ledPin5 = 5;          // Select Blue pin in
int ledPin9 = 9;          // Select Green pin in
int current_state = 0;    // Used to check if on or off
int counter;          // Starts counting between pulses
int time1 = 1;            // Check to start a time difference
int threshold = 1000;       // Where you set rising edge from digital 0 to 1
int BPM = 0;              // Beats per Minute
int val = 0;

//-------SETUP------
void setup() {  
  pinMode (ledPin3, INPUT);
  pinMode (ledPin5, INPUT);
  pinMode (ledPin9, INPUT);
  pinMode (pulse_in, INPUT);
  Serial.begin(9600);
}

//------Main Loop ----------
void loop() {
  pulse_value = analogRead(pulse_in);        // Read the adc and store it
  
  if (pulse_value >= threshold)              // Does the ADC value meet our threshold for a pulse
  {
   CL.cccyan(ledPin3, ledPin5, ledPin9);
   //current_state = 1;
   //Serial.println(pulse_value); 
  
   BPM = (counter/60)*100;
   Serial.println(pulse_value);
//   for(counter=1; ; )
//   {
//     pulse_value = analogRead(pulse_in);
//     //counter=counter+2;
//     if(pulse_value < threshold - 3){
//      // counter=counter+1;
//      break; 
//     }
//     counter=counter+1;
//   }
   //counter++;
   //val++;
   delay(50);
  }
  else if (pulse_value < threshold-3)
  {
   CL.ccred(ledPin3, ledPin5, ledPin9); 
   counter= counter+1;
   //current_state = 0; 
     // delay(50);
    //counter=counter + val; 
    //counter++;
//    if(pulse_value >= threshold)
//    {
//      counter = 1;
//    }
   // BPM = (60*1000)/counter;
    
    //Serial.println(BPM);
   
   Serial.println(pulse_value);
   delay(50);
  }
   
//  if(current_state == time1)                // If pulse detected start counting until next pulse
//  {
//    delay(250);
//    counter = 250;
//    for(pulse_value = analogRead(pulse_in) ; pulse_value < threshold ; )
//    {
//     counter = counter + 1;      // 250 + counter to calculate time different between beats 
//    }
//    BPM = (60*1000)/ counter;    // Calculate Beats per Minute
//  }

//    if(BPM < 70)                  // Yellow
//    {
//      for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) {
//        analogWrite(ledPin9, fadeValue);        
//        delay(30);            
//      }
//      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
//        analogWrite(ledPin9, fadeValue);        
//        delay(30);                            
//      }  
//    }
//    
//    else if((BPM >= 70) | (BPM < 105))        // Green
//    {
//      for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) {
//        analogWrite(ledPin9, fadeValue);        
//        delay(30);            
//      }
//      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
//        analogWrite(ledPin9, fadeValue);        
//        delay(30);                            
//      }  
//    }
//   
//    else if (BPM >= 105)
//    {
//      for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) {
//        analogWrite(ledPin9, fadeValue);        
//        delay(30);            
//      }
//      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
//        analogWrite(ledPin9, fadeValue);        
//        delay(30);                            
//      }  
//    }


}
