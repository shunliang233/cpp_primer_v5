// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp String.cpp ; ./main.out

#include <iostream>
#include <vector>
#include "String.hpp"
using std::cout;
using std::endl;
using std::vector;

// 到达 vector 的容量挪位置的时候，改用元素的移动构造函数
// 在 vector 整体挪位置的时候就不会拷贝元素
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