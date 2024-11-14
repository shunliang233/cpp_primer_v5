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
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    istringstream is("the quick red fox jumps over the slow red turtle");
    vector<string> vec;
    string word;
    while (is >> word)
        vec.push_back(word);
    elimDups(vec);
    stable_sort(vec.begin(), vec.end(), isShorter);

    for (auto i : vec)
        cout << i << ' ';
    cout << endl;
}