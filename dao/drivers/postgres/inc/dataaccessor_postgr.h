#ifndef DATAACCESSOR_POSTGR_H
#define DATAACCESSOR_POSTGR_H

#include <dao/inc/dataaccessorbase.h>
#include "connection_postgr.h"


namespace synopsis {

class CDataAccessorPostgr : public IDataAccessor {

public:

    CDataAccessorPostgr(ConnectionPostgr& connection);

//    virtual void SetConnection(IConnection* pIConnection) { m_pIConnection = pIConnection; }

    virtual void Read(TRows& arrResult, const std::string& sTableName, const TStrings& arrColumns,
                      const CRow& rowSelection, const TStrings& arrColumnsSort) const;
    virtual void Insert(const std::string& sTableName, const TRows& arrRows);
    virtual void Update(const std::string& sTableName, const CRow& rowSelection, const CRow& rowUpdate);
    virtual void Delete(const std::string& sTableName, const CRow& rowSelection);

private:
    ConnectionPostgr&  m_Connection;
};

} // namespace synopsis

#endif // DATAACCESSOR_POSTGR_H
