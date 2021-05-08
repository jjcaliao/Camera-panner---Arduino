#include <Stepper.h>

const int stepsPerRevolution = 1000;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

const int analogPin = A0;

bool goingRight = true;
bool isOn;
int stepCount = 0;         // number of steps the motor has taken
int steps = 1;
int maxStep = 9550;         //max distance
int dirStep = 1;
void setup() {
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one step:
  float sensorVal = analogRead(analogPin);
  if(sensorVal > 1023/2){
    myStepper.step(dirStep);
    Serial.print("steps:");
    Serial.println(stepCount);
    stepCount += steps;

    if( stepCount > maxStep){
      steps *= -1;
      dirStep *= -1;
      goingRight = false;
    }
  
    if( stepCount < 0){
      steps *= -1;
      dirStep *= -1;
      goingRight = true;
    }
   
    delayMicroseconds(50);
  }
}
