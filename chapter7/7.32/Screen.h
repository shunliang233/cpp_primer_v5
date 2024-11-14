#pragma once
#include <string>
#include <vector>
using std::ostream;
using std::string;
using std::vector;

// 先声明 Screen 类，才能在 Window_mgr 类的定义中使用这个类
class Screen;

// 定义 Window_mgr 类，只能使用 Screen 类本身，不能使用 Screen 类中的任何内容
class Window_mgr
{
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex); // 还不能定义函数，因为还没定义 Screen 类，不能使用 Screen 成员
    Window_mgr();            // 默认构造函数声明，还不能定义构造函数，因为没法使用 Screen(24,80,' ') 进行构造

private:
    vector<Screen> screens; // 不能用 Screen(24,80,' ') 对数据成员进行类内初始化，因为 Screen 的构造函数还没有定义
};

// 定义 Screen 类
class Screen
{
    // 成员函数友元声明之前需要先定义 Window_mgr 类
    friend void Window_mgr::clear(ScreenIndex);

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
    Screen &move(pos r, pos c)
    {
        cursor = r * width + c;
        return *this;
    }

    // 设置某处的字符
    Screen &set(char c)
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
    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(ostream &os) const
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

// 定义 Window_mgr::Window_mgr 默认构造函数，此时 Screen 类中的成员已经完整定义了，因此可以用 Screen 构造函数
Window_mgr::Window_mgr()
{
    screens = {Screen(24, 80, ' ')}; // 列表拷贝，见 P91 的表 3.5
}

// 定义 Window_mgr::clear 函数，由于已经声明为了 Screen 的友元函数，因此可以使用 Screen 中的 private 成员
void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i]; // 先把要修改的 Screen 对象引用出来，这样简洁一些
    s.contents = string(s.height * s.width, ' ');
}