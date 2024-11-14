// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <string>
#include <map>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::string;

int main()
{
    ifstream file("data.txt");
    map<string, size_t> word_count;
    string word;
    while (file >> word)
    {
        ++word_count[word];
    }

    for (const auto &w : word_count)
    {
        cout << "\"" << w.first << "\"" << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }
}