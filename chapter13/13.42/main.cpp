// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp TextQuery.cpp QueryResult.cpp StrVec.cpp ; ./main.out

#include <iostream>
#include <fstream>
#include "TextQuery.hpp"
#include "QueryResult.hpp"
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

// 2024-11-08 v3
// 将 vector<string> 改为自己定义的 StrVec, 直接就能用

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    ifstream file("data.txt");
    runQueries(file);
}