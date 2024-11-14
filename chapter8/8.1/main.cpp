#include <iostream>
#include <string>
using std::cout;
using std::istream;
using std::string;

istream &read(istream &is)
{
    while (!is.eof())
    {
        string word;
        is >> word;
        cout << word;
    }

    is.clear(is.rdstate() & ~is.eofbit);
    return is;
}