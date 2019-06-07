#ifndef _STUDENT_H_
#define _STUDENT_H_


#include "Proj.h"
#include "Person.h"
#include "EE_Course.h"
#include "CS_Course.h"

class Student : public Person {
protected:
	int EEC_num_ ;
	EE_Course* EEC_[MAX_COURSE_NUM] ;
	int CSC_num_ ;
	CS_Course* CSC_[MAX_COURSE_NUM] ;

public:
	Student(int id = 0 , char* name) ;
	virtual ~Student() ;
	int getCourseCnt()const ;
	bool addEE_Course(EE_Course* c) ;
	bool addCS_Course(CS_Course* c) ;
	bool remCourse(EE_Course* c) ;
	bool remCourse(CS_Course* c) ;
	EE_Course* getEE_Course(int c) const ;
	CS_Course* getCS_Course(int c) const ;
	int getAvg() const ;
	void print() const ;
};

#endif