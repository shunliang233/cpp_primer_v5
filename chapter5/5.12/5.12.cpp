// Windows Powershell: g++ -std=c++11 -Wall -o 5.12.exe 5.12.cpp ; gc data.txt | ./5.12.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 5.12.out 5.12.cpp ; ./5.12.out < data.txt

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string tmp_string;
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;

    // 得把空白也一起读入，不然的话对于 "f f" 这样的字符串片段也会使计数增加。
    while (getline(cin, tmp_string))
    {
        // ATTENTION: for 循环的条件必须加上 it != tmp_string.end() 来排除空串，光用 it != tmp_string.end() - 1 是没法排除空串的。
        for (auto it = tmp_string.begin(); it != tmp_string.end() && it != tmp_string.end() - 1; ++it)
        {
            switch (*it)
            {
            case 'f':
                switch (*(it + 1))
                {
                case 'f':
                    ++ffCnt;
                    break;
                case 'l':
                    ++flCnt;
                    break;
                case 'i':
                    ++fiCnt;
                    break;
                }
                break;
            }
        }
    }

    cout << "Number of \"ff\": \t" << ffCnt << '\n'
         << "Number of \"fl\": \t" << flCnt << '\n'
         << "Number of \"fi\": \t" << fiCnt << '\n';
    return 0;
}