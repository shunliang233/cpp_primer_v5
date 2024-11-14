// Windows Powershell: g++ -std=c++11 -Wall -o 4.28.exe 4.28.cpp ; ./4.28.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 4.28.out 4.28.cpp ; ./4.28.out

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    cout << sizeof(bool) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(wchar_t) << endl;
    cout << sizeof(char16_t) << endl;
    cout << sizeof(char32_t) << endl;
    cout << sizeof(short) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(long long) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(long double) << endl;
    return 0;
}