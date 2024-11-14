#include <fstream>
#include <string>
#include "TextQuery.hpp"
#include "function_head.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}