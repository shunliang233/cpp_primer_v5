// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include "HasPtr_v6.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::sort;
using std::vector;

int main()
{
    // 调用 HasPtr 的默认构造函数和拷贝构造函数
    vector<HasPtr> vec = {HasPtr("aaa"), HasPtr("ccc"), HasPtr("bbb")};

    // sort algorithm
    sort(vec.begin(), vec.end());
}
