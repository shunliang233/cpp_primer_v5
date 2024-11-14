// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <numeric>
#include "Sales_item.h"
using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;

bool compare(const Sales_item &s1, const Sales_item &s2)
{
    return s1.isbn() < s2.isbn();
}

int main()
{
    // 读取所有数据存入 vector
    ifstream file("book_sales.txt");
    istream_iterator<Sales_item> in(file), eof;
    vector<Sales_item> vec(in, eof);

    // 对 isbn 排序
    sort(vec.begin(), vec.end(), compare);

    // 叠加 isbn 相同的销售记录并输出
    auto it_begin = vec.begin(); // 用于存储一组相同 isbn 销售记录中的第一个
    auto it_end = vec.begin();   // 用于存储一组相同 isbn 销售记录中的最后一个的后面一个
    while (it_begin != vec.end())
    {
        it_end = find_if_not(it_begin, vec.end(), [it_begin](Sales_item s)
                             { return s.isbn() == it_begin->isbn(); });
        cout << accumulate(it_begin, it_end, Sales_item(it_begin->isbn())) << endl;
        it_begin = it_end;
    }
}