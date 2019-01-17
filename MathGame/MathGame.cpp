
#include "pch.h"
#include <iostream>
#include <random>

using namespace std;

bool MathOperation(int, int, char);

int main() 
{
  char ch = 'y';
  int num1{};
  int num2{};

  random_device seed{};
  mt19937 engine{seed()};
  uniform_int_distribution<> dist{1, 10};

  while (ch == 'y' || ch == 'Y') {
    num1 = dist(engine);
    num2 = dist(engine);

    if (MathOperation(num1, num2, '+')) {
      cout << "Correct" << endl;
    } else { 
      cout << "Wrong" << endl;
    }

    
    if (MathOperation(num1, num2, '-')) {
      cout << "Correct" << endl;
    } else { 
      cout << "Wrong" << endl;
    }

    if (MathOperation(num1, num2, '*')) {
      cout << "Correct" << endl;
    } else { 
      cout << "Wrong" << endl;
    }

    cout << "Do you want to continue (Y/N)? ";

    cin >> ch;
  }

  return 0;
}

bool MathOperation(int n1, int n2, char ch) {
   bool result;
   int answer;

   cout << n1 << ' ' << ch << ' ' << n2 << " = ? ";
   cin >> answer;

   switch (ch) {
   case '+':
      result = (answer == n1 + n2);
      break;

   case '-':
      result = (answer == n1 - n2);
      break;

   case '*':
      result = (answer == n1 * n2);
      break;

   default:
      cout << "Invalid operation" << endl;
   }

   return result;
}