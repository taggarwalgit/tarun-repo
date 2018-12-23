#include <iostream>

#include "Student.h"

using namespace std;

int main()
{
   cout << "CMake Sample Program" << endl;

   Student objStudent;

   cout << objStudent;

   objStudent = "Tarun";
   objStudent.mb_setAge(25);

   cout << objStudent;

   //cout << "Name: " << objStudent.mb_getName() << endl;
   //cout << "Age: " << objStudent.mb_getAge() << endl;

   return 0;
}