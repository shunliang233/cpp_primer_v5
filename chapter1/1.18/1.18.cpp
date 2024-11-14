// Windows Powershell: g++ -std=c++11 -Wall -o 1.18.exe 1.18.cpp ; ./1.18.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 1.18.out 1.18.cpp ; ./1.18.out
#include <iostream>
int main()
{
    int currVal = 0; // 正在统计连续个数的数
    int val = 0;     // 新读入的数，判断是否与 currVal 一样，一样的话统计加 1

    // 确保有数据可以处理时才运行程序
    if (std::cin >> currVal)
    {
        int cnt = 1;            // 统计的个数
        while (std::cin >> val) // 读入一个新的数
        {
            if (val == currVal)
            {
                cnt++;
            }
            else
            {
                std::cout << currVal << " occurs " << cnt << " times" << std::endl;
                currVal = val; // 重置 currVal
                cnt = 1;       // 重置 cnt
            }
        }
        std::cout << currVal << " occurs " << cnt << " times" << std::endl; // 最后一个 cnt 在 while 循环中没有输出
    }
    return 0;
}