// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;

int main()
{
    list<int> vec = {1, 2, 0, 43, 0, 443, 42, 0, 65, 765, 0, 42};
    auto it = find(vec.crbegin(), vec.crend(), 0);
    cout << *it << endl;
    cout << *++it << endl;
}