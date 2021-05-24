#include "TcPch.h"
#pragma hdrstop
#include "XMLBuilder.h"


XMLBuilder& XMLBuilder::GetXMLBuilderInstance() 
{
	/*
	A method to return the XMLFactory instance of the XML Builder. 
	*/
	static XMLBuilder* XMLBuilderInstance = NULL;
	if(!XMLBuilderInstance)
		XMLBuilderInstance = new XMLBuilder;
	return *XMLBuilderInstance;
}

void XMLBuilder::Build(const char* textdocument) 
{
	/*
	A method to build the system. It reads in the XML Document in the form of const char* string
	and iterates over the XML Tree and calls the designated NamedObjectBuilder for every First Child Node
	in the XML Tree. Returns true if built correctly and false if not.
	*/
	tinyxml2::XMLDocument doc;
	doc.Parse(textdocument);
	tinyxml2::XMLElement* ChildElement = doc.RootElement()->FirstChildElement();
	
	while (ChildElement != NULL)
	{
		const char * value(ChildElement->Value());
		if (m_builderMap.count(value))
			m_builderMap[value]->BuildObject(ChildElement);
		else
		{
			/*ToDo: need to throw exception object builder does not exist*/
			
		}
		ChildElement = ChildElement->NextSiblingElement();
	}

}

 void XMLBuilder::AddBuilder(const char * builderName, NamedObjectBuilder* namedobjectbuilder)
{
	 /*
	 Adds a pointer to the named object builder to the BuilderMap.
	 */
	if (!(m_builderMap.count(builderName)))
		m_builderMap[builderName] = namedobjectbuilder;
}

NamedObjectBuilder* XMLBuilder::GetObjectBuilder(const char * name)
{
	/*
	If the Builder is not yet built returns the nullptr otherwise returns the pointer to the Named Object 
	Builder.
	*/
	if (m_builderMap.count(name))
		return m_builderMap[name];
	else
		return nullptr;
}

