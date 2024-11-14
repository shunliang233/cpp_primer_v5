#include <iostream>
#include "QueryResult.hpp"
#include "function_head.hpp"
using std::endl;
using std::ostream;

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    return os;
}