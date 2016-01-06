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
int threshold = 430;       // Where you set rising edge from digital 0 to 1
int BPM = 0;              // Beats per Minute
int val = 0;
int i;
int samples;
int rate = 50;
int sample_block[50];
int Average_sample;
int Sum_of_samples;
unsigned long times[10000];
unsigned long t1;
unsigned long t2;
unsigned long delta;

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
  delay(1);
  
  if(pulse_value >= threshold)
  {
    for(samples=0; samples < rate; samples++)
   {
      sample_block[samples] = pulse_value;
      Sum_of_samples += sample_block[samples]; 
      pulse_value = analogRead(pulse_in);
      delay(1);
   }
  
     Average_sample = Sum_of_samples/rate;
     
     
     if(Average_sample > 412){
     t2=millis();
     delta = t2-t1;
     //Serial.println(Average_sample);
     Serial.println(millis());
     Serial.println(delta);
     t1=millis();
     }
     Average_sample = 0;
     Sum_of_samples = 0;
     
  }
  
}


