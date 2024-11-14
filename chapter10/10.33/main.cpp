// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe int.txt odd.txt even.txt
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out int.txt odd.txt even.txt

#include <iostream>
#include <iterator>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::ofstream;
using std::ostream_iterator;

int main(int argc, char **argv)
{
    // 读取文件和输出文件，以及绑定的流迭代器
    ifstream int_file(argv[1]);
    istream_iterator<int> int_is(int_file), eof;
    ofstream odd_file(argv[2]);
    ostream_iterator<int> odd_os(odd_file, " ");
    ofstream even_file(argv[3]);
    ostream_iterator<int> even_os(even_file, "\n");

    while (int_is != eof)
    {
        if (*int_is % 2 == 1)
            *odd_os++ = *int_is++;
        else
            *even_os++ = *int_is++;
    }
}