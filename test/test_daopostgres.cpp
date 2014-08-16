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
        m_conn.Open(sConnStr.toStdString());
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

   // QFETCH(std::string, column);
   // QFETCH(synopsis::CVariant, value);
   // QFETCH(int, expected);

   // m_row.addColumn(column, value);
   // QVERIFY(m_row.getColumnValue(column).ToInt() == expected);
}

void Test_synopsis_ConnectionPostgr::testCase1_data()
{
   // QTest::addColumn<std::string>("column");
   // QTest::addColumn<synopsis::CVariant>("value");
   // QTest::addColumn<int>("expected");

   // QTest::newRow("zero")     << std::string("first")  << synopsis::CVariant(0)    <<    0;
   // QTest::newRow("positive") << std::string("second") << synopsis::CVariant(100)  <<  100;
   // QTest::newRow("negative") << std::string("third")  << synopsis::CVariant(-100) << -100;

}

