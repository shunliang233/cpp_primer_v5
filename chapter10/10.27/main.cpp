// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <iterator>
using std::cout;
using std::endl;
using std::istringstream;
using std::list;
using std::string;
using std::vector;

int main()
{
    istringstream is("the quick red fox jumps over the slow red turtle");
    vector<string> vec;
    string word;
    while (is >> word)
        vec.push_back(word);

    // 用普通的迭代器的话，必须保证 lst 的长度足够，显然这个条件并不满足，因此只能使用插入迭代器。不用担心算法对迭代器的自增问题，插入迭代器不受自增运算的影响。
    list<string> lst;
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), back_inserter(lst));

    for (auto i : lst)
        cout << i << ' ';
    cout << endl;
}