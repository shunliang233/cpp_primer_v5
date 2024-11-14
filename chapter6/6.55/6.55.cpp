#include <vector>
using std::vector;

// 函数声明
int func1(int i, int j) { return i + j; }
int func2(int i, int j) { return i - j; }
int func3(int i, int j) { return i * j; }
int func4(int i, int j) { return i / j; }

// vector 中的元素是指向上述函数的指针
vector<decltype(func1) *> i = {&func1, &func2, &func3, &func4};