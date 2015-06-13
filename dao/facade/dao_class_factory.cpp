#include "dao_class_factory.h"

#include "ids_drivers.h"

#include <dao/drivers/postgres/inc/dataaccessor_postgr.h>

#include <sstream>
#include <stdexcept>
#include <string.h>

namespace synopsis {
namespace classfactory {

IDataAccessor* CreateDataAccessor(const char* pszDriverName)
{
    IDataAccessor* pRes = 0;

    if(pszDriverName)
    {

        if((strlen(DAO_DRIVER_POSTGRES) == strlen(pszDriverName))
                &&(0 == strcmp(DAO_DRIVER_POSTGRES, pszDriverName)))
        {
            pRes = new CDataAccessorPostgr;
        }
    }

    if(!pRes) {
        std::stringstream ss;
        ss << "Data accessor factory couldn't create the new object for:'"
           << pszDriverName
           << "'";
        throw std::runtime_error(ss.str());
    }
    return pRes;
}

} //classfactory
} //namespace synopsis
