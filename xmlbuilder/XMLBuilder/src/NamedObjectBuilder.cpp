#include"NamedObjectBuilder.h"
#include"tinyxml2.h"
#include <string>

//TestMotorBuilder* TestMotorBuilder::m_motorBuilderInstance = new TestMotorBuilder;//Creating an Instance of type TestMotorBuilder on the heap.

TestMotorBuilder* TestMotorBuilder::GetTestMotorBuilderInstance()
{
	static TestMotorBuilder* TestMotorBuilderInstance = NULL;
	if (!TestMotorBuilderInstance)
		TestMotorBuilderInstance = new TestMotorBuilder;
	return TestMotorBuilderInstance;
}

TestMotorBuilder::TestMotorBuilder()
{
	/*
	TestMotorBuilder Constructor is private and is only called ones when the static TestMotorBuilderInstance is instantiated
	*/
	this->SetObjectType();//Setting the Object Type when the constructor is called	
	XMLBuilder::GetXMLBuilderInstance().AddBuilder(this->m_objectType, this);//Registering the TestMotor Builder in the BuilderMap of XMLBuilder																									
}
void TestMotorBuilder::BuildObject(tinyxml2::XMLElement* root)
{
	/*
	BuildObject Method is used to Build the Obejct of type TestMotor , it takes a node of XML Tree and sets all the 
	attributes by iterating over all the XMLNodes.
	*/
	TestMotor* Object = new TestMotor();
	tinyxml2::XMLElement* XMLelement = root->FirstChildElement();
	const char * Attribute1("Name");
	const char * Attribute2("MaxSpeed");
	const char * Attribute3("MaxCurrent");

	while (XMLelement != NULL)
	{
		const char * value(XMLelement->Value());
		const char * data(XMLelement->GetText());
		if (strcmp(value, Attribute1) == 0)
			Object->SetName(data);
		else if (strcmp(value, Attribute2) == 0)
			Object->SetMaxSpeed(std::atof(data));
		else if (strcmp(value, Attribute3) == 0)
			Object->SetMaxCurrent(std::atof(data));

		XMLelement = XMLelement->NextSiblingElement();
	}
	// Setting Object Map with the Object
	m_objectMap[Object->GetName()] = Object;
}


NamedObject* TestMotorBuilder::GetObject(const char * name)
{
	/*
	Get an Object based on the uniquename of the object
	*/
	if (m_objectMap.count(name))
		return m_objectMap.at(name);
	else
		return nullptr;
}

TestMotor* TestMotorBuilder::GetTestMotor(const char* name)
{
	/*
	Get the TestMotor based on the uniquename of the object
	*/
	if (m_objectMap.count(name))
		return m_objectMap.at(name);
	else
		return nullptr;
}
