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