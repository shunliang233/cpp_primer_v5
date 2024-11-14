// Windows Powershell: g++ -std=c++11 -Wall -o 3.43.exe 3.43.cpp ; ./3.43.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.43.out 3.43.cpp ; ./3.43.out

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

    // 范围 for 循环输出 ia 的元素
    for (const int(&row)[colCnt] : ia)
        for (int col : row)
            cout << col << ' ';
    cout << endl;

    // 下标运算符输出 ia 的元素（感觉这个最简单，只需要对 int 类型做循环）
    for (size_t row = 0; row != rowCnt; row++)
        for (size_t col = 0; col != colCnt; col++)
            cout << ia[row][col] << ' ';
    cout << endl;

    // 用指针输出 ia 的元素
    for (int(*row)[colCnt] = ia; row != ia + rowCnt; row++)
        for (int *col = *row; col != *row + colCnt; col++)
            cout << *col << ' ';
    cout << endl;

    return 0;
}
