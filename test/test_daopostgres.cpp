#include "test_daopostgres.h"

#include "qtmeta.h"
#include <stdexcept>
#include <QProcessEnvironment>

Test_synopsis_ConnectionPostgr::Test_synopsis_ConnectionPostgr()
{
}

void Test_synopsis_ConnectionPostgr::initTestCase()
{
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    QString sConnStr = env.value("SQL_DB_CONN_STR_POSTGRES");
    try {
        m_Connection.Open(sConnStr.toStdString());
        m_PtrDataAccessor.reset(new synopsis::CDataAccessorPostgr(m_Connection));
    } catch (std::runtime_error& err) {
        std::cout << err.what() << std::endl;
        QVERIFY(false);
    }

}

void Test_synopsis_ConnectionPostgr::cleanupTestCase()
{

}

void Test_synopsis_ConnectionPostgr::testCase1()
{


    // This is a test for synopsis::CRow columns of int type
    // 1)Add a column and set value of integer type,
    // 2)Read and check the written value

    synopsis::CRow rowNew;

    rowNew.setColumnValue("int1", 1234);
    rowNew.setColumnValue("int2", 56789);

    m_PtrDataAccessor->Insert("test", rowNew);
    m_PtrDataAccessor->GetLastIsertedRowId("test", "id");

}

void Test_synopsis_ConnectionPostgr::testCase1_data()
{
}

void Test_synopsis_ConnectionPostgr::testCase2()
{
    synopsis::TRows arrResult;
    const std::string sTableName("test");
    m_PtrDataAccessor->Read(arrResult, sTableName);
}

void Test_synopsis_ConnectionPostgr::testCase2_data()
{

}

