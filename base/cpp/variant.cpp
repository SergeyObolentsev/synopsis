#include "../inc/variant.h"

#include <assert.h>

namespace synopsis {

CVariant::CVariant()
    :m_eType(ECommonTypeNone)
    ,m_bIsValid(false)
    ,m_bIsNull(true)
{
}

CVariant::CVariant (ECommonTypes eType)
    :m_eType(eType)
    ,m_bIsValid(true)
    ,m_bIsNull(true)
{
}

CVariant::CVariant (int iVal)
    :m_eType(ECommonTypeInt)
    ,m_bIsValid(true)
    ,m_bIsNull(false)
{
    m_uData.i = iVal;
}

CVariant::CVariant (bool bVal)
    :m_eType(ECommonTypeBool)
    ,m_bIsValid(true)
    ,m_bIsNull(false)
{
    m_uData.b = bVal;
}

CVariant::CVariant (double dVal)
    :m_eType(ECommonTypeDouble)
    ,m_bIsValid(true)
    ,m_bIsNull(false)
{
    m_uData.d = dVal;
}

CVariant::CVariant (const char* pszVal)
    :m_sData(pszVal)
    ,m_eType(ECommonTypeStdString)
    ,m_bIsValid(true)
    ,m_bIsNull(false)

{
}

CVariant::CVariant (const std::string& sVal)
    :m_sData(sVal)
    ,m_eType(ECommonTypeStdString)
    ,m_bIsValid(true)
    ,m_bIsNull(false)
{
}


int CVariant::ToInt() const
{
    assert(ECommonTypeInt == m_eType);
    return m_uData.i;
}

bool CVariant::ToBool() const
{
    assert(ECommonTypeBool == m_eType);
    return m_uData.b;
}

double CVariant::ToDouble() const
{
    assert(ECommonTypeDouble == m_eType);
    return m_uData.d;
}

const std::string& CVariant::ToStdString() const
{
    assert(ECommonTypeStdString == m_eType);
    return m_sData;
}

} //namespace synopsis

std::ostream& operator<<(std::ostream& os, const synopsis::CVariant& v)
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
        case synopsis::ECommonTypeStdString:
            os << v.ToStdString();
        break;
        default:
            assert(false);
    }
  return os;
}
