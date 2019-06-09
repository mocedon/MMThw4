#ifndef _EE_COURSE_H_
#define _EE_COURSE_H_

#include "Course.h"

class EE_Course : public Course
{
protected:
	int factor_;
public:
	EE_Course(int id = 0, char* name = NULL, int hw_num = 0, double hw_weigh = 0);
	int getCourseGrade() const;
	int getFactor() const;
	bool setFactor(int factor);
};

#endif