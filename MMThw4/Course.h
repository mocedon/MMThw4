#ifndef _COURSE_H_
#define _COURSE_H_


#ifndef _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 
#endif 


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;


#define MAX_GRADE 100

class Course
{
protected:
	int id_;
	char* name_;
	int hw_num_;
	double hw_weigh_;
	int exam_grade_;
	int* hw_grade_;
	char* getCopy(char* str) const;
public:
	Course(int id = 0, char* name = NULL, int hw_num = 0, double hw_weigh = 0);
	virtual ~Course();
	int getNum() const;
	char* getName() const;
	int getExamGrade() const;
	int getHwGrade(int i) const;
	int getHwNum() const;
	double getHwWeigh() const;
	double getHwAverage() const;
	virtual int getCourseGrade() const;
	bool setExamGrade(int grade);
	bool setHwGrade(int i, int grade);
};
	
#endif