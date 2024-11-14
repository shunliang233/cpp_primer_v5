// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Sales_data.h"
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

bool compareIsbn(const Sales_data &s1, const Sales_data &s2)
{
    return s1.isbn() < s2.isbn();
}

int main()
{
    // 将文件中的数据导入 vector<Sales_data>
    ifstream file("data.txt");
    vector<Sales_data> sales;
    string line;
    while (getline(file, line))
    {
        istringstream sline(line);
        sales.emplace_back(sline);
    }

    // 输出排序前的 isbn
    for (auto i : sales)
        cout << i.isbn() << ' ';
    cout << endl;

    // 按照 compareIsbn 谓词排序
    sort(sales.begin(),sales.end(), compareIsbn);

    // 输出排序后的 isbn
    for (auto i : sales)
        cout << i.isbn() << ' ';
    cout << endl;
}