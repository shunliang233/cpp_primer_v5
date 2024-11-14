// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; gc data.txt | ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out < data.txt

#include <iostream>
#include <vector>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;

// 使用流迭代器可以使代码长度大大缩短
int main()
{
    // 读取
    istream_iterator<int> in(cin), eof;
    vector<int> vec(in, eof);

    // 排序
    sort(vec.begin(), vec.end());

    // 输出
    ostream_iterator<int> out(cout, " ");
    copy(vec.cbegin(), vec.cend(), out);
    cout << endl;
}