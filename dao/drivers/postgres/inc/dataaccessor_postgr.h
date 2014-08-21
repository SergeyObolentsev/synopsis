#ifndef DATAACCESSOR_POSTGR_H
#define DATAACCESSOR_POSTGR_H

#include <dao/inc/idataaccessor.h>
#include "connection_postgr.h"


namespace synopsis {

class CDataAccessorPostgr : public IDataAccessor {

public:

    CDataAccessorPostgr(ConnectionPostgr& connection);

    virtual void Read(TRows& arrResult, const std::string& sTableName, const TStrings& arrColumns = TStrings(),
                      const CRow& rowSelection = CRow(), const SelectionOrder& selectionOrder = SelectionOrder()) const;
    virtual void Insert(const std::string& sTableName, const CRow& rowNew);
    virtual void Update(const std::string& sTableName, const CRow& rowSelection, const CRow& rowUpdate);
    virtual void Delete(const std::string& sTableName, const CRow& rowSelection);
    virtual unsigned long GetLastIsertedRowId(const std::string& sTableName, const std::string& sKeyColumn);


private:
    void CheckConnection() const;
    ConnectionPostgr&  m_Connection;
};

} // namespace synopsis

#endif // DATAACCESSOR_POSTGR_H
