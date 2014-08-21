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

/*! \fn void GenerateInsertClase(std::ostream& os, const std::string& sTableName, const TRows& arrRows);
    \brief Generates a SQL INSERT clause based on the given table name and a table row.
    \param os output stream.
    \param sTableName table name
    \param a row to be inserted
*/
void GenerateInsertClase(std::ostream& os, const std::string& sTableName, const CRow& row);

} //namespace synopsis


#endif // DATAACCESSORUTILS_H
