#include <Stepper.h>

const int stepsPerRevolution = 200;
Stepper LSPStepper(stepsPerRevolution, 24, 3); //pin nums
Stepper InstallStepper(stepsPerRevolution, 26, 4);
Stepper ConveyStepper(stepsPerRevolution, 2, 22);
Stepper DeployerStepper(stepsPerRevolution, 34, 8);


//DC Motors
// Motor A connections
int enA = 7;
int in1 = 32;
int in2 = 30;
// Motor B connections
int enB = 5;
int in3 = 6;
int in4 = 28;



int main(){
  init();
  //Setup
  LSPStepper.setSpeed(100); // set the speed in RPMs
  InstallStepper.setSpeed(100); // set the speed in RPMs
  ConveyStepper.setSpeed(100); // set the speed in RPMs

  // Set all the DC motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off DC motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

    move(DeployerStepper, 1000);

  //RUN
//  for(int i=0; i<3; i++){
//    move(ConveyStepper, 1000);
//    delay(1000); 
//    move(InstallStepper, 1000);
//    delay(1000); 
//    move(InstallStepper, -1000);
//    delay(1000);
//    move(LSPStepper, 1000);
//    delay(1000);
//  }

//  installerVertical();

}

void move(Stepper stepper, int numSteps){
  for(int i = 0; i <3; i++){
      stepper.step(numSteps);
  } 
}


void installerVertical(){
  // Set motor to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, 255);

  //Turn on switch which one is high for direction
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(2000); //Change to how long need to screw

  //Turn off
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
}

void installerScrew(){
  // Set motor to maximum speed
  // For PWM maximum possible values are 0 to 255 
  analogWrite(enB, 255);

  //Turn on switch which one is high for direction
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(5000); //Change to how long need to screw

  //Turn off
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
