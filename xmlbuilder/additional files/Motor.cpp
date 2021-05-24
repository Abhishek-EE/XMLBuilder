#include"Motor.h"

void Motor::start() const
{
	//This is also just there;
}

void Motor::stop() const
{
	//THis is just there;
}

Motor::Motor(const char* uniquename, float speed, float current)
{
	strcpy(m_name, uniquename);
	m_maxSpeed = speed;
	m_maxCurrent = current;
}

