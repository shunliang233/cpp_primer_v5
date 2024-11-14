// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp String.cpp ; ./main.out

#include <iostream>
#include "String.hpp"
using std::cout;
using std::endl;

// 2024-11-08 v1
// 基本上 StrVec 中的东西都可以直接抄过来用
// 添加了一个接受 C 风格字符串的构造函数
// 指针改用类内初始值进行初始化，这样就不怕在新构造函数中忘记初始化了

int main()
{
    String s("abc");
}