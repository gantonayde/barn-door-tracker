//#include <Time.h>
//#include <TimeLib.h>

#include <AccelStepper.h>
#define HALFSTEP 8


// Motor pin definitions
#define motorPin1  1     // IN1 on the ULN2003 driver 1
#define motorPin2  2     // IN2 on the ULN2003 driver 1
#define motorPin3  3     // IN3 on the ULN2003 driver 1
#define motorPin4  4     // IN4 on the ULN2003 driver 1


//#define TIME_MSG_LEN 11 // time sync to PC is HEADER followed by Unix time_t as ten ASCII digits
//#define TIME_HEADER 'T' // Header tag for serial time sync message
//#define TIME_REQUEST 7 // ASCII bell character requests a time sync message 


// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {
  // Бяло колело на шпилката (42 зъба)
// koeficient za namalqne spored snimkite : Vnew = 0.9434 x 71.32
// V = 71.32 steps/sec , S = 4279.56 steps for 1 rotation - white (final) gear
  OSCCAL += -2; // corrects the attiny85 default freq
 // stepper1.setMaxSpeed(67.2833); //corrected speed бяло колело
  //stepper1.setMaxSpeed(71.32);
 // stepper1.setAcceleration(71.32);
 // stepper1.setSpeed(67.2833); //corrected speed бяло колело
 // stepper1.moveTo(4279.56);  // stupki za 1 oborot na bqloto kolelo

 //Червено колело на шпилката:
 // 3056.8296 стъпки за един оборот, скорост 50.94716 стъпки/мин (това ще избързвам подобно на бялото)
 // Необходима скорост = 0.9434 х 50.94716 = 48.06355
 stepper1.setMaxSpeed(48.06355); 
 stepper1.setSpeed(48.06355);

}//--(end setup )---


void loop() {
  stepper1.runSpeed();
}
