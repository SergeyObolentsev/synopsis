#include "../inc/dataaccessorutils.h"

namespace synopsis {

void GenerateLiteralValue(std::ostream& os, const CVariant& vVal)
{
    if (!vVal.IsNumber()) {
        os << "'";
    }
    os << vVal;
    if (!vVal.IsNumber()) {
        os << "'";
    }
}

void GenerateWhereClause(std::ostream& os, const CRow& rowSelecion)
{
    if(!rowSelecion.Empty()) {
        os << " WHERE ";
    }

    for (CRow::TMap::const_iterator it(rowSelecion.begin()); it != rowSelecion.end(); ++it) {
        if(rowSelecion.begin() != it){
            os << " AND ";
        }
        os << it->first
           << "=";
        GenerateLiteralValue(os, it->second);
    }
}

void GenerateOrderClause(std::ostream& os, const SelectionOrder& selectionOrder) {

    if(!selectionOrder.m_Columns.empty()) {
        os << " ORDER BY ";        
        for(TStrings::const_iterator it(selectionOrder.m_Columns.begin()); it != selectionOrder.m_Columns.end(); ++it) {
            if(it != selectionOrder.m_Columns.begin()){
                os << ", ";
            }
            os << *it;
        }
        os << (selectionOrder.m_bAscent ? " ASC" : " DESC");
    }
}

void GenerateInsertClause(std::ostream& os, const std::string& sTableName, const CRow& row)
{
    os << "INSERT INTO "
       << sTableName;

    // List the column names
    os << " (";
    {
        for(CRow::TMap::const_iterator itColumn(row.begin()); itColumn != row.end(); ++itColumn) {
            if(itColumn != row.begin()){
                os << ", ";
            }
            os << itColumn->first;
        }
    }

    // List the column values
    os << ") VALUES (";
    {
        for(CRow::TMap::const_iterator itColumn(row.begin()); itColumn != row.end(); ++itColumn) {
            if(itColumn != row.begin()){
                os << ", ";
            }
            const CVariant& val (itColumn->second);
            GenerateLiteralValue(os, val);
        }
    }
    os << ")";
}

void GenerateSelectClause(std::ostream& os, const std::string& sTableName, const TStrings& arrColumns,
                          const CRow& rowSelection, const SelectionOrder& selectionOrder)
{
    os << "SELECT";
    if(arrColumns.empty()) {
        os << " *";
    } else {
        for (TStrings::const_iterator it(arrColumns.begin()); it != arrColumns.end(); ++it) {
            os << (it == arrColumns.begin() ? " " :  ", ")
               << *it;
        }
    }

    os << " FROM "
       << sTableName;

    GenerateWhereClause(os, rowSelection);
    GenerateOrderClause(os, selectionOrder);
}

} //namespace synopsis
