// Windows Powershell: g++ -std=c++11 -Wall -o 1.9.exe 1.9.cpp ; ./1.9.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 1.9.out 1.9.cpp ; ./1.9.out
#include <iostream>

int main()
{
    int sum = 0, val = 50;
    while(val<=100)
    {
        sum+=val;
        val++;
    }
    std::cout << "Sum of 50 to 100 inclusive is: " << sum << std::endl;
    return 0;
}