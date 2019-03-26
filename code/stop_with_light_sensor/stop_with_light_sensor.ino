int analogPin = A2; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int val = 0;  // variable to store the value read

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Starting...\n");
 
  pinMode(analogPin, INPUT);
  //Setup for wheel 1
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup for wheel 2
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin

}



void loop() {
  // put your main code here, to run repeatedly:
    val = analogRead(analogPin);  // read the input pin
    Serial.println(val);          // debug value

  if(val > 100) {
    //RIGHT Wheel
    digitalWrite(12, HIGH); //Establishes forward direction
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 0);   //Spins the motor on Channel A at full speed


    //LEFT Wheel
    digitalWrite(13, LOW);  //Establishes forward direction 
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    analogWrite(11, 0);   //Spins the motor on Channel B at half speed

    Serial.print("I am stopping!");

    
  } else if (val < 100) {
    
    //RIGHT Wheel
    digitalWrite(12, HIGH); //Establishes forward direction
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 200);   //Spins the motor on Channel A at full speed


    //LEFT Wheel
    digitalWrite(13, LOW);  //Establishes forward direction 
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    analogWrite(11, 200);   //Spins the motor on Channel B at half speed

    
    Serial.print("I am going!");

  }
}
