#pragma once

class NoDefault
{
public:
    NoDefault(int i) {} // 非默认构造函数
};

class C
{
public:
    C() : aaa(0){}; // 默认构造函数

private:
    NoDefault aaa;
};