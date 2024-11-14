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

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, string::size_type sz)
{
    // 主要按长度顺序，次要按字典顺序，删除重复元素
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
                { return a.size() < b.size(); });

    // 找到满足长度的第一个元素，输出满足长度的元素数，并打印每个满足长度的元素
    auto wc = stable_partition(words.begin(), words.end(), [sz](const string &a)
                        { return a.size() < sz; });
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer." << endl;
    for_each(wc, words.end(), [](const string &s)
             { cout << s << ' '; });
    cout << endl;
}

int main()
{
    istringstream is("the quick red fox jumps over the slow red turtle");
    vector<string> vec;
    string word;
    while (is >> word)
        vec.push_back(word);

    biggies(vec, 5);
}