// Windows Powershell: g++ -std=c++11 -Wall -o 3.31.exe 3.31.cpp ; ./3.31.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.31.out 3.31.cpp ; ./3.31.out

#include <iostream>
#include <cstddef>
using std::cout;
using std::endl;

int main()
{
    const size_t array_size = 10;
    int ia[array_size] = {};
    for (int i = 0; i != array_size; i++)
        ia[i] = i;
    for (auto i : ia)
        cout << i << endl;
    return 0;
}