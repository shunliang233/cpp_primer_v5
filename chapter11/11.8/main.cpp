// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <vector>
#include <set>
using std::cout;
using std::endl;
using std::set;
using std::vector;

int main()
{
    // 一个有重复元素的 vector
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i)
    {
        ivec.push_back(i);
        ivec.push_back(i);
    }

    // 用 set 保存不重复的单词
    set<int> iset(ivec.cbegin(), ivec.cend());
    cout << iset.size() << endl;

    // 用 vector 保存不重复的单词
    vector<int> vec1(ivec.cbegin(), ivec.cend());
    auto end_unique = unique(vec1.begin(), vec1.end());
    vec1.erase(end_unique, vec1.end());
    cout << vec1.size() << endl;
}