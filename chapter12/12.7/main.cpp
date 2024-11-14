// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <vector>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::make_shared;
using std::shared_ptr;
using std::vector;

shared_ptr<vector<int>> a()
{
    auto vec = make_shared<vector<int>>();
    return vec;
}

shared_ptr<vector<int>> b(istream &input, shared_ptr<vector<int>> vec)
{
    int i = 0;
    while (input >> i)
    {
        vec->push_back(i);
    }
    return vec;
}

void c(shared_ptr<vector<int>> vec)
{
    for (auto i : *vec)
    {
        cout << i << ' ';
    }
    cout << endl;
}

int main()
{
    ifstream file("data.txt");
    c(b(file, a()));
}