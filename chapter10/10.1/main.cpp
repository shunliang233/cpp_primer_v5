// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    const int val = 42;
    vector<int> vec = {1, 2, 42, 43, 6, 443, 42, 435, 65, 765, 8, 42};
    cout << count(vec.cbegin(), vec.cend(), val) << endl;
}