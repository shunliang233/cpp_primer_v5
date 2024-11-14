#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "TextQuery.hpp"
#include "QueryResult.hpp"
using std::ifstream;
using std::istringstream;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

// 在构造函数中就已经对整个 text 完成了索引 map 的生成
TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
    string text;
    while (getline(is, text))
    {
        file->push_back(text);
        line_no n = file->size() - 1; // 当前行号从 0 开始
        istringstream line(text);
        string word;
        while (line >> word)
        {
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

// 生成索引结果，并存储到 QueryResult 对象中
QueryResult TextQuery::query(const string &sought) const
{
    // 用于在 text 中没找到单词时返回一个指向空 set 的指针
    // 静态对象只在函数第一次调用时初始化（类中的静态成员就必须在类外部初始化）
    static shared_ptr<set<TextQuery::line_no>> nodata(new set<TextQuery::line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}