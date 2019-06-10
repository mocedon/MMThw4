#include "StArray.h"

StArray::StArray() : num_(0), arr_(new Student*[MAX_STUDENT_NUM])
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		arr_[i] = NULL;
	}
}

StArray::~StArray()
{
	resetStArray();
	delete[] arr_;
}

bool StArray::addStudent(int id, char* name)
{
	if (name == NULL || num_ >= MAX_STUDENT_NUM)
	{
		return false;
	}
	arr_[num_] = new Student(id, name);
	num_++;
	return true;
}

bool StArray::addEE_Course(int id, int num, char* name, int hwNum, double hwWeigh)
{
	int i = searchStudent(id);
	if (i == NO_STUDENT)
	{
		return false;
	}
	EE_Course c(num, name, hwNum, hwWeigh);
	return arr_[i]->addEE_Course(&c);
}

bool StArray::addCS_Course(int id, int num, char* name, int hwNum, double hwWeigh,
	bool takef, char* book)
{
	int i = searchStudent(id);
	if (i == NO_STUDENT)
	{
		return false;
	}
	CS_Course c(num, name, hwNum, hwWeigh, takef, book);
	return arr_[i]->addCS_Course(&c);
}

bool StArray::setHwGrade(int id, int num, int i, int grade)
{
	int j = searchStudent(id);
	if (j == NO_STUDENT)
	{
		return false;
	}
	EE_Course* ee = arr_[j]->getEE_Course(num);
	CS_Course* cs = arr_[j]->getCS_Course(num);
	if (ee != NULL)
	{
		return ee->setHwGrade(i, grade);
	}
	else if (cs != NULL)
	{
		return cs->setHwGrade(i, grade);
	}
	else
	{
		return false;
	}
}

bool StArray::setExamGrade(int id, int num, int grade)
{
	int i = searchStudent(id);
	if (i == NO_STUDENT)
	{
		return false;
	}
	EE_Course* ee = arr_[i]->getEE_Course(num);
	CS_Course* cs = arr_[i]->getCS_Course(num);
	if (ee != NULL)
	{
		return ee->setExamGrade(grade);
	}
	else if (cs != NULL)
	{
		return cs->setExamGrade(grade);
	}
	else
	{
		return false;
	}
}

bool StArray::setFactor(int num, int factor)
{
	if (factor < 0)
	{
		return false;
	}
	EE_Course* c = NULL;
	for (int i = 0; i < num_; i++)
	{
		c = arr_[i]->getEE_Course(num);
		if (c != NULL)
		{
			c->setFactor(factor);
		}
	}
	return true;
}

bool StArray::printStudent(int id) const
{
	int i = searchStudent(id);
	if (i == NO_STUDENT)
	{
		return false;
	}
	arr_[i]->print();
	return true;
}

void StArray::printAll() const
{
	for (int i = 0; i < num_; i++)
	{
		arr_[i]->print();
	}
}

void StArray::resetStArray()
{
	for (int i = 0; i < num_; i++)
	{
		delete arr_[i];
	}
	num_ = 0;
}

int StArray::searchStudent(int id) const
{
	for (int i = 0; i < num_; i++)
	{
		if (id == arr_[i]->getID())
		{
			return i;
		}
	}
	return NO_STUDENT;
}
