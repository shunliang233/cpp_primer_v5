// Windows Powershell: g++ -std=c++11 -Wall -o 6.25.exe 6.25.cpp ; ./6.25.exe string1 string2
// Mac Zsh: g++ -std=c++11 -Wall -o 6.25.out 6.25.cpp ; ./6.25.out string1 string2

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// argv[1] 和 argv[2] 是 C 风格字符串，本质上是数组
// C 风格字符串不能直接相加，但可以与 string 相加，并且可以赋值给 string.
int main(int argc, char *argv[])
{
    string s = argv[1];
    s += argv[2]; // 避免两个 C 风格字符串相加
    cout << s << endl;
    return 0;
}