#ifndef _STARRAY_H_
#define _STARRAY_H_

#include "Proj.h"
#include "Student.h"

#define NO_STUDENT -1

class StArray
{
protected:
	int num_;
	Student** arr_;
	int searchStudent(int id) const;
	Course* getCourse(int id, int num) const;
public:
	StArray();
	virtual ~StArray();
	bool addStudent(int id, char* name);
	bool addEE_Course(int id, int num, char* name, int hwNum, double hwWeigh);
	bool addCS_Course(int id, int num, char* name, int hwNum, double hwWeigh,
		bool takef, char* book);
	bool setHwGrade(int id, int num, int i, int grade);
	bool setExamGrade(int id, int num, int grade);
	bool setFactor(int num, int factor);
	bool printStudent(int id) const;
	void printAll() const;
	void resetStArray();
};

#endif