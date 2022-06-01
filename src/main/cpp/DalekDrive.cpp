#include "DalekDrive.h"

using namespace rev;

DalekDrive::DalekDrive() {
	m_left[FRONT]  = new CANSparkMax(leftFront, CANSparkMax::MotorType::kBrushless);
	m_left[REAR]   = new CANSparkMax(leftRear, CANSparkMax::MotorType::kBrushless);
	m_right[FRONT] = new CANSparkMax(rightFront, CANSparkMax::MotorType::kBrushless);
	m_right[REAR]  = new CANSparkMax(rightRear, CANSparkMax::MotorType::kBrushless);
}

double
DalekDrive::squareInput(double v)
{
	if (v < 0.0) {
		return -(v * v);
	}
	return (v * v);
}

void
DalekDrive::TankDrive(double l, double r, bool squaredInputs)
{
	if(squaredInputs) {
		l = squareInput(l);
		r = squareInput(r);
	}
	m_left[FRONT]->Set(l);
	m_left[REAR]->Set(l);
	m_right[FRONT]->Set(r * -1.0);
	m_right[REAR]->Set(r * -1.0);
}

void
DalekDrive::TankDrive(Joystick* leftStick, Joystick* rightStick, bool squaredInputs)
{
	TankDrive(leftStick->GetY(), rightStick->GetY(), squaredInputs);
}

void
DalekDrive::TankDrive(Joystick& leftStick, Joystick& rightStick, bool squaredInputs)
{
	TankDrive(leftStick.GetY(), rightStick.GetY(), squaredInputs);
}