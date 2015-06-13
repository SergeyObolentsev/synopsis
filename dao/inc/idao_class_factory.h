#ifndef IDAO_CLASS_FACROTY_H
#define IDAO_CLASS_FACROTY_H

#include "iconnection.h"
#include "idataaccessor.h"

namespace synopsis {

class IDaoClassFactory {

public:
    virtual ~IDaoClassFactory() {}
    virtual IConnection* CreateConnection() = 0;
    virtual IDataAccessor* CreateDataAccessor(IConnection*) = 0;
};

} //namespace synopsis


#endif // IDAO_CLASS_FACROTY_H
