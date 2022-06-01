#include "Robot.h"

using namespace rev;

class DalekDrive {
    public:
    DalekDrive();
    double squareInput(double v);
    void TankDrive(double l, double r, bool squaredInputs);
    void TankDrive(Joystick& leftStick, Joystick& rightStick, bool squaredInputs);
    void TankDrive(Joystick *leftStick, Joystick *rightStick, bool squaredInputs);

    private:
    enum Motors {leftFront = 0, leftRear, rightFront, rightRear};
    enum Sides {FRONT = 0, REAR};
    CANSparkMax *m_left[];
    CANSparkMax *m_right[];
};