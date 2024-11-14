// Windows Powershell: g++ -std=c++11 -Wall -o 5.10.exe 5.10.cpp ; gc data.txt | ./5.10.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 5.10.out 5.10.cpp ; ./5.10.out < data.txt

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
        switch (ch)
        {
        case 'a':
        case 'A':
            ++aCnt;
            break;
        case 'e':
        case 'E':
            ++eCnt;
            break;
        case 'i':
        case 'I':
            ++iCnt;
            break;
        case 'o':
        case 'O':
            ++oCnt;
            break;
        case 'u':
        case 'U':
            ++uCnt;
            break;
        }
    }

    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << '\n';
    return 0;
}