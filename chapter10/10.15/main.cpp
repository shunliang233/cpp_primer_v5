// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
using std::cout;
using std::endl;



int main()
{
    int i = 8;
    auto f = [i](int j)
    { return i + j; };

    cout << f(6) << endl;
}