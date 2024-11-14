// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <list>
#include <vector>
using std::cout;
using std::endl;
using std::list;
using std::vector;

int main()
{
    vector<int> vec = {1, 2, 0, 43, 0, 443, 42, 0, 65, 765};
    list<int> lst;
    for (auto it = vec.crbegin() + 2; it != vec.crend() - 3; ++it)
    {
        lst.push_back(*it);
    }

    for (auto i : lst)
    {
        cout << i << endl;
    }
}