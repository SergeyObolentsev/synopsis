#include "../inc/dataaccessorbase.h"

namespace synopsis {
/*
CDataAccessorBase::CDataAccessorBase()
    :m_pIConnection(0)
{

}*/


void CDataAccessorBase::Read(TRows& arrResult, const std::string& sTableName, const TStrings& arrColumns,
              const CRow& rowSelection, const TStrings& arrColumnsSort) const
{

}

void CDataAccessorBase::Insert(const std::string& sTableName, const TRows& arrRows)
{

}

void CDataAccessorBase::Update(const std::string& sTableName, const CRow& rowSelection, const CRow& rowUpdate)
{

}

void CDataAccessorBase::Delete(const std::string& sTableName, const CRow& rowSelection)
{

}

} // namespace synopsis
