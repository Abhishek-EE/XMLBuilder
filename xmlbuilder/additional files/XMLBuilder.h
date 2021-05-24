#pragma once
#ifndef XMLBUILDER_H
#define XMLBUILDER_H
#include "tinyxml2.h"
#include "NamedObjectBuilder.h"
#include"StringCompare.h"
#include <map>
/*
An XML builder is used to build objects from the given XML File. 
*/
class NamedObjectBuilder;
class XMLBuilder
{
	/*
	A class which is used to build a system from an XML Document.
	The System Comtains NamedObjects which are built by
	NamedObjectBuilders. The class assumes that the NamedObjectBuilders already exists
	and a pointer to there location is stored in the BuilderMap. 
	*/
public:
	
	void Build(const char*); 
	static XMLBuilder& GetXMLBuilderInstance();
	NamedObjectBuilder* GetObjectBuilder(const char * name);
	void AddBuilder(const char * builderName, NamedObjectBuilder* namedobjectbuilder);

protected:

	std::map<const char *, NamedObjectBuilder*,cmp_str> m_builderMap;// A map to store all of the pointers to named object builders 
	XMLBuilder() {};	
};

#endif /* XMLBUILDER_H */