// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <vector>
#include <iterator>
#include <list>
using std::cout;
using std::endl;
using std::list;
using std::vector;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> vec1;
    list<int> vec2;
    list<int> vec3;

    copy(vec.cbegin(), vec.cend(), inserter(vec1, vec1.begin()));
    for (auto i : vec1)
        cout << i << ' ';
    cout << endl;
    copy(vec.cbegin(), vec.cend(), back_inserter(vec2));
    for (auto i : vec2)
        cout << i << ' ';
    cout << endl;
    copy(vec.cbegin(), vec.cend(), front_inserter(vec3));
    for (auto i : vec3)
        cout << i << ' ';
    cout << endl;
}
