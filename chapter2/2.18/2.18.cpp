// Windows Powershell: g++ -std=c++11 -Wall -o 2.18.exe 2.18.cpp ; ./2.18.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 2.18.out 2.18.cpp ; ./2.18.out
#include <iostream>

int main()
{
    int i = 1;
    int j = 2;
    int *p = &i;

    p = &j;   // 更改指针的值
    *p = 100; // 更改指针所指对象的值
}