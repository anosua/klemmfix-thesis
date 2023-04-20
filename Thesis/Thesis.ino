// Leitboy Deployer wire colours (from power source to end)
// blue, yellow, green, white
#include <Stepper.h>

#define LSP_TO_MOTOR 2090
#define LSP_TO_END -2090
#define INSTALL 1200
#define REVERSE_INSTALLER -1400
#define DEPLOY 1000
#define CONVEY -2500 

const int stepsPerRevolution = 200;

//
Stepper ConveyStepper(stepsPerRevolution, 24, 3); //pin nums 
Stepper LSPStepper(stepsPerRevolution, 26, 4);
Stepper InstallStepper(stepsPerRevolution, 22, 2);
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
  InstallStepper.setSpeed(50); // set the speed in RPMs
  ConveyStepper.setSpeed(100); // set the speed in RPMs
  DeployerStepper.setSpeed(20); // set the speed in RPMs


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
  
    //move(DeployerStepper, 1000);

//  //RUN
  for(int i=0; i<1000; i++){
    delay(3000);
    installerVerticalDown();
////    move(ConveyStepper, CONVEY);
    delay(20000); // 10 seconds
    doScrew();
    delay(10000); // 10 seconds
    move(InstallStepper, INSTALL);
   delay(1000); // 1 second
    move(InstallStepper, REVERSE_INSTALLER);
////    delay(1000);
//    move(LSPStepper, LSP_TO_MOTOR);
    delay(10000);
    
//    move(DeployerStepper, DEPLOY);
//    delay(1000);
////
  //doScrew();
////
    //move(ConveyStepper, CONVEY);
////
   }

    // RESET TO INITAL POSITIONS
//    move(LSPStepper, LSP_TO_MOTOR);

//  for(int i=0; i<10000; i++){

/* THIS IS CORRECT FOR ERIN */
    // more klemmfix to the linear rail
//      move(LSPStepper, 1000);
//      move(InstallStepper, 950);
//        move(ConveyStepper, CONVEY);


//      move(DeployerStepper, -1000);
//        move(InstallStepper, -3000);

//        move(DeployerStepper, 1000);


      
//      delay(1000);
//
//      move(InstallStepper, -950);
//
//      //doScrew();
//      
//    }

    // RESET TO INITAL POSITIONS
    //move(LSPStepper, LSP_TO_MOTOR);

}

void doScrew() {
    //installerVerticalDown();

    delay(5000);
    
    installerScrewDown();

    delay(5000);

    installerVerticalUp();
    
    installerScrewUp();

    delay(5000);
}

void move(Stepper stepper, int numSteps){
  for(int i = 0; i <3; i++){
      stepper.step(numSteps);
  } 
}


void installerVerticalDown(){
  // Set motor to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, 255);

  //Turn on switch which one is high for direction
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(400); //Change to how long need to screw

  //Turn off
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
}

void installerVerticalUp(){
  // Set motor to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, 255);

  //Turn on switch which one is high for direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(600); //Change to how long need to screw

  //Turn off
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
}

void installerScrewUp(){
  // Set motor to maximum speed
  // For PWM maximum possible values are 0 to 255 
  analogWrite(enB, 255);

  //Turn on switch which one is high for direction
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(55000); //Change to how long need to screw

  //Turn off
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void installerScrewDown(){
  // Set motor to maximum speed
  // For PWM maximum possible values are 0 to 255 
  analogWrite(enB, 255);

  //Turn on switch which one is high for direction
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(60000); //Change to how long need to screw

  //Turn off
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
