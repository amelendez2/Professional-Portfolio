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
int threshold = 460;       // Where you set rising edge from digital 0 to 1
int BPM = 0;              // Beats per Minute
int val = 0;
int i;
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
    t1=millis();
    PHigh();
    delta = t2 - t1;
    Serial.print("Delta = ");
    Serial.println(delta);
  }
  
}

void PHigh()
{
  pulse_value = analogRead(pulse_in);        // Read the adc and store it
  delay(1);
  
  if(pulse_value >= threshold)
  {
    t2=millis();
    PHigh();
  }
  else if(pulse_value < threshold-10)
  {
    return;
  }
  
}
