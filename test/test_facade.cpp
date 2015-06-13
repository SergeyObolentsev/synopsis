#include "test_facade.h"

#include <dao/facade/ids_drivers.h>
#include <dao/facade/dao_class_factory.h>

#include "qtmeta.h"
#include <stdexcept>
#include <QProcessEnvironment>

Test_synopsis_Facade::Test_synopsis_Facade()
{
}

void Test_synopsis_Facade::initTestCase()
{
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    QString sConnStr = env.value("SQL_DB_CONN_STR_POSTGRES");
    try {
        m_ptrDataAccessor.reset(synopsis::classfactory::CreateDataAccessor(
                                synopsis::DAO_DRIVER_POSTGRES));
        m_ptrDataAccessor->GetConnection().Open(sConnStr.toStdString());
    } catch (std::runtime_error& err) {
        std::cout << err.what() << std::endl;
        QVERIFY(false);
    }

    cleanupTestCase();
}

void Test_synopsis_Facade::cleanupTestCase()
{

    // clear test table
    m_ptrDataAccessor->Delete("test");

    // check test table is empty
    unsigned long ulRowCount = m_ptrDataAccessor->GetRowCount("test");
    QVERIFY(0 == ulRowCount);
}

void Test_synopsis_Facade::testCase1()
{

    // This is a test for synopsis::CRow columns of int type
    // 1)Add a column and set value of integer type,
    // 2)Read and check the written value

    synopsis::CRow rowNew;

    rowNew.setColumnValue("int1", 1234);
    rowNew.setColumnValue("int2", 56789);

    m_ptrDataAccessor->Insert("test", rowNew);
    // check test table row count is one
    unsigned long ulRowCount = m_ptrDataAccessor->GetRowCount("test");
    QVERIFY(1 == ulRowCount);
}
