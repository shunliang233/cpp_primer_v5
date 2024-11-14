// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::vector;

void elimDups(vector<string> &words)
{
    for (auto i : words)
        cout << i << ' ';
    cout << endl;
    sort(words.begin(), words.end());
    for (auto i : words)
        cout << i << ' ';
    cout << endl;
    auto end_unique = unique(words.begin(), words.end());
    for (auto i : words)
        cout << i << ' ';
    cout << "(第 9 和 10 个 string 是存在的，就是不知道是啥)" << endl;
    words.erase(end_unique, words.end());
    for (auto i : words)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    istringstream is("the quick red fox jumps over the slow red turtle");
    vector<string> vec;
    string word;
    while (is >> word)
        vec.push_back(word);

    elimDups(vec);
}