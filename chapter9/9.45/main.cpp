// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void PreSuf(string &name, const string &pre, const string &suf)
{
    name.insert(name.begin(), 1, ' ');
    name.insert(name.begin(), pre.begin(), pre.end());
    name.append(1, ' ');
    name.append(suf.begin(), suf.end());
}

int main()
{
    string name1 = "Yaxuan";
    PreSuf(name1, "Ms.", "III");
    cout << name1 << endl;

    string name2 = "Xining";
    PreSuf(name2, "Mr.", "Jr.");
    cout << name2 << endl;
}