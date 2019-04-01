// center of object = (x,y)
// x = 0 - 319 --> 159 center
// y = 0 - 199

// signature 5 = orange
// signature 3 = green

int x_left_threshold = 149;
int x_right_threshold = 169;
static int i = 0;
int j, k;
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
    k = 0;
   } else if (check_approach_goal()) {
    if (k < 10) {
      approach(j);
      k++;
    } else {
      approach_goal(j);
    }
   } else {
    k = 0;
    stopDrive();
   }
   

}

bool check_approach() {
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
        if (pixy.blocks[j].signature == 5 || 
        pixy.blocks[j].signature == 3) 
        // 3 = green, 4 = yellow, 5 = ornge
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

bool check_approach_goal() {
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
        if (pixy.blocks[j].signature == 4 && pixy.blocks[j].height > 20 && pixy.blocks[j].height < 100) 
        // 4 = yellow
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


void approach_goal(int j) {
  
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

  front_drive();
}


void front_drive() {
    digitalWrite(12, HIGH); //Establishes forward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 75);   //Spins the motor on Channel A at full speed
    
    digitalWrite(13, LOW);  //Establishes backward direction of Channel B
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    analogWrite(11, 75);    //Spins the motor on Channel B at half speed
}

void stopDrive() {
    digitalWrite(12, HIGH); //Establishes forward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 0);   //Spins the motor on Channel A at full speed
    
    digitalWrite(13, LOW);  //Establishes backward direction of Channel B
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    analogWrite(11, 0);    //Spins the motor on Channel B at half speed
}
  
