#pragma once
#include <string>
using std::string;

class Screen
{
public:
    typedef string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }
    Screen &move(pos r, pos c)
    {
        cursor = r * width + c;
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 1, width = 1;
    string contents;
};
