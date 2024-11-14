// Windows Powershell: g++ -std=c++11 -Wall -o 6.5.exe 6.5.cpp ; ./6.5.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 6.5.out 6.5.cpp ; ./6.5.out

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// abs 函数名已经被 macOS 系统占用了，再定义会报错
double MyABS(double val)
{
    if (val < 0)
        val = -val;
    return val;
}

int main()
{
    cout << "Enter a number: " << endl;
    double a = 0;
    cin >> a;
    cout << MyABS(a) << endl;
    return 0;
}