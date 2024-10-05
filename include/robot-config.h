using namespace vex;

extern brain Brain;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void){
    // Create a brain object
    brain Brain;

    // Create motor objects for the drivetrain
    motor leftMotor1 = motor(PORT1, gearSetting::ratio18_1, false);
    motor leftMotor2 = motor(PORT2, gearSetting::ratio18_1, false);
    motor rightMotor1 = motor(PORT9, gearSetting::ratio18_1, true);
    motor rightMotor2 = motor(PORT10, gearSetting::ratio18_1, true);

    // Create motor objects for the intake
    motor intakeMotor1 = motor(PORT5, gearSetting::ratio18_1, false);
    motor intakeMotor2 = motor(PORT6, gearSetting::ratio18_1, false);

    // Create pneumatic objects for the pistons
    pneumatic piston1 = pneumatic(Brain.ThreeWirePort.A);
    pneumatic piston2 = pneumatic(Brain.ThreeWirePort.B);

    void groupPistons(pneumatic piston& piston1, pneumatic piston& piston2, bool state) {
        piston1.set(state);
        piston2.set(state);
    }

    // Create a controller object
    controller Controller1 = controller();
    //controller Controller2 = controller();
}
