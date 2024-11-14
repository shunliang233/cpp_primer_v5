// Windows Powershell: g++ -std=c++11 -Wall -o 5.23.exe 5.23.cpp ; ./5.23.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 5.23.out 5.23.cpp ; ./5.23.out

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a / b << endl;
    return 0;
}