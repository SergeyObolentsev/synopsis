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

void Test_synopsis_DataAccessUtils::testCase3()
{
    QFETCH(std::string, table);

    QFETCH(std::string, col0);
    QFETCH(synopsis::CVariant, val0);

    QFETCH(std::string, col1);
    QFETCH(synopsis::CVariant, val1);

    QFETCH(std::string, col2);
    QFETCH(synopsis::CVariant, val2);

    QFETCH(std::string, col3);
    QFETCH(synopsis::CVariant, val3);

    QFETCH(std::string, expected);

    {
        synopsis::CRow row;
        row.addColumn(col0, val0);
        row.addColumn(col1, val1);
        row.addColumn(col2, val2);
        row.addColumn(col3, val3);

        std::stringstream ss;
        synopsis::GenerateInsertClase(ss, table, row);
        std::string sRes = ss.str();
        QVERIFY(sRes == expected);
    }
}

void Test_synopsis_DataAccessUtils::testCase3_data()
{
    // Test for SQL INSERT clase generator

    // table name
    QTest::addColumn<std::string>("table");

    // #1 column
    //column name
    QTest::addColumn<std::string>("col0");
    //column value
    QTest::addColumn<synopsis::CVariant>("val0");

    // #2 column
    //column name
    QTest::addColumn<std::string>("col1");
    //column value
    QTest::addColumn<synopsis::CVariant>("val1");

    // #3 column
    //column name
    QTest::addColumn<std::string>("col2");
    //column value
    QTest::addColumn<synopsis::CVariant>("val2");

    // #4 column
    //column name
    QTest::addColumn<std::string>("col3");
    //column value
    QTest::addColumn<synopsis::CVariant>("val3");

    //expected result
    QTest::addColumn<std::string>("expected");

    QTest::newRow("int")

            << std::string("tbl")

            << std::string("col0")
            << synopsis::CVariant("str0")

            << std::string("col1")
            << synopsis::CVariant("str1")

            << std::string("col2")
            << synopsis::CVariant(100)

            << std::string("col3")
            << synopsis::CVariant(200)

            << std::string("INSERT INTO tbl (col0, col1, col2, col3) VALUES ('str0', 'str1', 100, 200)");

}
