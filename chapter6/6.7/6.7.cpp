// Windows Powershell: g++ -std=c++11 -Wall -o 6.7.exe 6.7.cpp ; ./6.7.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 6.7.out 6.7.cpp ; ./6.7.out

#include <iostream>
using std::cout;
using std::endl;

int count_calls()
{
    static int ctr = -1;
    return ++ctr;
}

// 在 main 函数里只管调用，不应该对 count_calls 函数中定义的 static 变量进行操作
int main()
{
    for (int i = 0; i != 10; i++)
    {
        cout << count_calls() << endl;
    }
    return 0;
}
