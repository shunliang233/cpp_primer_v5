#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "TextQuery.hpp"
using std::ostream;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

class QueryResult
{
    friend ostream &print(ostream &, const QueryResult &);

public:
    QueryResult(string s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) {}

private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<vector<string>> file;
};