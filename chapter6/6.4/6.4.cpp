// Windows Powershell: g++ -std=c++11 -Wall -o 6.4.exe 6.4.cpp ; ./6.4.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 6.4.out 6.4.cpp ; ./6.4.out

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// 阶乘参数通过函数中的交互获取，不需要从实参输入，因此使用空形参列表
int fact()
{
    int val = 0;
    cout << "Enter a integer: " << endl;
    cin >> val;
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}

int main()
{
    cout << fact() << endl;
    return 0;
}