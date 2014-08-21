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
    os << " WHERE ";
    for (CRow::TMap::const_iterator it(rowSelecion.begin()); it != rowSelecion.end(); ++it) {
        if(rowSelecion.begin() != it){
            os << " AND ";
        }
        os << it->first
           << " = "
           << it->second;
    }
}

void GenerateInsertClase(std::ostream& os, const std::string& sTableName, const CRow& row)
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


} //namespace synopsis
