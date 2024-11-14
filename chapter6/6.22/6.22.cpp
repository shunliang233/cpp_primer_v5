// Windows Powershell: g++ -std=c++11 -Wall -o 6.22.exe 6.22.cpp ; ./6.22.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 6.22.out 6.22.cpp ; ./6.22.out

#include <iostream>
using std::cout;
using std::endl;

void change(int *&a, int *&b)
{
    int *mid = a;
    a = b;
    b = mid;
}

int main()
{
    int i = 42, j = 48;
    int *pi = &i, *pj = &j;
    cout << pi << ' ' << pj << endl;
    change(pi, pj);
    cout << pi << ' ' << pj << endl;
    return 0;
}