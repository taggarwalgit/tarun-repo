#ifndef _STUDENT_H_
#define _STUDENT_H_

//#define DllExport __declspec( dllexport )

class 
   //DllExport 
   Student {
private:
   char* _name;
   int _age;

public:
   Student() : _name(""), _age(0) {}
   Student(char*, int = 0);
   Student(const Student&);
   Student& operator=(const Student&);

	 
   char* mb_getName() const {
      return _name;
   }
   
   int mb_getAge() const {
	   return _age;
   }

   void mb_setAge(int p_age) {
      _age = p_age;
   }


   friend 
      //DllExport 
      void operator<<(std::ostream&, const Student&);
};

#endif _STUDENT_H_