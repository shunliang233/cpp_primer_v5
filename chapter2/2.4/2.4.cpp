// Windows Powershell: g++ -std=c++11 -Wall -o 2.4.exe 2.4.cpp ; ./2.4.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 2.4.out 2.4.cpp ; ./2.4.out
#include <iostream>

int main()
{
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;
}