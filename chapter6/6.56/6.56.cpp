// Windows Powershell: g++ -std=c++11 -Wall 6.56.cpp -o 6.56.exe ; ./6.56.exe
// Mac Zsh: g++ -std=c++11 -Wall 6.56.cpp -o 6.56.out ; ./6.56.out

#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

// 函数声明
int func1(int i, int j) { return i + j; }
int func2(int i, int j) { return i - j; }
int func3(int i, int j) { return i * j; }
int func4(int i, int j) { return i / j; }

// 输出的地址全是 1, 网上有人也是这个结果，他用类的概念解释了一通，我看不大懂
// https://blog.csdn.net/Q_1849805767/article/details/107391572
int main()
{
    // vector 中的元素是指向上述函数的指针
    vector<decltype(func1) *> vec = {&func1, &func2, &func3, &func4};

    for (auto i : vec)
    {
        cout << i << endl;
    }
}