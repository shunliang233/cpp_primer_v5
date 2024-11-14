#include "Folder.hpp"

void Folder::save(Message &m)
{
    messages.insert(&m);
    m.addFld(this);
}
void Folder::remove(Message &m)
{
    messages.erase(&m);
    m.remFld(this);
}