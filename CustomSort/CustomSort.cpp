// Sort strings (based on string length) using C++11 Features
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
   // Brace Initialization (C++11)
   vector<string> vecOfString{ "Apple", "Orange", "Banana", "Mango", "Grapes" };

   cout << "Before Sorting:" << endl;

   // auto type (C++11)
   for (auto i = 0; i < vecOfString.size(); ++i) {
      cout << vecOfString[i] << " ";
   }

   cout << endl << endl;

   // Anatomy of Lambda [Capture list] (parameter list) { body }
   // basic (non-generic) lambda (C++11)
   sort(vecOfString.begin(), vecOfString.end(),
      [](const string& a, const string& b) {
      return (a.length() < b.length());
   }
   );

   cout << "After Sorting:" << endl;

   // range-based for loop (c++11)
   for (auto s : vecOfString) {
      cout << s << endl;
   }

   // Binary Literals (C++11)
   auto age = 0b100100;
   cout << "My age: " << age << endl;

   // nullptr (C++11)
   int *p = new int(100);   // Assignment
   cout << "Value: " << *p << endl;
   cout << "Pointer value before deletion: " << p << endl;
   delete p;
   cout << "Pointer value after deletion: " << p << endl;
   p = nullptr;
   cout << "Pointer value after assignment to nullptr: " << p << endl;

   return 0;
}