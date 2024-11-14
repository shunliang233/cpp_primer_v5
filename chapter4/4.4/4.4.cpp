// Windows Powershell: g++ -std=c++11 -Wall -o 4.4.exe 4.4.cpp ; ./4.4.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 4.4.out 4.4.cpp ; ./4.4.out

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;
    return 0;
}
