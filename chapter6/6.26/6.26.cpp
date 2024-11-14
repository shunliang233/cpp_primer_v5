// Windows Powershell: g++ -std=c++11 -Wall -o 6.26.exe 6.26.cpp ; ./6.26.exe -d -o ofile data0
// Mac Zsh: g++ -std=c++11 -Wall -o 6.26.out 6.26.cpp ; ./6.26.out -d -o ofile data0

#include <iostream>
#include <string>
#include <iterator>
using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;

// 不能使用范围 for 循环遍历数组，因为必须有迭代器成员才能使用范围 for 循环。
// argv 的类型似乎被直接当作了 char **, 因此连 C++11 为数组开发的迭代器也用不了，只能用 argc 保证 argv 数组的使用不超界。
int main(int argc, char *argv[])
{
    string s;
    for (int i = 1; i != argc; ++i) // 在没有选项的时候 argc = 1, 因此 argc 至少是 1, 能保证不超界。
    {
        s = argv[i]; // C 风格字符串转化为 string 后更容易输出
        cout << s << endl;
    }
    return 0;
}