// Windows Powershell: g++ -std=c++11 -Wall -o 6.3.exe 6.3.cpp ; ./6.3.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 6.3.out 6.3.cpp ; ./6.3.out

#include <iostream>
using std::cout;
using std::endl;

int fact(int val)
{
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}

int main()
{
    cout << fact(5) << endl;
    return 0;
}