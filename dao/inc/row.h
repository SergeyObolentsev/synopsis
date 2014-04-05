#ifndef ROW_H
#define ROW_H

#include <base/inc/variant.h>
#include <base/inc/stl_helper_map.h>

#include <map>
#include <stdexcept>
#include <string>


namespace synopsis {

class CRow {

public:

    typedef std::map<std::string, CVariant> TMap;

    CRow()
    {
    }

    CRow(const std::string sColumn, const CVariant& vVal)
    {
        EfficientAddUpdate(m_mapColumns, sColumn, vVal);
    }

    void addColumn(const std::string sColumn, const CVariant& vVal)
    {
        EfficientAddUpdate(m_mapColumns, sColumn, vVal);
    }

    const CVariant& getColumnValue(const std::string sColumn) const
    {
        typename TMap::const_iterator lb(m_mapColumns.lower_bound(sColumn));
        if(lb == m_mapColumns.end()) {
            throw std::out_of_range("Invalid column name");
        }
        return lb->second;
    }

    CVariant& getColumnValue(const std::string sColumn)
    {
        typename TMap::iterator lb(m_mapColumns.lower_bound(sColumn));
        if(lb == m_mapColumns.end()) {
            throw std::out_of_range("Invalid column name");
        }
        return lb->second;
    }

    TMap::iterator begin()
    {
        return m_mapColumns.begin();
    }

    TMap::iterator end()
    {
        return m_mapColumns.end();
    }


private:
    TMap m_mapColumns;
};

} //namespace synopsis

#endif // ROW_H
