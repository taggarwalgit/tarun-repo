#include <windows.h>
#include <iostream>

#include <cassert>   // includes assert.h
#include <assert.h>
#include <crtdbg.h>


using namespace std;

#define ASSERT assert         // assert defined in assert.h
//#define ASSERT _ASSERTE     // _ASSERTE defined in crtdbg.h

// assert definition in assert.h without using if-else and ternary operators
// #define assert(expression) (!!(expression) || Print info of file, line of failed expression in a windows assertion dialog)

// _ASSERTE defintion in crtdbg.h : More detailed
// #define _ASSERTE(expression) _ASSERT_EXPR((expr), _CRT_WIDE(#expr)), _CRT_WIDE(#expr) is the message formed in another macro

#ifdef _DEBUG
#define VERIFY ASSERT
#else
#define VERIFY(expression) (expression)
#endif

struct EventCreationException {
   EventCreationException() : _code(GetLastError()) {}
   DWORD GetLastError() { return _code; }

   DWORD _code;
};

class ManualResetEvent {
public:
   ManualResetEvent() {
      _event = CreateEvent(nullptr, true, false, nullptr);  // event kernel object

      if (!_event) {
         throw EventCreationException();
      }
   }
   ~ManualResetEvent() {
      VERIFY(CloseHandle(_event)); // Validation only for debug build
   }

private:
   HANDLE _event;
};


auto main() -> int {
   auto ev = ManualResetEvent{};
   auto ev2 = ev;

   return 0;
}