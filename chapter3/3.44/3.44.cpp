// Windows Powershell: g++ -std=c++11 -Wall -o 3.44.exe 3.44.cpp ; ./3.44.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.44.out 3.44.cpp ; ./3.44.out

#include <iostream>
#include <cstddef>
using std::cout;
using std::endl;

int main()
{
    // 初始化 ia
    constexpr int rowCnt = 3;
    constexpr int colCnt = 4;
    int ia[rowCnt][colCnt] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};

    // 定义类型别名（typedef 和 using 两种方法都可以）
    // typedef const int(&range_for)[colCnt];
    // typedef int(*int_array)[colCnt];
    // typedef int *int_point;
    using range_for = const int(&)[colCnt];
    using int_array = int(*)[colCnt];
    using int_point = int *;

    // 范围 for 循环输出 ia 的元素
    for (range_for row : ia)
        for (int col : row)
            cout << col << ' ';
    cout << endl;

    // 下标运算符输出 ia 的元素（感觉这个最简单，只需要对 int 类型做循环）
    for (size_t row = 0; row != rowCnt; row++)
        for (size_t col = 0; col != colCnt; col++)
            cout << ia[row][col] << ' ';
    cout << endl;

    // 用指针输出 ia 的元素
    for (int_array row = ia; row != ia + rowCnt; row++)
        for (int_point col = *row; col != *row + colCnt; col++)
            cout << *col << ' ';
    cout << endl;

    return 0;
}
