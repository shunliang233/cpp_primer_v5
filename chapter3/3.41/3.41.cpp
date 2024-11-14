// Windows Powershell: g++ -std=c++11 -Wall -o 3.41.exe 3.41.cpp ; ./3.41.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.41.out 3.41.cpp ; ./3.41.out

#include <iostream>
#include <vector>
#include <iterator>
using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::vector;

int main()
{
    int i[] = {0, 1, 2, 3, 4, 5};
    vector<int> vec(begin(i), end(i));

    for (auto a : vec)
        cout << a << endl;

    return 0;
}