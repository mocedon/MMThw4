#include "CS_Course.h"

CS_Course::CS_Course(int id, char* name, int hw_num, double hw_weigh, bool takef, char* book) :
	Course(Course(id, name, hw_num, hw_weigh)), takef_(takef), book_(getCopy(book)) {}

CS_Course::~CS_Course()
{
	delete[] book_;
}

int CS_Course::getCourseGrade() const
{
	if (takef_ && exam_grade_ < getHwAverage())
	{
		return Course::getCourseGrade();
	}
	return exam_grade_;
}

bool CS_Course::isTakef() const
{
	return takef_;
}

char* CS_Course::getBook() const
{
	return getCopy(book_);
}

bool CS_Course::setTakef(bool takef)
{
	takef_ = takef;
	return true;
}

bool CS_Course::setBook(char* book)
{
	if (book == NULL)
	{
		return false;
	}
	delete[] book_;
	book_ = getCopy(book);
	return true;
}