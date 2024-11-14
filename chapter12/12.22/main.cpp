// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <fstream>
#include "StrBlob_v4.hpp"
using std::cout;
using std::endl;
using std::ifstream;

int main()
{
    StrBlob a = {"aa", "bb"};
    const StrBlob b = {"11", "22", "33"};
    cout << a.front() << endl;
    cout << b.front() << endl;

    StrBlobPtr a1(a);
    ConstStrBlobPtr b1(b);
    cout << a1.deref() << endl;
    cout << b1.deref() << endl;
}