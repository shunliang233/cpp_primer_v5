// Windows Powershell: g++ -std=c++11 -Wall -o 1.16.exe 1.16.cpp ; ./1.16.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 1.16.out 1.16.cpp ; ./1.16.out
#include <iostream>

int main()
{
    int sum = 0, val = 0;
    while (std::cin >> val)
    {
        sum += val;
    }
    std::cout << "Sum is: " << sum << std::endl;

    return 0;
}