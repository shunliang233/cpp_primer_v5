#include "TreeNode.hpp"

class BinStrTree
{
public:
    BinStrTree() : root(new TreeNode) {} // 默认构造函数
    BinStrTree(const BinStrTree &b)
        : root(new TreeNode(*b.root)) {}       // 拷贝构造函数
    BinStrTree &operator=(const BinStrTree &); // 拷贝赋值运算符
    ~BinStrTree() { delete root; }             // 析构函数

private:
    TreeNode *root;
};

// 拷贝赋值运算符
BinStrTree &BinStrTree::operator=(const BinStrTree &b)
{
    auto newp = new TreeNode(*b.root);
    delete root;
    root = newp;
    return *this;
}