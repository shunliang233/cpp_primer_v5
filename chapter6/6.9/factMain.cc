// macOS Zsh 分离式编译
// g++ -std=c++11 -Wall -c factMain.cc -o factMain.o
// g++ -std=c++11 -Wall -c fact.cc -o fact.o
// g++ -std=c++11 -Wall fact.o factMain.o -o main.out
// ./main.out

#include <iostream>
#include "Chapter6.h"
using std::cout;
using std::endl;

int main()
{
    cout << fact(5) << endl;
    return 0;
}