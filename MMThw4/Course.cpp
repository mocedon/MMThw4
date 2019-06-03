#include "Course.h"

Course::Course(int id, char* name, int hw_num, double hw_weigh) :
	id_(id), name_(strcpy(new char[strlen(name)+1],name)), hw_num_(hw_num), hw_weigh_(hw_weigh),
	exam_grade_(0) ,hw_grade_(new int[hw_num]) {}

Course::~Course()
{
	delete[] name_;
	delete[] hw_grade_;
}

int Course::getNum() const
{
	return hw_num_;
}

char* Course::getName() const
{
	char* copy = new char[strlen(name_) + 1];
	strcpy(copy, name_);
	return copy;
}

int Course::getExamGrade() const
{
	return exam_grade_;
}

int Course::getHwGrade(int i) const
{
	return hw_grade_[i];
}

int Course::getHwNum() const
{
	return hw_num_;
}

double Course::getHwWeigh() const
{
	return hw_weigh_;
}

double Course::getHwAverage() const
{
	double sum = 0;
	for (int i = 0; i < hw_num_; i++)
	{
		sum += hw_grade_[i];
	}
	return sum / hw_num_;
}

int Course::getCourseGrade() const
{
	return (1 - hw_weigh_)*exam_grade_ + hw_weigh_ * getHwAverage();
}

int Course::setExamGrade(int grade)
{
	exam_grade_ = grade;
}

int Course::setHwGrade(int i, int grade)
{
	hw_grade_[i] = grade;
}