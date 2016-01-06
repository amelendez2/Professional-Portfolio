#include <ColorLED.h>

ColorLED myColorLED(255,255,255,3,5,9);
//-------This program will be used to calculate pulse

//-----INIT------
int pulse_in = A0;        // ADC record analog register
int pulse_value;          // Stores value from ADC
int ledPin3 = 3;          // Select Red pin in
int ledPin5 = 5;          // Select Green pin in
int ledPin9 = 9;          // Select Blue pin in
int threshold = 520;      // Where you set rising edge from digital 0 to 1
int BPM = 0;              // Beats per Minute
int samples;              // Variable to record samples from ADC
int rate = 20;            // Sample Rate
int sample_block[20];     // Array of samples from ADC
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
  if (millis() < 5000)
  {
    Pulse_Range = 1;   
  }
  else if ((millis() > 5000) && (millis() < 7500))
  {
    Pulse_Range = 2;   
  }
  else if ((millis() > 7500) && (millis() < 10000))
  {
    Pulse_Range = 3;   
  }
  else if ((millis() > 10000) && (millis() < 12500))
  {
    Pulse_Range = 4;   
  }
  else if ((millis() > 15000) && (millis() < 17500))
  {
    Pulse_Range = 5;   
  }
  else if ((millis() > 20000) && (millis() < 22500))
  {
    Pulse_Range = 6;   
  }
  else if ((millis() > 25000))
  {
    Pulse_Range = 7;   
  }
  switch (Pulse_Range) {
    case 1:
      myColorLED.ccwhite(ledPin3, ledPin5, ledPin9);
      delay(5000);
      Serial.println("Pulse = 50");
      break;
    case 2:
      myColorLED.ccpink(ledPin3, ledPin5, ledPin9);
      delay(5000);
      Serial.println("Pulse = 60");
      break;
    case 3:
      myColorLED.ccblue(ledPin3, ledPin5, ledPin9);
      delay(5000);
      Serial.println("Pulse = 65");
      break;
    case 4:
      myColorLED.ccgreen(ledPin3, ledPin5, ledPin9);
      delay(5000);
      Serial.println("Pulse = 70");
      break;
    case 5:
      myColorLED.ccred(ledPin3, ledPin5, ledPin9);
      delay(5000);
      Serial.println("Pulse = 75");
      break;
    case 6:
      myColorLED.cccyan(ledPin3, ledPin5, ledPin9);
      delay(5000);
      Serial.println("Pulse = 80");
      break;
    case 7:
      myColorLED.ccpurple(ledPin3, ledPin5, ledPin9);
      delay(5000);
      Serial.println("Pulse > 90");
      break;  
    default: 
      break;
  } 
}
