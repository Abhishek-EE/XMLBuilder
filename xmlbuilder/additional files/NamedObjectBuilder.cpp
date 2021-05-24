#include "TcPch.h"
#pragma hdrstop
#include"NamedObjectBuilder.h"
#include"tinyxml2.h"
#include <string>

MotorBuilder* MotorBuilder::m_motorBuilderInstance = new MotorBuilder;//Creating an Instance of type MotorBuilder on the heap.

MotorBuilder* MotorBuilder::GetMotorBuilderInstance()
{
	return m_motorBuilderInstance;
}

MotorBuilder::MotorBuilder()
{
	/*
	MotorBuilder Constructor is private and is only called ones when the static MotorBuilderInstance is instantiated
	*/
	this->SetObjectType();//Setting the Object Type when the constructor is called
	XMLBuilder::GetXMLBuilderInstance().AddBuilder(this->m_objectType, this);//Registering the Motor Builder in the BuilderMap of XMLBuilder																									
}
void MotorBuilder::BuildObject(tinyxml2::XMLElement* root)
{
	/*
	BuildObject Method is used to Build the Obejct of type Motor , it takes a node of XML Tree and sets all the 
	attributes by iterating over all the XMLNodes.
	*/
	Motor* Object = new Motor();
	tinyxml2::XMLElement* XMLelement = root->FirstChildElement();
	const char * Attribute1("Name");
	const char * Attribute2("MaxSpeed");
	const char * Attribute3("MaxCurrent");

	while (XMLelement != NULL)
	{
		const char * value(XMLelement->Value());
		const char * data(XMLelement->GetText());
		if (strcmp(value, Attribute1) == 0)
		{
			Object->SetName(data);
		}
		else if (strcmp(value, Attribute2) == 0)
			Object->SetMaxSpeed(atof(data));
		else if (strcmp(value, Attribute3) == 0)
			Object->SetMaxCurrent(atof(data));

		XMLelement = XMLelement->NextSiblingElement();
	}
	// Setting Object Map with the Object
	m_objectMap[Object->GetName()] = Object;
}


NamedObject* MotorBuilder::GetObject(const char * name)
{
	/*
	Get an Object based on the uniquename of the object
	*/
	if (m_objectMap.count(name))
		return m_objectMap.at(name);
	else
		return nullptr;
}

Motor* MotorBuilder::GetMotor(const char* name)
{
	/*
	Get the Motor based on the uniquename of the object
	*/
	if (m_objectMap.count(name))
		return m_objectMap.at(name);
	else
		return nullptr;
}
