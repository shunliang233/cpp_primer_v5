// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp String.cpp ; ./main.out

#include <iostream>
#include <vector>
#include "String.hpp"
using std::cout;
using std::endl;
using std::vector;

// 拷贝次数比 push_back 次数多
// 是因为每次到达 vector 的容量极限就需要挪位置，要把现有的所有元素都拷贝一遍
// 如果改用元素的移动构造函数，会节省计算资源
int main()
{
    vector<String> vec1;
    vector<String> vec2;
    vector<String> vec3;
    vector<String> vec4;
    String s("abc");
    vec1.push_back(s);
    cout << endl;
    vec2.push_back(s);
    vec2.push_back(s);
    cout << endl;
    vec3.push_back(s);
    vec3.push_back(s);
    vec3.push_back(s);
    cout << endl;
    vec4.push_back(s);
    vec4.push_back(s);
    vec4.push_back(s);
    vec4.push_back(s);
}