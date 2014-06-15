#ifndef DATAACCESSORBASE_H
#define DATAACCESSORBASE_H

#include "idataaccessor.h"


namespace synopsis {

class CDataAccessorBase : public IDataAccessor {

public:

    virtual void Read(TRows& arrResult, const std::string& sTableName, const TStrings& arrColumns,
              const CRow& rowSelection, const TStrings& arrColumnsSort) const;
    virtual void Insert(const std::string& sTableName, const TRows& arrRows);
    virtual void Update(const std::string& sTableName, const CRow& rowSelection, const CRow& rowUpdate);
    virtual void Delete(const std::string& sTableName, const CRow& rowSelection);
};

} // namespace synopsis


#endif // DATAACCESSORBASE_H
