#ifndef __fb18b419_a0b8_4588_8bca_c238e00562e3__
#define __fb18b419_a0b8_4588_8bca_c238e00562e3__

#include "defines.h"
#include <iostream>
#include <string>

namespace synopsis {

class CVariant {

public:

    CVariant ();
    CVariant (ECommonTypes eType);
    CVariant (int iVal);
    CVariant (unsigned long ulVal);
    CVariant (bool bVal);
    CVariant (double dVal);
    CVariant (const char* pszVal);
    CVariant (const std::string& sVal);

    inline bool IsValid() const { return m_bIsValid; }
    inline bool IsNull() const { return m_bIsNull; }
    inline ECommonTypes GetType() const { return m_eType; }
    inline void SetType(ECommonTypes eType) { m_eType = eType; }
    inline bool IsNumber() const { return m_eType == ECommonTypeInt
                                       || m_eType == ECommonTypeDouble
                                       || m_eType == ECommonTypeFloat
                                       || m_eType == ECommonTypeULong; }

    int ToInt() const;
    unsigned long ToULong() const;
    bool ToBool() const;
    double ToDouble() const;
    const std::string& ToStdString() const;

    inline ECommonTypes Type() const { return m_eType; }

    friend std::ostream& operator<<(std::ostream&, CVariant&);

protected:
    inline void SetValid(bool bIsValid) { m_bIsValid = bIsValid; }
    inline void SetIsNull(bool bIsNull) { m_bIsNull = bIsNull; }
    union UData
    {
        int i;
        unsigned long ul;
        bool b;
        double d;
    } m_uData;
    std::string m_sData;
    ECommonTypes m_eType;
    bool m_bIsValid;
    bool m_bIsNull;
};

} //namespace synopsis

std::ostream& operator << (std::ostream& os, const synopsis::CVariant& v);

#endif // __fb18b419_a0b8_4588_8bca_c238e00562e3__
