// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <list>
#include <vector>
#include <string>
using std::list;
using std::string;
using std::vector;

int main()
{
    list<const char *> c1 = {"a", "an", "the"};
    vector<string> c2(c1.cbegin(), c1.cend());
}