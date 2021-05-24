
#ifndef MOTOR_H_something
#define MOTOR_H_something
#include "NamedObject.h"
#include <string>

class Motor : public NamedObject
{
public:

	float GetMaxSpeed() const { return m_maxSpeed; }
	float GetMaxCurrent() const { return m_maxCurrent; }
	void SetMaxSpeed(float speed) { m_maxSpeed = speed; }
	void SetMaxCurrent(float current) { m_maxCurrent = current; }
	const char* GetName() const { return m_name; }
	void SetName(const char * name) { strcpy(m_name, name); }
	void start() const;
	void stop() const;
	//Constructors
	Motor(const char* uniquename, float speed, float current);
	Motor() = default;

private:
	//Private Attributes
	char m_name[80];
	float m_maxSpeed = 100;
	float m_maxCurrent = 200;
};


#endif /* MOTOR_H */