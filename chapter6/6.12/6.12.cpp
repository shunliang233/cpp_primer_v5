// Windows Powershell: g++ -std=c++11 -Wall 6.12.cpp -o 6.12.exe ; ./6.12.exe
// Mac Zsh: g++ -std=c++11 -Wall 6.12.cpp -o 6.12.out ; ./6.12.out

#include <iostream>
using std::cout;
using std::endl;

// 改用引用来修改实参的话更方便，因为传入实参和使用形参的时候都不用加解引用运算符 *

void change(int &a, int &b)
{
    int middle = a;
    a = b;
    b = middle;
}

int main()
{
    int i = 42, j = 10;
    cout << i << " " << j << endl;
    change(i, j);
    cout << i << " " << j << endl;
    return 0;
}