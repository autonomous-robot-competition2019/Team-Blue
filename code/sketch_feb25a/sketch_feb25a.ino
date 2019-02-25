int IRR = 24;
int IRL = 26;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Starting...\n");
  pinMode(IRR, INPUT);
  pinMode(IRL, INPUT);

  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
}

void loop() {
  // put your main code here, to run repeatedly:
  int valR = digitalRead(IRR);
  int valL = digitalRead(IRL);
  /*if (valR == 1 && valL == 1) {
    digitalWrite(12, LOW); //Establishes forward direction of Channel A
    digitalWrite(9, HIGH);   //Disengage the Brake for Channel A
    analogWrite(3, 0);   //Spins the motor on Channel A at full speed
  
    //Motor B backward @ half speed
    digitalWrite(13, HIGH);  //Establishes backward direction of Channel B
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    analogWrite(11, 225);    //Spins the motor on Channel B at half speed
  } else*/ if(valR == 1) {
    digitalWrite(12, LOW); //Establishes forward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 255);   //Spins the motor on Channel A at full speed

    //Motor B backward @ half speed
    digitalWrite(13, LOW);  //Establishes backward direction of Channel B
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    analogWrite(11, 225);    //Spins the motor on Channel B at half speed
  } else if(valL == 1) {
    digitalWrite(12, HIGH); //Establishes forward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 225);   //Spins the motor on Channel A at full speed
  
    //Motor B backward @ half speed
    digitalWrite(13, HIGH);  //Establishes backward direction of Channel B
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    analogWrite(11, 255);    //Spins the motor on Channel B at half speed
  } else {
    digitalWrite(12, HIGH); //Establishes forward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 255);   //Spins the motor on Channel A at full speed
    
    digitalWrite(13, LOW);  //Establishes backward direction of Channel B
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    analogWrite(11, 225);    //Spins the motor on Channel B at half speed
  }
}
