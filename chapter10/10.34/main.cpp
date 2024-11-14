// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec = {1, 2, 42, 43, 6, 443, 42, 435, 65, 765, 8, 42};
    for (auto it = vec.crbegin(); it != vec.crend(); ++it)
    {
        cout << *it << endl;
    }
}