// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp StrVec.cpp ; ./main.out

#include <iostream>
#include "StrVec.hpp"

// 2024-11-08 v3
// 重写 StrVec::free 函数的实现
// 将内存对象的 destroy 改为从前往后了，不如原来的从后往前和 vector 一样

int main() {}