#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "TextQuery.hpp"

// QueryResult 类只需要保存访问索引需要用到的数据成员就行了
// 只有构造函数和数据成员（数据类？）
class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    // 只有 file 和 lines 这样内容可能很多的对象才会优化以避免拷贝
    // 对于单词 sought 就没必要进行拷贝优化了，可以减少代码的复杂程度
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<std::vector<std::string>> f)
        : sought(s), lines(p), file(f) {}

private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

// 相关函数的声明
// 有的编译器在类外面不声明友元函数也能通过，但最好还是声明一下
std::ostream &print(std::ostream &os, const QueryResult &qr);
std::string make_plural(size_t ctr, const std::string &word, const std::string &ending);