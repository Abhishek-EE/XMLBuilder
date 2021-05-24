
#include<iostream>
#include"tinyxml2.h"
#include <fstream>
#include <string>
#include<cstring>
#include"XMLBuilder.h"


using namespace tinyxml2;

int main()
{
	std::cout << "Hello World!";
	std::string file = "";
	std::string line;
	std::string name = "TestMotor.xml";
	std::ifstream myfile(name);
	if (myfile.is_open())
	{
		while (std::getline(myfile, line))
		{
			file = file + line;
			std::cout << line;
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";

	const char * arr = file.c_str();

	XMLBuilder& xmlbuilder = XMLBuilder::GetXMLBuilderInstance();
	xmlbuilder.Initialize();
	xmlbuilder.Build(arr);
	NamedObject* motor1 = TestMotorBuilder::GetTestMotorBuilderInstance()->GetObject("UniqueMotor");
	TestMotor* TestMotor1 = TestMotorBuilder::GetTestMotorBuilderInstance()->GetTestMotor("UniqueMotor");
	TestMotor1->start();
	
}