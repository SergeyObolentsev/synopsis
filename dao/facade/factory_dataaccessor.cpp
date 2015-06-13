#include "factory_dataaccessor.h"
#include <dao/drivers/postgres/inc/dataaccessor_postgr.h>

#include <sstream>
#include <stdexcept>
#include <string.h>

namespace synopsis {

IDataAccessor* CreateDataAccessor(const char* pszDriverName)
{
    IDataAccessor* pRes = 0;
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
