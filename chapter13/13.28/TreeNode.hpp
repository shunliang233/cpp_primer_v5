#include <string>

class TreeNode
{
public:
    // 默认构造函数，两个指针都指向栈内存，不需要手动释放内存
    TreeNode()
        : value(std::string()), count(0), left(this), right(this) {}
    // 拷贝构造函数，拷贝 string 和 int, 指针指向自己的栈内存
    TreeNode(const TreeNode &t)
        : value(t.value), count(t.count), left(this), right(this) {}
    // 拷贝赋值运算符
    TreeNode &operator=(const TreeNode &);

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

// 拷贝赋值运算符，不拷贝指针
TreeNode &TreeNode::operator=(const TreeNode &t)
{
    value = t.value;
    count = t.count;
}

