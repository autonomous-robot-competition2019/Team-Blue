const int IRR = 24;
const int IRL = 26;
int valR, valL;
bool backwards = false;
uint16_t r, g, b, c, colorTemp, lux;
boolean lockout = false;


#include <Wire.h>
#include "Adafruit_TCS34725.h"

/* Example code for the Adafruit TCS34725 breakout library */

/* Connect SCL    to analog 5
   Connect SDA    to analog 4
   Connect VDD    to 3.3V DC
   Connect GROUND to common ground */

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_1X);



void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  Serial.print("Starting...\n");
 
  //Setup for wheel 1
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup for wheel 2
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin

  front_drive();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (color()) {
    keeping();
  }
}



// If we hit a yellow border, back-up and turn around to stay IN BOUNDS
bool color() {
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
 
  Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
  Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");

  return r > 20 && g > 20;
  }

//
void keeping() {
   
    temp_bckwrds(); // backs up
    delay(500);

    turn_around(LOW, LOW); // spins 180 degrees
    delay(900); // (good at 900 usually)

    front_drive(); // drives forward until end of middle goal
    delay(3250);
   
    temp_bckwrds(); // backs up
    delay(500);

    turn_around(HIGH, HIGH); // spins 180 degrees
    delay(900); // (good at 900 usually)

    front_drive(); // drives forward until end of middle goal
    delay(3250);

    analogWrite(3, 0);
    analogWrite(11,0);
}


// Turns around CLOCKWISE
void turn_around(int right, int left) {
    digitalWrite(12, right); //Establishes backward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 250);   //Spins the motor on Channel A at full speed

    //Motor B backward @ half speed
    digitalWrite(13, left);  //Establishes forward direction of Channel B
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    analogWrite(11, 250);    //Spins the motor on Channel B at half speed
}

void temp_bckwrds() {

    digitalWrite(12, LOW); //Establishes forward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 150);   //Spins the motor on Channel A at full speed
    
    digitalWrite(13, HIGH);  //Establishes backward direction of Channel B
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    analogWrite(11, 150);    //Spins the motor on Channel B at half speed 
}

void front_drive() {
    digitalWrite(12, HIGH); //Establishes forward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 100);   //Spins the motor on Channel A at full speed
    
    digitalWrite(13, LOW);  //Establishes backward direction of Channel B
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    analogWrite(11, 100);    //Spins the motor on Channel B at half speed
}
  
