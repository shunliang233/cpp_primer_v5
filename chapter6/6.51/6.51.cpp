// Windows Powershell: g++ -std=c++11 -Wall 6.51.cpp -o 6.51.exe ; ./6.51.exe
// Mac Zsh: g++ -std=c++11 -Wall 6.51.cpp -o 6.51.out ; ./6.51.out

#include <iostream>
using std::cout;
using std::endl;

void f() { cout << 1 << endl; }
void f(int i) { cout << 2 << endl; }
void f(int i, int j) { cout << 3 << endl; }
void f(double, double = 3.14) { cout << 4 << endl; }

int main()
{
    // f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
}