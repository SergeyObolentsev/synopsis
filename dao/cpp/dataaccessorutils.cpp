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


} //namespace synopsis
