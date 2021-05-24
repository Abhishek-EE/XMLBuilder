#pragma once
#ifndef NAMEDOBJECTBUILDER_H
#define NAMEDOBJECTBUILDER_H
#include"NamedObject.h"
#include "Motor.h"
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


class MotorBuilder : public NamedObjectBuilder
{
	/*
	A class to build the objects of type Motor.
	*/
public:

	static MotorBuilder* GetMotorBuilderInstance();
	void BuildObject(tinyxml2::XMLElement* root) override;
	NamedObject* GetObject(const char * name) override;
	Motor* GetMotor(const char * name);
	void SetObjectType() override { m_objectType = "Motor"; }
	
private:
	static MotorBuilder* m_motorBuilderInstance;
	std::map<const char *, Motor*,cmp_str> m_objectMap;//A map to store the Pointers to the Objects of type Motor
	MotorBuilder();
};   

#endif /* NAMEDOBJECTBUILDER_H */