#include<vector>
using std::vector;

// 函数声明
int func(int, int);

// i 矢量中的元素类型是指向 func 函数类型的指针，并且第一个元素的初始值就是指向 func 函数的指针
vector<decltype(func) *> i = {&func};