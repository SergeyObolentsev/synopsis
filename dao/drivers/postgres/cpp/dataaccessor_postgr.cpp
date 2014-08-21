#include <stdlib.h>

#include <sstream>
#include <stdexcept>


#include <dao/inc/dataaccessorutils.h>

#include "../inc/dataaccessor_postgr.h"


namespace synopsis {

CDataAccessorPostgr::CDataAccessorPostgr(ConnectionPostgr& connection)
    :m_Connection(connection)
{

}

void CDataAccessorPostgr::Read(TRows& arrResult, const std::string& sTableName, const TStrings& arrColumns,
                      const CRow& rowSelection, const SelectionOrder& selectionOrder) const
{
    CheckConnection();

    std::stringstream ss;
    GenerateSelectClause(ss, sTableName ,arrColumns, rowSelection, selectionOrder);

    PGresult *res(NULL);
    res = PQexec(m_Connection.getPGconn(), ss.str().c_str());

    ExecStatusType status = PQresultStatus(res);

    if (status != PGRES_TUPLES_OK) {
          std::string sMsg(PQresultErrorMessage(res));
          std::stringstream ss;
          ss << "PQ Failed to execute query. "
             << sMsg;
          PQclear(res);
          throw std::runtime_error(ss.str());
     }

    int iRowNum = PQntuples(res);
    int iFieldNum = PQnfields(res);
    if(iRowNum > 0 && iFieldNum > 0) {
        for(int i = 0; i < iRowNum; ++i) {
            CRow row;

            for(int j = 0; j < iFieldNum; ++j) {

                if(PQgetisnull(res, i, j)) {
                    row.setColumnValue(PQfname(res, j), CVariant());
                } else {
                    CVariant val = PQgetvalue(res, i, j);
                    row.setColumnValue(PQfname(res, j), val);
                }
            }
            arrResult.push_back(row);
        }
    }

    PQclear(res);
}



void CDataAccessorPostgr::Insert(const std::string& sTableName, const CRow& rowNew)
{
    CheckConnection();

    std::stringstream ss;
    GenerateInsertClause(ss, sTableName ,rowNew);

    PGresult *res(NULL);
    res = PQexec(m_Connection.getPGconn(), ss.str().c_str());

    ExecStatusType status = PQresultStatus(res);
    if (status != PGRES_COMMAND_OK ) {
        std::string sMsg(PQresultErrorMessage(res));
        std::stringstream ss;
        ss << "PQ Failed to execute query. "
           << sMsg;
        PQclear(res);
        throw std::runtime_error(ss.str());
    }
    PQclear(res);
}


unsigned long CDataAccessorPostgr::GetLastIsertedRowId(const std::string& sTableName, const std::string& sKeyColumn)
{
    CheckConnection();

    unsigned long ulRes = -1L;


    enum {
        _NParams = 2,
    };

    const char *paramValues[_NParams] = {
        sTableName.c_str(),
        sKeyColumn.c_str()
    };

    const int paramFormats[_NParams] = { 0, 0 };
    const int paramLengths[_NParams] = { 0, 0 };

    PGresult *res(NULL);

    const char sqlCommand[] = "SELECT currval(pg_get_serial_sequence($1, $2));";

    res = PQexecParams(
         m_Connection.getPGconn()
        ,sqlCommand
        ,_NParams
        ,NULL
        ,paramValues
        ,paramLengths
        ,paramFormats
        ,0 );

    ExecStatusType status = PQresultStatus(res);

    if (status != PGRES_TUPLES_OK ) {
        std::string sMsg(PQresultErrorMessage(res));
        std::stringstream ss;
        ss << "PQ Failed to execute query. "
           << sMsg;
        PQclear(res);
        throw std::runtime_error(ss.str());
    }

    //Check the result
    if(PQntuples(res) < 1){
        PQclear(res);
        throw std::runtime_error("Couldn't read the last inserted key");
    }

    const char* sRes = PQgetvalue(res, 0, 0);
    if(!sRes) {
        PQclear(res);
        throw std::runtime_error("Couldn't read the last inserted key");
    }

    ulRes = atoll(sRes);

    PQclear(res);

    return ulRes;
}

void CDataAccessorPostgr::Update(const std::string& sTableName, const CRow& rowSelection, const CRow& rowUpdate)
{
    CheckConnection();
}

void CDataAccessorPostgr::Delete(const std::string& sTableName, const CRow& rowSelection)
{
    CheckConnection();
}

void CDataAccessorPostgr::CheckConnection() const
{
    ConnStatusType status = PQstatus(m_Connection.getPGconn());
    if (CONNECTION_OK != status) {
        PQreset(m_Connection.getPGconn());
        std::stringstream ss;
        ss << " Database Error.\nConnection status is:" << status;
        throw std::runtime_error(ss.str());
    }
}

} // namespace synopsis
