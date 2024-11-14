// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <iterator>
using std::cout;
using std::endl;
using std::istream_iterator;
using std::istringstream;
using std::list;
using std::string;

void elimDups(list<string> &words)
{
    words.sort();
    words.unique();
}

int main()
{
    istringstream is("the quick red fox jumps over the slow red turtle");
    istream_iterator<string> is_it(is), eof;
    list<string> lst(is_it, eof);

    elimDups(lst);
    for (auto i : lst)
    {
        cout << i << endl;
    }
}