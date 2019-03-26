// center of object = (x,y)
// x = 0 - 319 --> 159 center
// y = 0 - 199

// signature 5 = orange
// signature 3 = green

int x_left_threshold = 149;
int x_right_threshold = 169;
static int i = 0;
int j;
uint16_t blocks;
char buf[32]; 


#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <SPI.h>  
#include <Pixy.h>

// This is the main Pixy object 
Pixy pixy;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Starting...\n");

  //Setup for RIGHT wheel 
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup for LEFT wheel 
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
  
  //Setup for getting infor from Pixycam
  pixy.init();

}

void loop()
{ 
  blocks = pixy.getBlocks();
  
  if (check_approach()) {
    approach(j);
   }
   

}

bool check_approach() {
             Serial.print("hello");
  // the following if statement block of code is from the "helloworld" file from the Examples of the Pixy library 
 if (blocks)
    {

    i++;    
    // do this (print) every 50 frames because printing every
    // frame would bog down the Arduino
    if (i%50==0)
    {
      sprintf(buf, "Detected %d:\n", blocks); // print objects it sees
      Serial.print(buf);
      for (j=0; j<blocks; j++)
      {
        if (pixy.blocks[j].signature == 5 || pixy.blocks[j].signature == 3)
        {
        sprintf(buf, "  block %d: ", j); // print specifically orange objects
        Serial.print(buf); 
        pixy.blocks[j].print();

        return true;
     } else {
      return false;
     }
    }
   }
  }
}


void approach(int j) {
  
  if (pixy.blocks[j].x > x_right_threshold) {
    digitalWrite(12, LOW);  //Establishes forward direction
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 150);   
    
    digitalWrite(13, LOW);  //Establishes backward direction 
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    analogWrite(11, 150);    
    
    } else if (pixy.blocks[j].x < x_left_threshold) {
      digitalWrite(12, HIGH); //Establishes backward direction
      digitalWrite(9, LOW);   //Disengage the Brake for Channel A
      analogWrite(3, 150);   
    
     digitalWrite(13, HIGH);  //Establishes forward direction 
     digitalWrite(8, LOW);   //Disengage the Brake for Channel B
     analogWrite(11, 150);     
  }

}
