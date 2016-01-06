#include <ColorLED.h>

ColorLED myColorLED(255,255,255,3,5,9);
//-------This program will be used to calculate pulse

//-----INIT------
int pulse_in = A0;        // ADC record analog register
int pulse_value;          // Stores value from ADC
int ledPin3 = 3;          // Select Red pin in
int ledPin5 = 5;          // Select Green pin in
int ledPin9 = 9;          // Select Blue pin in
int threshold = 430;      // Where you set rising edge from digital 0 to 1
int BPM = 0;              // Beats per Minute
int samples;              // Variable to record samples from ADC
int rate = 50;            // Sample Rate
int sample_block[50];     // Array of samples from ADC
int Average_sample;       // Average Value for sample block
int Sum_of_samples;       // Add all samples then divide by the rate
int Pulse_Range;          // Determines the pulse range the user is in
int Pulse;                // Pulse of user
unsigned long t1;         // time of initial beat 
unsigned long t2;         // time of second beat 
unsigned long delta;      // time between beats

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
    ADC_Sample();    
    if(Average_sample > 413)
    {
       Pulse = Beats_Per_Minute(Delta_T());
       Serial.println(Pulse);
       Pulse_Range = Range_Calc(Pulse);
    }
      
    Average_sample = 0;
    Sum_of_samples = 0;
    //---------- Switch Case for Pulse_Range ----------
    switch (Pulse_Range) {
    case 1:
      myColorLED.ccwhite(ledPin3, ledPin5, ledPin9);
      break;
    case 2:
      myColorLED.ccpink(ledPin3, ledPin5, ledPin9);
      break;
    case 3:
      myColorLED.ccblue(ledPin3, ledPin5, ledPin9);
      break;
    case 4:
      myColorLED.ccgreen(ledPin3, ledPin5, ledPin9);
      break;
    case 5:
      myColorLED.ccred(ledPin3, ledPin5, ledPin9);
      break;
    case 6:
      myColorLED.cccyan(ledPin3, ledPin5, ledPin9);
      break;
    case 7:
      myColorLED.ccpurple(ledPin3, ledPin5, ledPin9);
      break;  
    default: 
      break;
  } 
     
  }
  
}

//---------- Method that samples 50 values then returns Average ----------
int ADC_Sample()
{
  for(samples=0; samples < rate; samples++)
  {
      sample_block[samples] = pulse_value;
      Sum_of_samples += sample_block[samples]; 
      pulse_value = analogRead(pulse_in);
      delay(1);
  }
  Average_sample = Sum_of_samples/rate;
  return Average_sample;
}

//----------- Method that Calculates BPM depending on time between spikes ------
int Beats_Per_Minute(int delta_time)
{
  BPM = (60*1000)/delta_time;
  return BPM;
}

//------------ Method that calculates the delta between pulses ------------
int Delta_T()
{
  t2=millis();                      // millis gives us current program time
  delta = t2-t1;
  //Serial.println(Average_sample);
  //Serial.println(millis());
  //Serial.println(delta);
  t1=millis();
  if ((delta > 375) && (delta < 1200))
  {
    return delta;
  }
  else
  {
    return 850;
  }  
}

//----------- Method that determines the BPM Range ------------------
int Range_Calc(int pulse)
{
 if ((pulse >= 50) && (pulse < 60))
 {
  return 1; 
 }
 else if ((pulse >= 60) && (pulse < 65))
 {
  return 2; 
 }
 else if ((pulse >= 65) && (pulse < 70))
 {
  return 3; 
 } 
 else if ((pulse >= 70) && (pulse < 75))
 {
  return 4; 
 }
 else if ((pulse >= 75) && (pulse < 80))
 {
  return 5; 
 }
 else if ((pulse >= 80) && (pulse < 90))
 {
  return 6; 
 }
 else
 {
  return 7; 
 }
}
