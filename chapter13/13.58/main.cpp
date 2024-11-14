// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp Foo_v1.cpp Foo_v2.cpp ; ./main.out

#include <iostream>
#include "Foo_v1.hpp"
#include "Foo_v2.hpp"
using std::cout;
using std::endl;

// 2024-11-10
// v1 会重复调用左值版本，有问题
// v2 的左值版本会调用右值版本，是正确的

int main()
{
    Foo_v1 v1;
    v1.sorted();

    cout << endl;

    Foo_v2 v2;
    v2.sorted();
}