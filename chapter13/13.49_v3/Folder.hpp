#pragma once
#include <set>
#include "Message.hpp"

class Folder
{
    friend class Message;
    friend void swap(Message &, Message &);

public:
    // 默认构造函数
    Folder() = default;

    // 从 Folder 中添加或删除给定 Message
    void save(Message &);
    void remove(Message &);

private:
    // 私有数据成员
    std::set<Message *> messages;

    // 在 Folder::messages 中添加或删除 Message
    // 不会操作 Message 中的 set, 直接调用会导致矛盾，因此只能给友元使用
    void addMsg(Message *m) { messages.insert(m); }
    void remMsg(Message *m) { messages.erase(m); }
};