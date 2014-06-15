#ifndef DATAACCESSORUTILS_H
#define DATAACCESSORUTILS_H

#include <base/inc/variant.h>
#include "row.h"

#include <iostream>
#include <string>

namespace synopsis {

/*! \fn std::string GenerateLiteralValue(std::ostream& os, const CVariant& vVal)
    \brief Generates a SQL literal string.
    \param os output stream.
    \param vVal value.
*/
void GenerateLiteralValue(std::ostream& os, const CVariant& vVal);

/*! \fn void GenerateWhereClause(std::ostream& os, const CRow& rowSelecion);
    \brief Generates a SQL WHERE clause based on a selection row.
    \param os output stream.
    \param rowSelection fields to be put in WHERE clause.
*/
void GenerateWhereClause(std::ostream& os, const CRow& rowSelecion);

} //namespace synopsis


#endif // DATAACCESSORUTILS_H
