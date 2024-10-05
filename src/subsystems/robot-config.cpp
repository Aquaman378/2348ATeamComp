#include "vex.h"

using namespace vex;


void drive(double speed) {
    leftMotor1.spin(forward, speed, velocityUnits::pct);
    leftMotor2.spin(forward, speed, velocityUnits::pct);
    rightMotor1.spin(forward, speed, velocityUnits::pct);
    rightMotor2.spin(forward, speed, velocityUnits::pct);
}

void intake(double speed) {
    intakeMotor1.spin(forward, speed, velocityUnits::pct);
    intakeMotor2.spin(forward, speed, velocityUnits::pct);
}

int main() {
    // Initializing Robot Configuration
    vexcodeInit();

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

        wait(20, msec); // Small delay to prevent CPU overload
    }
}