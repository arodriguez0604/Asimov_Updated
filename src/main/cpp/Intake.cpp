#include "Robot.h"

Intake::Intake(frc::XboxController *xbox)
{
    init(xbox);
}

void
Intake::init(frc::XboxController *xbox)
{
    m_xbox = xbox;
    m_intake = new WPI_TalonSRX(INTAKE);
    if(m_intake == NULL)
        std::bad_alloc();
}

void
Intake::Tick() {
    if (m_xbox->GetYButton()) {
        m_intake->Set(-0.9);
    }
    else if (m_xbox->GetXButton()) {
        m_intake->Set(1.0);
    }
    else {
        m_intake->Set(0.0);
    }
}