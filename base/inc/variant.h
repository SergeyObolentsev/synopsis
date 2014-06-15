#ifndef __fb18b419_a0b8_4588_8bca_c238e00562e3__
#define __fb18b419_a0b8_4588_8bca_c238e00562e3__

#include "defines.h"
#include <iostream>

namespace synopsis {

class CVariant {

public:

    CVariant ();
    CVariant (ECommonTypes eType);
    CVariant (int iVal);
    CVariant (bool iVal);
    CVariant (double iVal);

    inline bool IsValid() const { return m_bIsValid; }
    inline bool IsNull() const { return m_bIsNull; }
    inline void SetNull() { m_bIsNull = true; }
    inline ECommonTypes GetType() const { return m_eType; }
    inline void SetType(ECommonTypes eType) { m_eType = eType; }
    inline bool IsNumber() const { return m_eType == ECommonTypeInt
                                       || m_eType == ECommonTypeDouble
                                       || m_eType == ECommonTypeFloat ; }

    int ToInt() const;
    bool ToBool() const;
    double ToDouble() const;

    friend std::ostream& operator<<(std::ostream&, CVariant&);

public:
private:
    inline void SetValid(bool bIsValid) { m_bIsValid = bIsValid; }

    union UData
    {
        int i;
        bool b;
        double d;
    } m_uData;

    ECommonTypes m_eType;
    bool m_bIsValid;
    bool m_bIsNull;
};

} //namespace synopsis

std::ostream& operator << (std::ostream& os, const synopsis::CVariant& v);

#endif // __fb18b419_a0b8_4588_8bca_c238e00562e3__
