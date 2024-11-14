// Windows Powershell: g++ -std=c++11 -Wall 6.27.cpp -o 6.27.exe ; ./6.27.exe
// Mac Zsh: g++ -std=c++11 -Wall 6.27.cpp -o 6.27.out ; ./6.27.out

#include <iostream>
#include <initializer_list>
using std::cout;
using std::endl;
using std::initializer_list;

int sum(initializer_list<int> il)
{
    int result = 0;
    for (auto i : il)
    {
        result += i;
    }
    return result;
}

int main()
{
    cout << sum({1, 2, 3, 5, 6}) << endl;
    return 0;
}
