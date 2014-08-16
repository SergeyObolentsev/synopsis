#include "../inc/dataaccessor_postgr.h"


namespace synopsis {

CDataAccessorPostgr::CDataAccessorPostgr(ConnectionPostgr& connection)
    :m_Connection(connection)
{

}

void CDataAccessorPostgr::Read(TRows& arrResult, const std::string& sTableName, const TStrings& arrColumns,
                      const CRow& rowSelection, const TStrings& arrColumnsSort) const
{

}

void CDataAccessorPostgr::Insert(const std::string& sTableName, const TRows& arrRows)
{

}

void CDataAccessorPostgr::Update(const std::string& sTableName, const CRow& rowSelection, const CRow& rowUpdate)
{
}

void CDataAccessorPostgr::Delete(const std::string& sTableName, const CRow& rowSelection)
{
}

} // namespace synopsis
