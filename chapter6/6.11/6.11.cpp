// Windows Powershell: g++ -std=c++11 -Wall 6.11.cpp -o 6.11.exe ; ./6.11.exe
// Mac Zsh: g++ -std=c++11 -Wall 6.11.cpp -o 6.11.out ; ./6.11.out

#include <iostream>
using std::cout;
using std::endl;

void reset(int &i)
{
    i = 0;
}

int main()
{
    int j = 42;
    reset(j);
    cout << j << endl;
    return 0;
}
