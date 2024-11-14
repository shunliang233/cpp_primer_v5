#pragma once
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
using std::ifstream;
using std::map;
using std::shared_ptr;
using std::string;
using std::vector;
using std::set;

class QueryResult;

class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &);
    QueryResult query(const string &) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};