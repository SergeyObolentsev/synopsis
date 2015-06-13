#include <sstream>
#include <stdexcept>

#include "../inc/connection_postgr.h"

namespace synopsis {

ConnectionPostgr::ConnectionPostgr()
    :m_pConn(0)
{

}

ConnectionPostgr::~ConnectionPostgr()
{
    try
    {
        Close();
    }
    catch (...) {}
}

void ConnectionPostgr::Open(const std::string & sConnectionStr)
{
    bool isOk = false;
    m_pConn = PQconnectdb(sConnectionStr.c_str());
    const ConnStatusType statusOk = CONNECTION_OK;
    ConnStatusType status = CONNECTION_BAD;
    if (m_pConn) {
        status = PQstatus(m_pConn);
        if (status == statusOk) {
            isOk = true;
        } else {
            PQfinish(m_pConn);
            m_pConn = 0;
        }
    }
    if (!isOk) {
        std::stringstream ss;
        ss << "open database error."
           << " Connection status is:" << status
           << " Expected:" << statusOk;
        throw std::runtime_error(ss.str());
    }
}

void ConnectionPostgr::Close()
{
    PQfinish(m_pConn);
}


} //namespace synopsis
