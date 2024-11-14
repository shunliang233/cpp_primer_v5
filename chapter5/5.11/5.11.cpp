// Windows Powershell: g++ -std=c++11 -Wall -o 5.11.exe 5.11.cpp ; gc data.txt | ./5.11.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 5.11.out 5.11.cpp ; ./5.11.out < data.txt

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string tmp_string;
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, enterCnt = 0;

    // cin 会自动忽略空白，要想读入所有的空格和制表符，必须用 getline. 换行符的数目利用循环的次数得到。
    while (getline(cin, tmp_string))
    {
        ++enterCnt; // getline 读入一行就代表遇到了一个换行符
        for (auto ch : tmp_string)
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
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            }
        }
    }
    // 当最后一行不是空行时，行末遇到的实际上是文件结束符(eof), 而不是换行符，因此要减去。
    // 当最后一行是空行时（即换行符紧跟eof）, getline 函数读入的最后一行中只有 eof（将空串存入 tmp_string）, 因此函数返回值是 False, 不会执行最后一行的循环，就没有多算换行符的数目。
    if (!tmp_string.empty())
        --enterCnt;

    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << '\n'
         << "Number of space: \t" << spaceCnt << '\n'
         << "Number of tab: \t\t" << tabCnt << '\n'
         << "Number of enter: \t" << enterCnt << '\n';
    return 0;
}