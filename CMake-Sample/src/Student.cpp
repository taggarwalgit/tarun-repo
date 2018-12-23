#include <string.h>
#include <iostream>

#include "Student.h"

Student::Student(char* p_name, int p_age) : _age(p_age) {

	_ASSERT(p_name != NULL);
   
	int length = strlen(p_name);
   _name = new char[length + 1];
   strcpy_s(_name, length + 1, p_name);
}

Student::Student(const Student& p_stduent) : _age(p_stduent._age) {
   
   int length = strlen(p_stduent._name);
   _name = new char[length + 1];
   strcpy_s(_name, length + 1, p_stduent._name);
}

Student& Student::operator= (const Student& p_student) {

   if (this != &p_student) {
      int length = strlen(p_student._name);
      _name = new char[length + 1];
      strcpy_s(_name, length + 1, p_student._name);
      _age = p_student._age;
   }

   return *this;
}


void operator<< (std::ostream& p_os, const Student& p_student) {
	p_os << "Name: " << p_student.mb_getName() << std::endl;
	p_os << "Age: " << p_student.mb_getAge() << std::endl;
}