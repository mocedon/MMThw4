#ifndef _PERSON_H_
#define _PERSON_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std ;

class Person
{
protected:
	int id_ ;
	char* name_ ;
	char* getCopy(char* str) const;

public:
	Person(int id = 0 , char* name = NULL) ;
	virtual ~Person() ;
	int getID() const ;
	char* getName() const ;
};

#endif