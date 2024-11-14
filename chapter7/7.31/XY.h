#pragma once

// 类的声明
class X;
class Y;

// 先定义 X 类
class X
{
    Y *ptr;
};

// 再定义 Y 类
class Y
{
    X obj;
};