#ifndef DATAACCESSORUTILS_H
#define DATAACCESSORUTILS_H

#include <base/inc/variant.h>

#include "daocommon.h"
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
    \param rowSelecion a set of filter columns and values used to subset of rows, or empty to read all the rows
*/
void GenerateWhereClause(std::ostream& os, const CRow& rowSelecion);

/*! \fn void GenerateOrderClause(std::ostream& os, const TStrings& arrSortColumns);
    \brief Generates a SQL ORDER clause based on a list of columns to sort.
    \param os output stream.
    \param selectionOrder the columns to sort
*/
void GenerateOrderClause(std::ostream& os,  const SelectionOrder& selectionOrder);


/*! \fn void GenerateInsertClase(std::ostream& os, const std::string& sTableName, const TRows& arrRows);
    \brief Generates a SQL INSERT clause based on the given table name and a table row.
    \param os output stream.
    \param sTableName table name
    \param row a row to inserts
*/
void GenerateInsertClause(std::ostream& os, const std::string& sTableName, const CRow& row);

/*! \fn void GenerateSelectClase(std::ostream& os, const std::string& sTableName, const TRows& arrRows);
    \brief Generates a SQL SELECT clause
    \param os output stream.
    \param sTableName table name
    \param arrColumns the columns to read, or empty to read all the columns in the table
    \param rowSelecion a set of filter columns and values used to subset of rows, or empty to read all the rows
    \param selectionOrder the columns to sort
*/
void GenerateSelectClause(std::ostream& os, const std::string& sTableName,
                          const TStrings& arrColumns = TStrings(),
                          const CRow& rowSelection = CRow(),
                          const SelectionOrder& selectionOrder = SelectionOrder());


} //namespace synopsis


#endif // DATAACCESSORUTILS_H
