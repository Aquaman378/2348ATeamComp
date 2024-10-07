#include "robot/drivetrain.h"

#include "globals.h"

using namespace Robot;
using namespace Robot::Globals;

Drivetrain::DRIVE_MODE Drivetrain::driveMode = CURVATURE_DRIVE;

Drivetrain::Drivetrain()
{
	Drivetrain::driveMode = CURVATURE_DRIVE;
}

void Drivetrain::CurvatureDrive()
{
	int left  = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int right = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

	chassis.curvature(left, right);

	pros::delay(15);
}

void Drivetrain::ArcadeDrive()
{
	// Arcade Measurements
	int left  = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int right = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

	chassis.arcade(left, right, false, 0.6);

	pros::delay(15);
}

void Drivetrain::TankDrive()
{
	int left  = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int right = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

	chassis.tank(left, right);

	pros::delay(15);
}


// Run the drivetrain depending on the control mode
void Drivetrain::run()
{
	switch (Drivetrain::driveMode) {
	case CURVATURE_DRIVE:
		Drivetrain::CurvatureDrive();
		break;
	case ARCADE_DRIVE:
		Drivetrain::ArcadeDrive();
		break;
	case TANK_DRIVE:
		Drivetrain::TankDrive();
		break;
	}
}

// Cycle through each drivetrain control mode, overflows back to 0
std::string Drivetrain::toggleDrive()
{
	int driveMode = (Drivetrain::driveMode + 1) % (TANK_DRIVE + 1);
	return SwitchDrive(driveMode);
}
