#ifndef _CS_COURSE_H_
#define _CS_COURSE_H_

#include "Course.h"

class CS_Course : public Course
{
protected:
	bool takef_;
	char* book_;
public:
	CS_Course(int id = 0, char* name = NULL, int hw_num = 0, double hw_weigh = 0,
		bool takef = true, char* book = NULL);
	virtual ~CS_Course() ;
	int getCourseGrade() const;
	bool isTakef() const;
	char* getBook() const;
	bool setTakef(bool takef);
	bool setBook(char* book);
};

#endif