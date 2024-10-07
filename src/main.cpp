/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  robotConfig();
  screen();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void DrivetrainMov() {
    if (Controller1.Axis3.position(pct) != 0) {
      LeftA.spin(forward, Controller1.Axis3.position(pct), pct);
      LeftB.spin(forward, Controller1.Axis3.position(pct), pct);
    } else {
      LeftA.stop();
      LeftB.stop();
    }
    if (Controller1.Axis2.position(pct) != 0) {
      RightA.spin(reverse, Controller1.Axis2.position(pct), pct);
      RightB.spin(reverse, Controller1.Axis2.position(pct), pct);
    } else {
      RightA.stop();
      RightB.stop();
    }
}



void usercontrol(void) {
  // User control code here, inside the loop
  while (true) {
    // Drive control
    double forwardSpeed = Controller1.Axis3.position(percent);
    double turnSpeed = Controller1.Axis1.position(percent);
    drive(forwardSpeed + turnSpeed);
    drive(forwardSpeed - turnSpeed);

    // Intake control
    if (Controller.ButtonR1.pressing()) {
        intake(100); // Run intake motors at full speed
    } else if (Controller.ButtonR2.pressing()) {
        intake(-100); // Reverse intake motors
    } else {
        intake(0); // Stop intake motors
    }

    // Piston control
    if (Controller.ButtonA.pressing()) {
      groupPistons(piston1, piston2, true); // Extend pistons
    } else {
      groupPistons(piston1, piston2, false); // Retract pistons
    }
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
