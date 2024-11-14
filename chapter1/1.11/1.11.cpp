// Windows Powershell: g++ -std=c++11 -Wall -o 1.11.exe 1.11.cpp ; ./1.11.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 1.11.out 1.11.cpp ; ./1.11.out
#include <iostream>

int main()
{
    // 输入两个整数
    int a = 0, b = 0;
    std::cout << "Enter two integers: " << std::endl;
    std::cin >> a >> b;

    // 分出大小
    int min = 0, max = 0;
    if (a < b)
    {
        min = a;
        max = b;
    }
    else
    {
        min = b;
        max = a;
    }

    // 输出这两个数中间的所有整数
    while (min <= max)
    {
        std::cout << min << " ";
        min++;
    }
    std::cout << std::endl;
    return 0;
}