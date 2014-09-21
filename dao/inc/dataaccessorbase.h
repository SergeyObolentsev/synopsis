#ifndef DATAACCESSORBASE_H
#define DATAACCESSORBASE_H

#include "idataaccessor.h"


namespace synopsis {


//It seems like we don't need this class TBR(To Be Removed)
class CDataAccessorBase : public IDataAccessor {

public:

    virtual void Read(TRows& arrResult, const std::string& sTableName, const TStrings& arrColumns,
                      const CRow& rowSelection, const SelectionOrder& selectionOrder) const;
    virtual void Insert(const std::string& sTableName, const CRow& rowNew);
    virtual void Update(const std::string& sTableName, const CRow& rowSelection, const CRow& rowUpdate);
    virtual void Delete(const std::string& sTableName, const CRow& rowSelection);

private:
   //IConnection* m_pIConnection;
};

} // namespace synopsis


#endif // DATAACCESSORBASE_H
