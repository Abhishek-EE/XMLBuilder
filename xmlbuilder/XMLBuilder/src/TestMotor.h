
#ifndef MOTOR_H_XMLBuilder
#define MOTOR_H_XMLBuilder
#include "NamedObject.h"
#include <string>

class TestMotor : public NamedObject
{
public:

	float GetMaxSpeed() const { return m_maxSpeed; }
	float GetMaxCurrent() const { return m_maxCurrent; }
	void SetMaxSpeed(float speed) { m_maxSpeed = speed; }
	void SetMaxCurrent(float current) { m_maxCurrent = current; }
	const char* GetName() const { return m_name; }
	void SetName(const char * name) { std::strcpy(m_name, name); }
	void start() const;
	void stop() const;
	//Constructors
	TestMotor(const char* uniquename, float speed, float current);
	TestMotor() = default;

private:
	//Private Attributes
	char m_name[80];
	float m_maxSpeed = 100;
	float m_maxCurrent = 200;
};


#endif /* MOTOR_H_XMLBUILDER */