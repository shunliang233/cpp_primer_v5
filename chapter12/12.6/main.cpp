// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <vector>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::vector;

vector<int> *a()
{
    auto vec = new vector<int>;
    return vec;
}

vector<int> *b(istream &input, vector<int> *vec)
{
    int i = 0;
    while (input >> i)
    {
        vec->push_back(i);
    }
    return vec;
}

// 这个函数有点猛，人家给你一个 vector 让你输出，你输出完就直接删掉
// 要是外面还有指针指向这个 vector, 那些指针也用不了了
void c(vector<int> *vec)
{
    for (auto i : *vec)
    {
        cout << i << ' ';
    }
    cout << endl;
    delete vec;
}

int main()
{
    ifstream file("data.txt");
    c(b(file, a()));
}