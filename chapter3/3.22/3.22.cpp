// Windows Powershell: g++ -std=c++11 -Wall -o 3.22.exe 3.22.cpp ; gc data.txt | ./3.22.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.22.out 3.22.cpp ; ./3.22.out < data.txt
// 判断 vector 是否准确无误: ./3.22.out < data.txt > check.txt ; diff data.txt check.txt

#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    // 读入 LaTeX 文本，存入字符串 vector 中，每个字符串存一句话或空行。
    string word;                  // 临时存放单词
    string sentence;              // 临时存放句子
    string paragraph;             // 临时存放段落
    vector<string> text_sentence; // 存放整个文本的 vector
    while (getline(cin, paragraph))
    {
        if (!paragraph.empty()) // 空行会被 getline 读取为空字符串
        {
            for (auto it = paragraph.begin(); it != paragraph.end(); ++it) // 循环处理每一个字符
            {
                // ATTENTION: 绝对不能用 ++it 代替 (it+1), 因为 ++it 相当于 it=it+1, 这打乱了 for 循环一轮只加一次的节奏。
                // 并且下面再用到 it 时可能会超范围，导致编译通过但运行失败。
                if (*it != ' ' && (it + 1) != paragraph.end()) // 单词没结束
                    word += *it;
                else // 单词结束
                {
                    if (*(word.end() - 1) == '.' && word != "i.e." && word != "e.g.") // 句子结束
                    {
                        sentence += word;
                        text_sentence.push_back(sentence);
                        sentence = "";
                    }
                    else if ((it + 1) == paragraph.end()) // 段落结束
                    {
                        word += *it;
                        sentence += word;
                        text_sentence.push_back(sentence);
                        sentence = "";
                    }
                    else // 句子没结束
                        sentence += (word + ' ');
                    word = "";
                }
            }
        }
        else
            text_sentence.push_back(paragraph);
    }
    // 临时量用完最好确保归零
    word = "";
    sentence = "";
    paragraph = "";

    // // 用于给 Linux 的 diff 程序检验 vector 是否准确无误。取消注释后可以得到与输入内容完全一样的文本。
    // for (auto s = text_sentence.begin(); s != text_sentence.end(); ++s)
    // {
    //     // ATTENTION: 在 *(s+1) 取迭代器所指元素值之前得先确保迭代器没有超范围
    //     if (!(*s).empty() && (s + 1) != text_sentence.end() && !(*(s + 1)).empty()) // 是句子，不是文章的最后一句，不是段落的最后一句
    //         cout << *s << ' ';
    //     else if (!(*s).empty() && (s + 1) != text_sentence.end() && (*(s + 1)).empty()) // 是句子，不是文章的最后一句，是段落的最后一句
    //         cout << *s << endl;
    //     else if ((*s).empty()) // 是空行
    //         cout << endl;
    //     else if ((s + 1) == text_sentence.end()) // 是文章的最后一句
    //         cout << *s;
    // }

    // 把 text_sentence 的第一段全部改为大写，再输出
    for (auto it = text_sentence.begin(); it != text_sentence.end() && !it->empty(); ++it)
    {
        for (auto &i : *it)
        {
            i = toupper(i);
        }
        cout << *it << endl;
    }

    return 0;
}
