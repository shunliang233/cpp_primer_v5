#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "TextQuery.hpp"
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
    string text;
    while (getline(is, text))
    {
        file->push_back(text);
        int n = file->size() - 1; // 当前行号
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