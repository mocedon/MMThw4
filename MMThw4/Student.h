#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "Proj.h"
#include "Person.h"
#include "EE_Course.h"
#include "CS_Course.h"

class Student : public Person
{
protected:
	int EEC_num_ ;
	EE_Course** EEC_;
	int CSC_num_ ;
	CS_Course** CSC_;
	void printCourse(Course* c) const;

public:
	Student(int id = 0, char* name = NULL);
	virtual ~Student() ;
	int getCourseCnt() const;
	bool addEE_Course(EE_Course* c) ;
	bool addCS_Course(CS_Course* c) ;
	bool remCourse(int id);
	EE_Course* getEE_Course(int id) const ;
	CS_Course* getCS_Course(int id) const ;
	int getAvg() const ;
	void print() const ;
};

#endif