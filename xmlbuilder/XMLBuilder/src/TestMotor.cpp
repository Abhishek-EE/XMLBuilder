#include"TestMotor.h"

void TestMotor::start() const
{
	//This method is included just for testing
	std::cout << "TestMotor Started" << "\n";
}

void TestMotor::stop() const
{
	//This Method is included just for testing 
}

TestMotor::TestMotor(const char* uniquename, float speed, float current)
{
	std::strcpy(m_name, uniquename);
	m_maxSpeed = speed;
	m_maxCurrent = current;
}

