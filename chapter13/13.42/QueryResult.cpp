#include <iostream>
#include "QueryResult.hpp"
using std::endl;
using std::ostream;
using std::string;
using std::size_t;

// 在输出流 os 上打印 QueryRequest 查询结果
ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    return os;
}

// 根据数量返回单词的单数或复数形式
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}