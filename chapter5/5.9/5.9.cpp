// Windows Powershell: g++ -std=c++11 -Wall -o 5.9.exe 5.9.cpp ; gc data.txt | ./5.9.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 5.9.out 5.9.cpp ; ./5.9.out < data.txt

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    char ch = ' ';
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

    while (cin >> ch)
    {
        if (ch == 'a')
            ++aCnt;
        else if (ch == 'e')
            ++eCnt;
        else if (ch == 'i')
            ++iCnt;
        else if (ch == 'o')
            ++oCnt;
        else if (ch == 'u')
            ++uCnt;
    }

    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << '\n';
    return 0;
}