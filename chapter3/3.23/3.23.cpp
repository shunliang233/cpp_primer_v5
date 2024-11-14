// Windows Powershell: g++ -std=c++11 -Wall -o 3.23.exe 3.23.cpp ; ./3.23.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.23.out 3.23.cpp ; ./3.23.out

#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> vec;
    for (int i = 0; i != 10; i++)
        vec.push_back(i);

    for (auto it = vec.begin(); it != vec.end(); it++)
        (*it) *= 2;

    for (auto i : vec)
        cout << i << ' ';
    cout << endl;

    return 0;
}