// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include "StrBlob_v2.hpp"
using std::cout;
using std::endl;

int main()
{
    StrBlob a = {"aa", "bb"};
    const StrBlob b = {"11", "22", "33"};
    cout << a.front() << endl;
    cout << b.back() << endl;
}