#ifndef DAOCOMMON_H
#define DAOCOMMON_H

#include <list>
#include <string>

namespace synopsis {

typedef std::list<std::string> TStrings;

struct SelectionOrder
{
    SelectionOrder()
        :m_bAscent(true)
    {
    }

    TStrings m_Columns;
    bool m_bAscent;
};

} // namespace synopsis

#endif // DAOCOMMON_H
