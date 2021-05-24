
#ifndef NAMEDOBJECT_H_XMLBUILDER
#define NAMEDOBJECT_H_XMLBUILDER
#include <iostream>
#include <string>

class NamedObject
{
public:

	virtual const char* GetName() const = 0; 
	virtual void SetName(const char * name) = 0; 
	NamedObject() = default;

protected:

};

#endif /* NAMEDOBJECT_H_XMLBUILDER */


