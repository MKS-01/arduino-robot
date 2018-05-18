



#include <AFMotor.h> //import your motor shield library
#define trigPin A5 // define the pins of your sensor
#define echoPin A4
AF_DCMotor motor1(1,MOTOR12_64KHZ); // set up motors.
AF_DCMotor motor2(2, MOTOR12_64KHZ);

 int sensorPin = A0; //input pin for ldr
const int LED = 13;
int ldrValue; //variable to store the value coming from the ldr


 
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600); // begin serial communitication  
  Serial.println("Motor test!");
   pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
  motor1.setSpeed(150); //set the speed of the motors, between 0-255
motor2.setSpeed (150);  
}
 
void loop() {
  ldr(0);
   long duration, distance; // start the scan
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
  if (distance < 25)/*if there's an obstacle 25 centimers, ahead, do the following: */ {   
   Serial.println ("Close Obstacle detected!" );
Serial.println ("Obstacle Details:");
Serial.print ("Distance From Robot is " );
Serial.print ( distance);
Serial.print ( " CM!");// print out the distance in centimeters.

Serial.println (" The obstacle is declared a threat due to close distance. ");
Serial.println (" Turning !");
    motor1.run(FORWARD);  // Turn as long as there's an obstacle ahead.
    motor2.run (BACKWARD);

}
  else {
   Serial.println ("No obstacle detected. going forward");
   delay (15);
   motor1.run(FORWARD); //if there's no obstacle ahead, Go Forward! 
    motor2.run(FORWARD);  
  }  
  
  

  
  
  
 
}



void ldr(int ldrValue){
  ldrValue = analogRead(sensorPin);
  
  Serial.println(ldrValue);

  if(ldrValue < 100){
    Serial.println("LED light on");
    digitalWrite(LED, HIGH);
    delay(1000);
  }
  else{
    digitalWrite(LED, LOW);
    delay(ldrValue);
  }
} 
