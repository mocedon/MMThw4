#include "EE_Course.h"

EE_Course::EE_Course(int id, char* name, int hw_num, double hw_weigh) :
	Course(Course(id,name,hw_num,hw_weigh)),factor_(0) {}

int EE_Course::getCourseGrade() const
{
	int grade = Course::getCourseGrade() + factor_;
	if (grade > MAX_GRADE)
	{
		return MAX_GRADE;
	}
	return grade;
}

int EE_Course::getFactor() const
{
	return factor_;
}

bool EE_Course::setFactor(int factor)
{
	if (factor < 0)
	{
		return false;
	}
	factor_ = factor;
	return true;
}