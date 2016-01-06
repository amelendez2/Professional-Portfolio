#include <ColorLED.h>

ColorLED myColorLED(255,255,255,3,5,9);
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
   myColorLED.cccyan(ledPin3, ledPin5, ledPin9);  
   Serial.println(pulse_value);
   delay(50);
  }
  else if (pulse_value < threshold-3)
  {
   myColorLED.ccred(ledPin3, ledPin5, ledPin9); 
   Serial.println(pulse_value);
   delay(50);
  }



}
