#include "test_daopostgres.h"

#include "qtmeta.h"
#include <stdexcept>
#include <QProcessEnvironment>

Test_synopsis_ConnectionPostgr::Test_synopsis_ConnectionPostgr()
    :m_ulLastRowId(-1UL)
{
}

void Test_synopsis_ConnectionPostgr::initTestCase()
{
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    QString sConnStr = env.value("SQL_DB_CONN_STR_POSTGRES");
    try {        
        m_PtrDataAccessor.reset(new synopsis::CDataAccessorPostgr());
        m_PtrDataAccessor->GetConnection().Open(sConnStr.toStdString());
    } catch (std::runtime_error& err) {
        std::cout << err.what() << std::endl;
        QVERIFY(false);
    }

    cleanupTestCase();
}

void Test_synopsis_ConnectionPostgr::cleanupTestCase()
{

    // clear test table
    m_PtrDataAccessor->Delete("test");

    // check test table is empty
    unsigned long ulRowCount = m_PtrDataAccessor->GetRowCount("test");
    QVERIFY(0 == ulRowCount);
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
    // check test table row count is one
    unsigned long ulRowCount = m_PtrDataAccessor->GetRowCount("test");
    QVERIFY(1 == ulRowCount);

    m_ulLastRowId = m_PtrDataAccessor->GetLastIsertedRowId("test", "id");

}

void Test_synopsis_ConnectionPostgr::testCase1_data()
{
}

void Test_synopsis_ConnectionPostgr::testCase2()
{
    QVERIFY(m_ulLastRowId != -1UL);
    synopsis::TRows arrResult;
    const std::string sTableName("test");
    synopsis::TStrings arrColumns;
    arrColumns.push_back("id");
    m_PtrDataAccessor->Read(arrResult, sTableName, arrColumns, synopsis::CRow("id", m_ulLastRowId));
    QVERIFY(1 == arrResult.size());
    const synopsis::CRow& row = *arrResult.begin();
    const unsigned long ulLastRowId = row.getColumnValue("id").ToULong();
    QVERIFY(ulLastRowId == m_ulLastRowId);
}

void Test_synopsis_ConnectionPostgr::testCase2_data()
{

}

void Test_synopsis_ConnectionPostgr::testCase3()
{
    synopsis::CRow rowNew;

    rowNew.setColumnValue("int1", 333);
    rowNew.setColumnValue("int2", 444);

    m_PtrDataAccessor->Insert("test", rowNew);

    QVERIFY(m_ulLastRowId != -1UL);

    // check test table row count is one
    unsigned long ulRowCount = m_PtrDataAccessor->GetRowCount("test");
    QVERIFY(2 == ulRowCount);

    m_ulLastRowId = m_PtrDataAccessor->GetLastIsertedRowId("test", "id");

    synopsis::CRow rowUpdate("int2", 555);
    synopsis::CRow rowSelection("id", m_ulLastRowId);

    rowSelection.setColumnValue("int1", 333);
    m_PtrDataAccessor->Update("test", rowUpdate, rowSelection);


    synopsis::TRows arrResult;
    const std::string sTableName("test");
    synopsis::TStrings arrColumns;
    arrColumns.push_back("id");
    arrColumns.push_back("int2");

    m_PtrDataAccessor->Read(arrResult, sTableName, arrColumns, synopsis::CRow("id", m_ulLastRowId));
    QVERIFY(1 == arrResult.size());
    const synopsis::CRow& row = *arrResult.begin();
    const int intVal = row.getColumnValue("int2").ToInt();
    QVERIFY(555 == intVal);
}

void Test_synopsis_ConnectionPostgr::testCase3_data()
{

}

void Test_synopsis_ConnectionPostgr::testCase4()
{
    QVERIFY(m_ulLastRowId != -1UL);
    // Delete the inserted row
    m_PtrDataAccessor->Delete("test", synopsis::CRow("", m_ulLastRowId));

    // check test table is empty
    unsigned long ulRowCount = m_PtrDataAccessor->GetRowCount("test");
    QVERIFY(0 == ulRowCount);
}

void Test_synopsis_ConnectionPostgr::testCase4_data()
{

}
