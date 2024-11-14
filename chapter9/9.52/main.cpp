// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <stack>
#include <string>

// 从 Copilot 抄的，没有仔细看
// 仅能处理加减乘除运算
// 仅能处理数字 0 到 9
// 如果是 Python 的话，只需要用 eval 函数就行了
// 在 C++ 中想要节省人力的话，可以用 ofstream 创建一个 .cpp 文件，
// 然后写基本的 main 函数，再写入表达式，运行这个 .cpp 文件，
// 或者在 C++ 中调用 Python 来运算。
// 只是这样可能比较浪费算力 

// 函数：获取运算符优先级
int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// 函数：将中缀表达式转换为后缀表达式
// 后缀表达式将运算符放在操作数后面，不需要括号来改变运算顺序。
// 从左到右扫描表达式，遇到运算符时，取出前两个操作数进行计算，然后将结果放回操作数序列中。
// 计算器更适合使用后缀表达式进行计算，而人类更适合用中缀表达式。
std::string infixToPostfix(const std::string &infix)
{
    std::stack<char> s; // 栈用来暂存运算符和括号
    std::string postfix;
    for (char ch : infix)
    {
        if (std::isdigit(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // 弹出 '('
        }
        else
        {
            while (!s.empty() && getPrecedence(s.top()) >= getPrecedence(ch))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// 函数：计算后缀表达式
int evaluatePostfix(const std::string &postfix)
{
    std::stack<int> s;
    for (char ch : postfix)
    {
        if (std::isdigit(ch))
        {
            s.push(ch - '0');
        }
        else
        {
            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();
            switch (ch)
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    std::string infix = "3+(2*2)";
    std::string postfix = infixToPostfix(infix);
    std::cout << "Postfix: " << postfix << std::endl;
    std::cout << "Result: " << evaluatePostfix(postfix) << std::endl;
    return 0;
}