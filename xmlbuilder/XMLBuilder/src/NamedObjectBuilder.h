
#ifndef NAMEDOBJECTBUILDER_H_XMLBUILDER
#define NAMEDOBJECTBUILDER_H_XMLBUILDER
#include"NamedObject.h"
#include "TestMotor.h"
#include <map>
#include"XMLBuilder.h"
#include "tinyxml2.h"
#include "StringCompare.h"

class NamedObjectBuilder 
{
	/*
	A base class for all the different types of named object builders.
	*/
public:

	virtual void BuildObject(tinyxml2::XMLElement* root) = 0;
	virtual NamedObject* GetObject(const char * name) = 0;
	virtual void SetObjectType() = 0;

protected:
	const char * m_objectType;
};


class TestMotorBuilder : public NamedObjectBuilder
{
	/*
	A class to build the objects of type TestMotor.
	*/
public:

	static TestMotorBuilder* GetTestMotorBuilderInstance();
	void BuildObject(tinyxml2::XMLElement* root) override;
	NamedObject* GetObject(const char * name) override;
	TestMotor* GetTestMotor(const char * name);
	void SetObjectType() override { m_objectType = "TestMotor"; }
	
private:
	std::map<const char *, TestMotor*,cmp_str> m_objectMap;//A map to store the Pointers to the Objects of type TestMotor
	TestMotorBuilder();
};   

#endif /* NAMEDOBJECTBUILDER_H_XMLBUILDER */