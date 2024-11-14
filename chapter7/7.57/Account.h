#pragma once
#include <string>
using std::string;

// 使用合成的默认构造函数
class Account
{
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void set_rate(double newRate) { interestRate = newRate; }

private:
    string owner;
    double amount = 0;
    static double interestRate;
    static double initRate() { return 0; };
};

// 定义静态成员变量
double Account::interestRate = initRate();