// Windows Powershell: g++ -std=c++11 -Wall -o 5.14.exe 5.14.cpp ; gc data.txt | ./5.14.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 5.14.out 5.14.cpp ; ./5.14.out < data.txt

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    unsigned maxCnt = 0;
    string max_word;
    unsigned currentCnt = 0;
    string current_word;
    string next_word;

    while (cin >> next_word)
    {
        if (next_word != current_word)
        {
            if (currentCnt > maxCnt)
            {
                maxCnt = currentCnt;
                max_word = current_word;
            }
            current_word = next_word;
            currentCnt = 1;
        }
        else
            ++currentCnt;
    }
    // 循环结束后还要判断最后一组连续单词出现的次数是不是最多的
    if (currentCnt > maxCnt)
    {
        maxCnt = currentCnt;
        max_word = current_word;
    }

    if (maxCnt > 1)
        cout << "Word \"" << max_word << "\" appears " << maxCnt << " times." << endl;
    else
        cout << "No word continuously appears." << endl;
    return 0;
}