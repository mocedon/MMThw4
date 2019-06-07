#include "Student.h"

Student::Student(int id = 0, char* name) :
	Person(id , name) , EEC_num_(0) , CSC_num_(0) {}

Student::~Student() {
	delete[] EEC_ ;
	delete[] CSC_ ;
}

int Student::getCourseCnt()const {
	return EEC_num_ + CSC_num_ ;
}

bool Student::addEE_Course(EE_Course* c) {
	if (c == NULL) return false ;
	EEC_[EEC_num_] = c ;
	EEC_num_++ ;
	return true ;
}

bool Student::addCS_Course(CS_Course* c) {
	if (c == NULL) return false;
	CSC_[CSC_num_] = c;
	CSC_num_++;
	return true;
}

bool Student::remCourse(EE_Course* c) {
	if (c == NULL) return false ;
	delete c ;
	return true ;
}

bool Student::remCourse(CS_Course* c) {
	if (c == NULL) return false ;
	delete c ;
	return true ;
}

EE_Course* Student::getEE_Course(int c) const {
	for (int i = 0; i < EEC_num_; i++) {
		if (EEC_[i]->getNum() == c) return EEC_[i] ;
	}
	return NULL ;
}

CS_Course* Student::getCS_Course(int c) const {
	for (int i = 0; i < CSC_num_; i++) {
		if (CSC_[i]->getNum() == c) return CSC_[i];
	}
	return NULL;
}

int Student::getAvg() const {
	int sum = 0 ;
	for (int i = 0; i < CSC_num_; i++) {
		sum += CSC_[i]->getCourseGrade() ;
	}
	for (int i = 0; i < EEC_num_; i++) {
		sum += EEC_[i]->getCourseGrade();
	}
	return sum / (EEC_num_ + CSC_num_) ;
}

void Student::print() const {
	cout << "SName: " << name_ << endl ;
	cout << "SID: " << id_ << endl ;
	cout << "Avg.: " << getAvg() << endl << endl ;
	cout << "EE:" << endl ;
	for (int i = 0; i < EEC_num_; i++) {
		EEC_[i]->print() ;
	}
	cout << endl << "CS courses:" << endl ;
	for (int i = 0; i < CSC_num_; i++) {
		CSC_[i]->print() ;
	}
}