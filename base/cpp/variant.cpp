#include "../inc/variant.h"

#include <assert.h>

namespace synopsis {

Variant::Variant()
    :m_eType(ECommonTypeNone)
    ,m_bIsValid(false)
    ,m_bIsNull(true)
{
}

Variant::Variant (ECommonTypes eType)
    :m_eType(eType)
    ,m_bIsValid(true)
    ,m_bIsNull(true)
{
}

Variant::Variant (int iVal)
    :m_eType(ECommonTypeInt)
    ,m_bIsValid(true)
    ,m_bIsNull(false)
{
    m_uData.i = iVal;
}

Variant::Variant (bool bVal)
    :m_eType(ECommonTypeBool)
    ,m_bIsValid(true)
    ,m_bIsNull(false)
{
    m_uData.b = bVal;
}

Variant::Variant (double dVal)
    :m_eType(ECommonTypeDouble)
    ,m_bIsValid(true)
    ,m_bIsNull(false)
{
    m_uData.d = dVal;
}

int Variant::ToInt() const
{
    assert(ECommonTypeInt == m_eType);
    return m_uData.i;
}

bool Variant::ToBool() const
{
    assert(ECommonTypeBool == m_eType);
    return m_uData.b;
}

double Variant::ToDouble() const
{
    assert(ECommonTypeDouble == m_eType);
    return m_uData.d;
}

} //namespace synopsis

std::ostream& operator<<(std::ostream& os, synopsis::Variant& v)
{
    switch(v.GetType()) {
        case synopsis::ECommonTypeBool:
            os << v.ToBool();
        break;
        case synopsis::ECommonTypeInt:
            os << v.ToInt();
        break;
        case synopsis::ECommonTypeDouble:
            os << v.ToDouble();
        break;
        default:
            assert(false);
    }
  return os;
}
