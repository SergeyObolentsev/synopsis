#include "qtmeta.h"
#include "test_dataaccessutils.h"

#include <dao/inc/dataaccessorutils.h>
#include <sstream>

Test_synopsis_DataAccessUtils::Test_synopsis_DataAccessUtils()
{
}

void Test_synopsis_DataAccessUtils::initTestCase()
{

}

void Test_synopsis_DataAccessUtils::cleanupTestCase()
{

}

void Test_synopsis_DataAccessUtils::testCase1()
{
    QFETCH(synopsis::CVariant, value);
    QFETCH(std::string, expected);
    {
        std::stringstream ss;
        synopsis::GenerateLiteralValue(ss, value);
        QVERIFY(ss.str() == expected);
    }
}

void Test_synopsis_DataAccessUtils::testCase1_data()
{
    QTest::addColumn<synopsis::CVariant>("value");
    QTest::addColumn<std::string>("expected");
    QTest::newRow("int") << synopsis::CVariant(0) << std::string("0");
}

void Test_synopsis_DataAccessUtils::testCase2()
{
    QFETCH(std::string, column);
    QFETCH(synopsis::CVariant, value);
    QFETCH(std::string, expected);
    {
        synopsis::CRow row(column, value);
        std::stringstream ss;
        synopsis::GenerateWhereClause(ss, row);
        std::string sRes = ss.str();
        QVERIFY(sRes == expected);
    }
}

void Test_synopsis_DataAccessUtils::testCase2_data()
{
    //Test for single column
    //column name
    QTest::addColumn<std::string>("column");
    //column value
    QTest::addColumn<synopsis::CVariant>("value");
    //expected result
    QTest::addColumn<std::string>("expected");

    QTest::newRow("int") << std::string("id") << synopsis::CVariant(0) << std::string(" WHERE id = 0");
}
