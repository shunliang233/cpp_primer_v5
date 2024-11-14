// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int i = 32;
    auto a = [&i]() mutable -> bool
    {
        if (i != 0)
        {
            --i;
            return false;
        }
        else
            return true;
    };

    while (i != 0)
    {
        cout << i << ", " << a() << endl;
    }
    cout << i << ", " << a() << endl;
}