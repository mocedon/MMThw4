#include "Student.h"

Student::Student(int id, char* name) :
	Person(Person(id, name)), EEC_num_(0), EEC_(new EE_Course*[MAX_COURSE_NUM]),
	CSC_num_(0), CSC_(new CS_Course*[MAX_COURSE_NUM]) {}

Student::~Student() {
	delete[] EEC_ ;
	delete[] CSC_ ;
}

int Student::getCourseCnt() const
{
	return EEC_num_ + CSC_num_;
}

bool Student::addEE_Course(EE_Course* c)
{
	if (c == NULL || EEC_num_ >= MAX_COURSE_NUM)
	{
		return false;
	}
	int id = c->getNum();
	char* name = c->getName();
	int hwNum = c->getHwNum();
	double hwWeigh = c->getHwWeigh();
	EEC_[EEC_num_] = new EE_Course(id, name, hwNum, hwWeigh);
	delete[] name;
	EEC_[EEC_num_]->setExamGrade(c->getExamGrade());
	for (int i = 0; i < hwNum; i++)
	{
		EEC_[EEC_num_]->setHwGrade(i, c->getExamGrade());
	}
	EEC_[EEC_num_]->setFactor(c->getFactor());
	EEC_num_++ ;
	return true ;
}

bool Student::addCS_Course(CS_Course* c)
{
	if (c == NULL || CSC_num_ >= MAX_COURSE_NUM)
	{
		return false;
	}
	int id = c->getNum();
	char* name = c->getName();
	int hwNum = c->getHwNum();
	double hwWeigh = c->getHwWeigh();
	bool takef = c->isTakef();
	char* book = c->getBook();
	CSC_[CSC_num_] = new CS_Course(id, name, hwNum, hwWeigh, takef, book);
	delete[] name;
	delete[] book;
	EEC_[CSC_num_]->setExamGrade(c->getExamGrade());
	for (int i = 0; i < hwNum; i++)
	{
		CSC_[CSC_num_]->setHwGrade(i, c->getExamGrade());
	}
	CSC_num_++;
	return true;
}

bool Student::remCourse(int id)
{
	for (int i = 0; i < EEC_num_; i++)
	{
		if (id == EEC_[i]->getNum())
		{
			delete EEC_[i];
			EEC_num_--;
			for (int j = i; j < EEC_num_; j++)
			{
				EEC_[j] = EEC_[j + 1];
			}
			EEC_[EEC_num_] = NULL;
			return true;
		}
	}
	for (int i = 0; i < CSC_num_; i++)
	{
		if (id == CSC_[i]->getNum())
		{
			delete CSC_[i];
			CSC_num_--;
			for (int j = i; j < CSC_num_; j++)
			{
				CSC_[j] = CSC_[j + 1];
			}
			CSC_[CSC_num_] = NULL;
			return true;
		}
	}
	return false;
}

EE_Course* Student::getEE_Course(int id) const
{
	for (int i = 0; i < EEC_num_; i++)
	{
		if (EEC_[i]->getNum() == id)
		{
			return EEC_[i];
		}
	}
	return NULL ;
}

CS_Course* Student::getCS_Course(int id) const
{
	for (int i = 0; i < CSC_num_; i++)
	{
		if (CSC_[i]->getNum() == id)
		{
			return CSC_[i];
		}
	}
	return NULL;
}

int Student::getAvg() const
{
	double sum = 0 ;
	for (int i = 0; i < CSC_num_; i++)
	{
		sum += CSC_[i]->getCourseGrade();
	}
	for (int i = 0; i < EEC_num_; i++)
	{
		sum += EEC_[i]->getCourseGrade();
	}
	sum /= (EEC_num_ + CSC_num_);
	return static_cast<int>(sum + 0.5);
}

void Student::print() const
{
	cout << "SName: " << name_ << endl;
	cout << "SID: " << id_ << endl;
	cout << "Avg.: " << getAvg() << endl;
	cout << endl << "EE Courses:" << endl;
	for (int i = 0; i < EEC_num_; i++)
	{
		printCourse(EEC_[i]);
	}
	cout << endl << "CS courses:" << endl;
	for (int i = 0; i < CSC_num_; i++)
	{
		printCourse(CSC_[i]);
	}
	cout << endl;
}

void Student::printCourse(Course* c) const
{
	int num = c->getNum();
	char* name = c->getName();
	int grade = c->getCourseGrade();
	cout << num << " " << name << " " << grade << endl;
	delete[] name;
}
