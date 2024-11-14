// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
using std::cout;
using std::endl;

class numbered
{
public:
    numbered() { mysn = ++count; } // 默认构造函数
    int mysn;

private:
    static int count;
};

// 类中的静态成员变量必须在外部初始化
int numbered::count = 0;

void f(numbered s) { cout << s.mysn << endl; }

// 把 a 的 mysn 都拷贝到 b 和 c 中，进一步拷贝到 f 函数的局部变量 s 中
int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}