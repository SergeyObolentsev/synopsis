#ifndef IDATAACCESSOR_H
#define IDATAACCESSOR_H

#include "row.h"
#include "daocommon.h"
#include "iconnection.h"


namespace synopsis {

class IDataAccessor {

public:
    virtual ~IDataAccessor() {}

    virtual void Read(TRows& arrResult, const std::string& sTableName, const TStrings& arrColumns = TStrings(),
                      const CRow& rowSelection = CRow(), const SelectionOrder& selectionOrder = SelectionOrder()) const = 0;
    virtual void Insert(const std::string& sTableName, const CRow& rowNew) = 0;
    virtual void Update(const std::string& sTableName, const CRow& rowUpdate, const CRow& rowSelection = CRow()) = 0;
    virtual void Delete(const std::string& sTableName, const CRow& rowSelection = CRow()) = 0;
    virtual unsigned long GetLastIsertedRowId(const std::string& sTableName, const std::string& sKeyColumn) = 0;
    virtual unsigned long GetRowCount(const std::string& sTableName) const = 0;
    virtual IConnection& GetConnection() = 0;
};

} // namespace synopsis

#endif // IDATAACCESSOR_H
