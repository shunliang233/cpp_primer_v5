// Windows Powershell: g++ -std=c++11 -Wall -o 6.21.exe 6.21.cpp ; ./6.21.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 6.21.out 6.21.cpp ; ./6.21.out

#include <iostream>
using std::cout;
using std::endl;

// i 加 const 属性的话是顶层 const, 因此加不加 const 无所谓
// 而 p 加的 const 是底层 const, 因此最好加上
int compare(int i, const int *p)
{
    if (i >= *p)
    {
        return i;
    }
    else
    {
        return *p;
    }
}

int main()
{
    int i = 42, j = 423;
    cout << compare(j, &i) << endl;
    return 0;
}