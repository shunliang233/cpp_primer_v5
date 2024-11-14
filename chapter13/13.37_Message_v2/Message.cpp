#include "Message.hpp"
#include "Folder.hpp"

// 向给定 Folder 中添加 this Message
void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}
// 从给定 Folder 中添加 this Message
void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

// 将 this Message 添加到 m 位于的所有 Folder 中
void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}
// 从所有 Folder 中删除 this Message
void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

// 拷贝构造函数
Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}
// 析构函数
Message::~Message()
{
    remove_from_Folders();
}
// 拷贝赋值运算符
Message &Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

// 专门交换 Message 的 swap 函数
void swap(Message &lhs, Message &rhs)
{
    using std::swap;

    // 将 Folder 里面指向这两个 Message 的指针删干净
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);

    // 交换 Message 中的数据成员
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);

    // 给对应的 Folder 添加这两个 Message 的指针
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}