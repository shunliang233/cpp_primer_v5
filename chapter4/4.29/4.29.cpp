// Windows Powershell: g++ -std=c++11 -Wall -o 4.29.exe 4.29.cpp ; ./4.29.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 4.29.out 4.29.cpp ; ./4.29.out

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int x[10];
    int *p = x;
    cout << sizeof(x) / sizeof(*x) << endl;
    cout << sizeof(p) / sizeof(*p) << endl;
    return 0;
}