// Windows Powershell: g++ -std=c++11 -Wall -o 1.4.exe 1.4.cpp ; ./1.4.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 1.4.out 1.4.cpp ; ./1.4.out
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The multiplication of " << v1 << " and " << v2 << " is " << v1 * v2 << std::endl;
    return 0;
}