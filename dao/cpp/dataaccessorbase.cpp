#include "../inc/dataaccessorbase.h"

namespace synopsis {

/*
CDataAccessorBase::CDataAccessorBase()
    :m_pIConnection(0)
{

}*/


void CDataAccessorBase::Read(TRows& arrResult, const std::string& sTableName, const TStrings& arrColumns,
              const CRow& rowSelection, const SelectionOrder& selectionOrder) const
{

}

void CDataAccessorBase::Insert(const std::string& sTableName, const CRow& rowNew)
{

}

void CDataAccessorBase::Update(const std::string& sTableName, const CRow& rowSelection, const CRow& rowUpdate)
{

}

void CDataAccessorBase::Delete(const std::string& sTableName, const CRow& rowSelection)
{

}

} // namespace synopsis
