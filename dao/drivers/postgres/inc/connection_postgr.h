#ifndef CONNECTION_POSTGR_H
#define CONNECTION_POSTGR_H

#include <postgresql/libpq-fe.h>

#include <dao/inc/iconnection.h>

namespace synopsis {

class ConnectionPostgr : public IConnection {

public:

    ConnectionPostgr();
    ~ConnectionPostgr();

    virtual void Open(const std::string & sConnectionStr);
    virtual void Close();

    inline PGconn* getPGconn() { return m_pConn; }
private:

    //ConnectionPostgr (const ConnectionPostgr&);
    //ConnectionPostgr& operator=(const ConnectionPostgr&);

    PGconn* m_pConn;
};

} //namespace synopsis

#endif // CONNECTION_POSTGR_H
