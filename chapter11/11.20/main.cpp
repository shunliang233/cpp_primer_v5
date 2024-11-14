// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::set;
using std::string;

int main()
{
    ifstream file("data.txt");
    map<string, size_t> word_count;
    set<char> punctuation = {',', '.'};
    string word;
    while (file >> word)
    {
        // 转化为小写
        for (auto &i : word)
            i = tolower(i);
        // 末尾有标点的话要删除
        if (punctuation.find(word[word.size() - 1]) != punctuation.end())
        {
            word.erase(word.size() - 1);
        }
        // 最后再添加到 map 中，不如 11.4 中用下标添加来的简单明了，主要是 insert 容易插入失败，检测到失败后还要手动将值自增
        auto ret = word_count.insert({word, 1});
        if (!ret.second)
            ++ret.first->second;
    }

    for (const auto &w : word_count)
    {
        cout << "\"" << w.first << "\""
             << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }
}