#include "Person.h"

Person::Person(int id = 0, char* name = NULL) :
	id_(id) , name_(getCopy(name)) {} 

Person::~Person()
{
	delete[] name_ ;
}

int Person::getID() const
{
	return id_ ;
}

char* Person::getName() const
{
	return getCopy(name_) ;
}

char* Person::getCopy(char* str) const
{
	if (str == NULL)
	{
		return NULL;
	}
	char* copy = new char[strlen(str) + 1];
	strcpy(copy, str);
	return copy;
}
