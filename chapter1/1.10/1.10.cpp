// Windows Powershell: g++ -std=c++11 -Wall -o 1.10.exe 1.10.cpp ; ./1.10.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 1.10.out 1.10.cpp ; ./1.10.out
#include <iostream>

int main()
{
    int val = 10;
    while (val >= 0)
    {
        std::cout << val << " ";
        val--;
    }
    std::cout << std::endl;
    return 0;
}