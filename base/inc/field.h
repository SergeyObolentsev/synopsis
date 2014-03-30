#ifndef FIELD_H
#define FIELD_H

#include "value.hpp"
#include <string>

namespace synopsis {

template <typename T>
class TField {
public:
    TField(std::string sName, TValue <T> tValue)
        : m_sName(sName)
        , m_tValue(tValue)
    {
    }

    std::string m_sName;
    TValue <T> m_tValue;

};

}
#endif // FIELD_H
