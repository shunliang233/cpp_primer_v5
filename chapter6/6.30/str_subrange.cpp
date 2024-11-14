// Mac Zsh: g++ -std=c++11 -Wall -c str_subrange.cpp -o str_subrange.o

#include <string>
using std::string;

// 这个函数有两个错误，下面描述的是 macOS 的 Apple clang version 14.0.0 编译器的表现
// 可能没有返回值: error: non-void function 'str_subrange' should return a value
// 可能没有 return 语句: warning: non-void function does not return a value in all control paths

bool str_subrange(const string &str1, const string &str2)
{
    if (str1.size() == str2.size())
        return str1 == str2;

    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

    for (decltype(size) i = 0; i != size; ++i)
    {
        if (str1[i] != str2[i])
            return;
    }
}