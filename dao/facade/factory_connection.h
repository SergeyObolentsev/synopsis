#ifndef FACTORY_CONNECTION_H
#define FACTORY_CONNECTION_H

#include <dao/inc/idaoclassfactory.h>

namespace synopsis {

IConnection* CreateConnection(const char* pszDriverName);

} //namespace synopsis



#endif //FACTORY_CONNECTION_H
