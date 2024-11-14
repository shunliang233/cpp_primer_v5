// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::vector;
using namespace std::placeholders;

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

bool compare(const string &a, const string &b) { return a.size() < b.size(); }

bool threshold(const string &a, size_t sz) { return a.size() < sz; }

void print(const string &s) { cout << s << ' '; }

void biggies(vector<string> &words, string::size_type sz)
{
    // 主要按长度顺序，次要按字典顺序，删除重复元素
    elimDups(words);
    stable_sort(words.begin(), words.end(), compare);

    // 找到满足长度的第一个元素，输出满足长度的元素数，并打印每个满足长度的元素
    auto wc = stable_partition(words.begin(), words.end(), bind(threshold, _1, sz));
    auto count = words.size() - count_if(words.begin(), words.end(), bind(threshold, _1, sz));
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer." << endl;
    for_each(wc, words.end(), print);
    cout << endl;
}

int main()
{
    istringstream is("the quick red fox jumps over the slow red turtle");
    vector<string> vec;
    string word;
    while (is >> word)
        vec.push_back(word);

    biggies(vec, 6);
}