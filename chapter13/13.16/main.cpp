// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
using std::cout;
using std::endl;

class numbered
{
public:
    numbered() { mysn = ++count; }                           // 默认构造函数，新生成唯一的 mysn
    numbered(const numbered &a) { mysn = ++count; }          // 拷贝构造函数，使用新生成的 mysn 而不是从 a 中拷贝来
    numbered &operator=(const numbered &a)
    {
        mysn = ++count;
        return *this;
    } // 拷贝赋值运算符，不用生成新的 mysn, 使用被拷贝对象原有的 mysn
    int mysn;

private:
    static int count;
};

int numbered::count = 0;

void f(const numbered &s) { cout << s.mysn << endl; }

// 不会拷贝 a 中的 mysn 到 b 和 c 中，调用 f 函数时不发生拷贝，因此输出的是 a, b, c 各自的 mysn (这种情况是最合理的)
int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}