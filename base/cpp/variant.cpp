#include <stdlib.h>
#include <assert.h>

#include "../inc/variant.h"

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

CVariant::CVariant (unsigned long ulVal)
    :m_eType(ECommonTypeULong)
    ,m_bIsValid(true)
    ,m_bIsNull(false)
{
    m_uData.ul = ulVal;
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
    int iRes = 0;
    switch (m_eType) {
        case ECommonTypeInt:
            iRes = m_uData.i;
        break;
        case ECommonTypeStdString:
            if (!m_sData.empty()){
                iRes = atoi(m_sData.c_str());
            }
        break;
        default:
         iRes = 0;
    }
    return iRes;
}

unsigned long CVariant::ToULong() const
{
    unsigned long ulRes = 0;
    switch (m_eType) {
    case ECommonTypeInt:
        ulRes = m_uData.i;
        break;
    case ECommonTypeULong:
        ulRes = m_uData.ul;
        break;
    case ECommonTypeStdString:
        if (!m_sData.empty()){
            ulRes = atol(m_sData.c_str());
        }
        break;
    default:
        ulRes = 0;
    }
    return ulRes;
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
        case synopsis::ECommonTypeULong:
            os << v.ToULong();
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
