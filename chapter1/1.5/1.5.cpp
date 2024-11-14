// Windows Powershell: g++ -std=c++11 -Wall -o 1.5.exe 1.5.cpp ; ./1.5.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 1.5.out 1.5.cpp ; ./1.5.out
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The multiplication of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
    return 0;
}