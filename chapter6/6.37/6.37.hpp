#pragma once
#include <string>
using std::string;

// 应该还是尾置返回类型最简单方便，只有这种类型要经常用时定义类型别名才比较好。

string (&arr(int i))[10]; // 直接声明返回类型
auto arr(int i) -> string(&)[10]; // 尾置返回类型

string s[10]; // 先声明一个 string 数组
decltype(s) &arr(int i); // 使用 decltype 关键字

using string_arr = string[10]; // 定义类型别名
string_arr &arr(int i); // 使用类型别名


