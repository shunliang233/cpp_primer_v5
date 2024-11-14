#pragma once
#include <string>
#include <set>

class Folder;

class Message
{
    friend class Folder;
    friend void swap(Message &, Message &);

public:
    // 构造和析构
    explicit Message(const std::string &str = "") : contents(str) {}
    Message(const Message &);
    ~Message();

    // 运算符
    Message &operator=(const Message &);

    // 从给定 Folder 中添加或删除 this Message
    void save(Folder &);
    void remove(Folder &);

private:
    // 私有数据成员，存储实际的消息和 Message 所位于的 Folder 的集合
    std::string contents;
    std::set<Folder *> folders;

    // 拷贝控制函数使用的工具
    // 将 this Message 从所有 Folder 中删除，或添加到另一个 Message 位于的所有 Folder
    // 仅修改 Folder 对象，因此理论上可以是 const 函数
    // 但是 Folder 仅接受非 const this, 所以只能用非 const 函数
    void add_to_Folders(const Message &);
    void remove_from_Folders();
};