#ifndef IDATAACCESSOR_H
#define IDATAACCESSOR_H

#include "row.h"

#include <list>

namespace synopsis {

class IDataAccessor {

public:

typedef std::list<CRow> TRows;
typedef std::list<std::string> TStrings;

    virtual void Read(TRows& arrResult, const std::string& sTableName, const TStrings& arrColumns,
              const CRow& rowSelection, const TStrings& arrColumnsSort) const = 0;
    virtual void Insert(const std::string& sTableName, const TRows& arrRows) = 0;
    virtual void Update(const std::string& sTableName, const CRow& rowSelection, const CRow& rowUpdate) = 0;
    virtual void Delete(const std::string& sTableName, const CRow& rowSelection) = 0;
};

} // namespace synopsis

#endif // IDATAACCESSOR_H
