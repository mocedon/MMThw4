#include "Course.h"

Course::Course(int id, char* name, int hw_num, double hw_weigh) :
	id_(id), name_(getCopy(name)), hw_num_(hw_num), hw_weigh_(hw_weigh),
	exam_grade_(0) ,hw_grade_(new int[hw_num]) {}

Course::~Course()
{
	delete[] name_;
	delete[] hw_grade_;
}

int Course::getNum() const
{
	return id_;
}

char* Course::getName() const
{
	return getCopy(name_);
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
	double grade = (1 - hw_weigh_)*exam_grade_ + hw_weigh_ * getHwAverage();
	return static_cast<int>(grade + 0.5);
}

bool Course::setExamGrade(int grade)
{
	if (grade<0 || grade>MAX_GRADE)
	{
		return false;
	}
	exam_grade_ = grade;
	return true;
}

bool Course::setHwGrade(int i, int grade)
{
	if (i < 0 || i >= hw_num_)
	{
		return false;
	}
	if (grade<0 || grade>MAX_GRADE)
	{
		return false;
	}
	hw_grade_[i] = grade;
	return true;
}

char* Course::getCopy(char* str) const
{
	if (str == NULL)
	{
		return NULL;
	}
	char* copy = new char[strlen(str) + 1];
	strcpy(copy, str);
	return copy;
}