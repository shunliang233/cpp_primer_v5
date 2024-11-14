#pragma once
#include "StrVec.hpp"
#include <string>
#include <map>
#include <set>
#include <fstream>

class QueryResult;

class TextQuery
{
public:
    using line_no = size_t;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;

private:
    std::shared_ptr<StrVec> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};