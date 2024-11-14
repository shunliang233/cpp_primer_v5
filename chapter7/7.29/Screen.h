#pragma once
#include <string>
using std::ostream;
using std::string;

class Screen
{
public:
    typedef string::size_type pos;

    // 构造函数
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    // 获取某处的字符
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }

    // 移动光标
    Screen move(pos r, pos c)
    {
        cursor = r * width + c;
        return *this;
    }

    // 设置某处的字符
    Screen set(char c)
    {
        contents[cursor] = c;
        return *this;
    }
    Screen set(pos row, pos col, char ch)
    {
        contents[row * width + col] = ch;
        return *this;
    }

    // 展示整个字符串
    Screen display(ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen display(ostream &os) const
    {
        do_display(os);
        return *this;
    }

private:
    void do_display(ostream &os) const { os << contents; }
    pos cursor = 0;
    pos height = 1, width = 1;
    string contents;
};
