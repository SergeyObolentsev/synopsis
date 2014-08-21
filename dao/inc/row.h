#ifndef ROW_H
#define ROW_H

#include <base/inc/variant.h>
#include <base/inc/stl_helper_map.h>

#include <map>
#include <stdexcept>
#include <string>
#include <list>

namespace synopsis {

class CRow {

public:

    typedef std::map<std::string, CVariant> TMap;

    CRow()
    {
    }

    CRow(const std::string& sColumn, const CVariant& vVal)
    {
        EfficientAddUpdate(m_mapColumns, sColumn, vVal);
    }

    void addColumn(const std::string& sColumn, const CVariant& vVal)
    {
        EfficientAddUpdate(m_mapColumns, sColumn, vVal);
    }

    const CVariant& getColumnValue(const std::string& sColumn) const
    {
        typename TMap::const_iterator lb(m_mapColumns.lower_bound(sColumn));
        if(lb == m_mapColumns.end()) {
            throw std::out_of_range("Invalid column name");
        }
        return lb->second;
    }

    CVariant& getColumnValue(const std::string& sColumn)
    {
        typename TMap::iterator lb(m_mapColumns.lower_bound(sColumn));
        if(lb == m_mapColumns.end()) {
            throw std::out_of_range("Invalid column name");
        }
        return lb->second;
    }

    void setColumnValue(const std::string& sColumn, const CVariant& vVal)
    {
        addColumn(sColumn, vVal);
    }

    inline TMap::iterator begin()
    {
        return m_mapColumns.begin();
    }

    inline TMap::iterator end()
    {
        return m_mapColumns.end();
    }


    inline TMap::const_iterator begin() const
    {
        return m_mapColumns.begin();
    }

    inline TMap::const_iterator end() const
    {
        return m_mapColumns.end();
    }

    inline void SetKeyColumnName(const std::string& sKeyColumn)
    {
        m_sKeyColumn = sKeyColumn;
    }

    inline const std::string& GetKeyColumnName() const
    {
        return m_sKeyColumn;
    }

private:
    TMap m_mapColumns;
    std::string m_sKeyColumn;
};

typedef std::list<CRow> TRows;
typedef std::list<std::string> TStrings;

} //namespace synopsis

#endif // ROW_H
