#ifndef DAO_CLASS_FACTORY_H
#define DAO_CLASS_FACTORY_H

#include <dao/inc/iconnection.h>
#include <dao/inc/idataaccessor.h>

namespace synopsis {
namespace classfactory {

IDataAccessor* CreateDataAccessor(const char* pszDriverName);

} //classfactory
} //namespace synopsis

#endif // DAO_CLASS_FACTORY_H
