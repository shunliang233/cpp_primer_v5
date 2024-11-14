#include <set>
#include <string>
#include "TextQuery.hpp"
#include "QueryResult.hpp"
using std::set;
using std::shared_ptr;
using std::string;

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<TextQuery::line_no>> nodata(new set<TextQuery::line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}