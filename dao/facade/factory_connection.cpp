#include "factory_connection.h"
#include "ids_drivers.h"

#include <dao/drivers/postgres/inc/connection_postgr.h>

#include <sstream>
#include <stdexcept>
#include <string.h>

namespace synopsis {

IConnection* CreateConnection(const char* pszDriverName)
{
    IConnection* pRes = 0;
    if(pszDriverName) {
        if((strlen(DAO_DRIVER_POSTGRES) == strlen(pszDriverName))
                &&(strcmp(DAO_DRIVER_POSTGRES, pszDriverName)))
        {
            pRes = new ConnectionPostgr;
        }
    }

    if(!pRes) {
        std::stringstream ss;
        ss << "Connection factory couldn't create the new object for:'"
           << pszDriverName
           << "'";
        throw std::runtime_error(ss.str());
    }
    return pRes;
}

} //namespace synopsis
