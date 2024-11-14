// Windows Powershell: g++ -std=c++11 -Wall -o 3.35.exe 3.35.cpp ; ./3.35.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.35.out 3.35.cpp ; ./3.35.out

#include <iostream>
#include <cstddef>
#include <iterator>
using std::begin;
using std::cout;
using std::end;
using std::endl;

int main()
{
    const size_t array_size = 10;
    int ia[array_size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int *p = begin(ia); p != end(ia); p++)
        *p = 0;

    for (auto i : ia)
        cout << i << endl;

    return 0;
}