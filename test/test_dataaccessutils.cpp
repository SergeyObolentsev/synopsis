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

    QTest::newRow("int") << std::string("id") << synopsis::CVariant(0) << std::string(" WHERE id=0");
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
        synopsis::GenerateInsertClause(ss, table, row);
        std::string sRes = ss.str();
        QVERIFY(sRes == expected);
    }
}

void Test_synopsis_DataAccessUtils::testCase3_data()
{
    // Test for SQL INSERT clause generator

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

void Test_synopsis_DataAccessUtils::testCase4()
{
    // Test for SQL SELECT clause generator
    QFETCH(std::string, table);
    QFETCH(std::string, expected);

    {
        std::stringstream ss;
        synopsis::GenerateSelectClause(ss, table);
        std::string sRes = ss.str();
        QVERIFY(sRes == expected);
    }
}

void Test_synopsis_DataAccessUtils::testCase4_data()
{
    // Test for SQL SELECT clause generator

    // table name
    QTest::addColumn<std::string>("table");

    //expected result
    QTest::addColumn<std::string>("expected");

    QTest::newRow("int")
            << std::string("tbl")
            << std::string("SELECT * FROM tbl");
}

void Test_synopsis_DataAccessUtils::testCase5()
{
    // Test for SQL "SELECT * " clause generator
    QFETCH(std::string, table);
    QFETCH(std::string, expected);
    QFETCH(std::string, col0);
    QFETCH(std::string, col1);
    {
        std::stringstream ss;
        synopsis::TStrings columns;
        columns.push_back(col0);
        columns.push_back(col1);
        synopsis::GenerateSelectClause(ss, table, columns);
        std::string sRes = ss.str();
        QVERIFY(sRes == expected);
    }
}

void Test_synopsis_DataAccessUtils::testCase5_data()
{
    // Test for SQL SELECT + columns list clause generator

    // table name
    QTest::addColumn<std::string>("table");

    // #1 column
    //column name
    QTest::addColumn<std::string>("col0");

    // #2 column
    //column name
    QTest::addColumn<std::string>("col1");

    //expected result
    QTest::addColumn<std::string>("expected");

    QTest::newRow("int")
            << std::string("tbl")
            << std::string("col0")
            << std::string("col1")
            << std::string("SELECT col0, col1 FROM tbl");
}

void Test_synopsis_DataAccessUtils::testCase6()
{
    // Test for SQL SELECT + WHERE clause generator
    QFETCH(std::string, table);
    QFETCH(std::string, expected);
    QFETCH(std::string, col0);
    QFETCH(std::string, col1);
    QFETCH(std::string, col2);
    QFETCH(synopsis::CVariant, val2);
    {
        std::stringstream ss;

        synopsis::TStrings columns;
        columns.push_back(col0);
        columns.push_back(col1);
        columns.push_back(col2);

        synopsis::CRow rowSelection(col2, val2);

        synopsis::GenerateSelectClause(ss, table, columns, rowSelection);
        std::string sRes = ss.str();
        QVERIFY(sRes == expected);
    }
}

void Test_synopsis_DataAccessUtils::testCase6_data()
{
    // Test for SQL SELECT + WHERE clause generator

    // table name
    QTest::addColumn<std::string>("table");

    // #1 column
    //column name
    QTest::addColumn<std::string>("col0");

    // #2 column
    //column name
    QTest::addColumn<std::string>("col1");

    // #3 column
    //column name
    QTest::addColumn<std::string>("col2");
    //column value
    QTest::addColumn<synopsis::CVariant>("val2");



    //expected result
    QTest::addColumn<std::string>("expected");

    QTest::newRow("int")
            << std::string("tbl")
            << std::string("col0")
            << std::string("col1")
            << std::string("col2")
            << synopsis::CVariant(333)
            << std::string("SELECT col0, col1, col2 FROM tbl WHERE col2=333");
}

void Test_synopsis_DataAccessUtils::testCase7()
{
    // Test for SQL SELECT + WHERE clause generator
    QFETCH(std::string, table);
    QFETCH(std::string, expected);
    QFETCH(std::string, col0);
    QFETCH(std::string, col1);
    QFETCH(std::string, col2);
    QFETCH(std::string, col3);
    QFETCH(std::string, col4);

    QFETCH(synopsis::CVariant, val2);
    QFETCH(synopsis::CVariant, val3);
    QFETCH(synopsis::CVariant, val4);

    {
        std::stringstream ss;

        synopsis::TStrings columns;
        columns.push_back(col0);
        columns.push_back(col1);
        columns.push_back(col2);
        columns.push_back(col3);
        columns.push_back(col4);

        synopsis::CRow rowSelection;
        rowSelection.setColumnValue(col2, val2);
        rowSelection.setColumnValue(col3, val3);
        rowSelection.setColumnValue(col4, val4);

        synopsis::GenerateSelectClause(ss, table, columns, rowSelection);
        std::string sRes = ss.str();
        QVERIFY(sRes == expected);
    }
}

void Test_synopsis_DataAccessUtils::testCase7_data()
{
    // Test for SQL SELECT + WHERE clause generator

    // table name
    QTest::addColumn<std::string>("table");

    // #1 column
    //column name
    QTest::addColumn<std::string>("col0");

    // #2 column
    //column name
    QTest::addColumn<std::string>("col1");

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

    // #5 column
    //column name
    QTest::addColumn<std::string>("col4");
    //column value
    QTest::addColumn<synopsis::CVariant>("val4");

    //expected result
    QTest::addColumn<std::string>("expected");

    QTest::newRow("int")
            << std::string("tbl")
            << std::string("col0")
            << std::string("col1")

            << std::string("col2")
            << synopsis::CVariant(333)

            << std::string("col3")
            << synopsis::CVariant("col3 string")

            << std::string("col4")
            << synopsis::CVariant(444)

            << std::string("SELECT col0, col1, col2, col3, col4 FROM tbl WHERE col2=333 AND col3='col3 string' AND col4=444");
}

void Test_synopsis_DataAccessUtils::testCase8()
{
    // Test for SQL SELECT + WHERE + ORDER  clause generator
    QFETCH(std::string, table);
    QFETCH(std::string, expected0);
    QFETCH(std::string, expected1);
    QFETCH(std::string, col0);
    QFETCH(std::string, col1);
    QFETCH(std::string, col2);
    QFETCH(std::string, col3);
    QFETCH(std::string, col4);

    QFETCH(synopsis::CVariant, val2);
    QFETCH(synopsis::CVariant, val3);
    QFETCH(synopsis::CVariant, val4);

    QFETCH(bool, selorder0);
    QFETCH(bool, selorder1);

    {
        synopsis::TStrings columns;
        columns.push_back(col0);
        columns.push_back(col1);
        columns.push_back(col2);
        columns.push_back(col3);
        columns.push_back(col4);

        synopsis::CRow rowSelection;
        rowSelection.setColumnValue(col2, val2);
        rowSelection.setColumnValue(col3, val3);
        rowSelection.setColumnValue(col4, val4);

        synopsis::SelectionOrder selectionOrder;
        selectionOrder.m_bAscent = selorder0;
        selectionOrder.m_Columns.push_back(col0);

        {
            std::stringstream ss;
            synopsis::GenerateSelectClause(ss, table, columns, rowSelection, selectionOrder);
            std::string sRes = ss.str();
            QVERIFY(sRes == expected0);
        }

        {
            selectionOrder.m_bAscent = selorder1;

            selectionOrder.m_Columns.push_back(col1);
            selectionOrder.m_Columns.push_back(col2);
            std::stringstream ss;
            synopsis::GenerateSelectClause(ss, table, columns, rowSelection, selectionOrder);
            std::string sRes = ss.str();
            QVERIFY(sRes == expected1);
        }

    }
}

void Test_synopsis_DataAccessUtils::testCase8_data()
{
    // Test for SQL SELECT + WHERE + ORDER clause generator

    // table name
    QTest::addColumn<std::string>("table");

    // #1 column
    //column name
    QTest::addColumn<std::string>("col0");

    // #2 column
    //column name
    QTest::addColumn<std::string>("col1");

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

    // #5 column
    //column name
    QTest::addColumn<std::string>("col4");
    //column value
    QTest::addColumn<synopsis::CVariant>("val4");

    QTest::addColumn<bool>("selorder0");
    QTest::addColumn<bool>("selorder1");

    // expected result
    QTest::addColumn<std::string>("expected0");
    QTest::addColumn<std::string>("expected1");

    QTest::newRow("int")
            << std::string("tbl")
            << std::string("col0")
            << std::string("col1")

            << std::string("col2")
            << synopsis::CVariant(333)

            << std::string("col3")
            << synopsis::CVariant("col3 string")

            << std::string("col4")
            << synopsis::CVariant(444)

            << true
            << false

            << std::string("SELECT col0, col1, col2, col3, col4" \
                           " FROM tbl WHERE col2=333 AND col3='col3 string' AND col4=444" \
                           " ORDER BY col0 ASC")

            << std::string("SELECT col0, col1, col2, col3, col4" \
                           " FROM tbl WHERE col2=333 AND col3='col3 string' AND col4=444" \
                           " ORDER BY col0, col1, col2 DESC");
}

void Test_synopsis_DataAccessUtils::testCase9()
{
    // Test for SQL SELECT clause generator
    QFETCH(std::string, table);
    QFETCH(std::string, expected);

    {
        std::stringstream ss;
        synopsis::GenerateDeleteClause(ss, table);
        std::string sRes = ss.str();
        QVERIFY(sRes == expected);
    }
}

void Test_synopsis_DataAccessUtils::testCase9_data()
{
    // Test for SQL DELETE clause generator

    // table name
    QTest::addColumn<std::string>("table");

    //expected result
    QTest::addColumn<std::string>("expected");

    QTest::newRow("int")
            << std::string("tbl")
            << std::string("DELETE FROM tbl");
}

void Test_synopsis_DataAccessUtils::testCase10()
{
    // Test for SQL SELECT clause generator
    QFETCH(std::string, table);
    QFETCH(std::string, expected);

    QFETCH(std::string, col0);
    QFETCH(std::string, col1);

    QFETCH(synopsis::CVariant, val0);
    QFETCH(synopsis::CVariant, val1);

    {
        std::stringstream ss;

        synopsis::CRow row;
        row.setColumnValue(col0, val0);
        row.setColumnValue(col1, val1);

        synopsis::GenerateDeleteClause(ss, table, row);
        std::string sRes = ss.str();
        QVERIFY(sRes == expected);
    }
}

void Test_synopsis_DataAccessUtils::testCase10_data()
{
    // Test for SQL DELETE clause generator

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

    //expected result
    QTest::addColumn<std::string>("expected");

    QTest::newRow("int")
            << std::string("tbl")

            << std::string("col0")
            << synopsis::CVariant(444)

            << std::string("col1")
            << synopsis::CVariant("col1 string")

            << std::string("DELETE FROM tbl WHERE col0=444 AND col1='col1 string'");
}

void Test_synopsis_DataAccessUtils::testCase11()
{
    // Test for SQL SELECT clause generator
    QFETCH(std::string, table);
    QFETCH(std::string, expected);

    QFETCH(std::string, col0);
    QFETCH(std::string, col1);

    QFETCH(synopsis::CVariant, val0);
    QFETCH(synopsis::CVariant, val1);

    QFETCH(std::string, filt_col0);
    QFETCH(std::string, filt_col1);

    QFETCH(synopsis::CVariant, filt_val0);
    QFETCH(synopsis::CVariant, filt_val1);

    {
        synopsis::CRow rowUpdate;
        rowUpdate.setColumnValue(col0, val0);
        rowUpdate.setColumnValue(col1, val1);

        synopsis::CRow rowSelection;
        rowSelection.setColumnValue(filt_col0, filt_val0);
        rowSelection.setColumnValue(filt_col1, filt_val1);

        std::stringstream ss;
        synopsis::GenerateUpdateClause(ss, table, rowUpdate, rowSelection);
        std::string sRes = ss.str();
        QVERIFY(sRes == expected);
    }
}

void Test_synopsis_DataAccessUtils::testCase11_data()
{
    // Test for SQL UPDATE + WHERE clause generator

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

    // filter columns
    // #1 filter column
    //column name
    QTest::addColumn<std::string>("filt_col0");
    //column value
    QTest::addColumn<synopsis::CVariant>("filt_val0");

    // #2 filter column
    //column name
    QTest::addColumn<std::string>("filt_col1");
    //column value
    QTest::addColumn<synopsis::CVariant>("filt_val1");

    //expected result
    QTest::addColumn<std::string>("expected");

    QTest::newRow("int")
            << std::string("tbl")
            << std::string("col0")
            << synopsis::CVariant(555)
            << std::string("col1")
            << synopsis::CVariant("col1 string")

            << std::string("id")
            << synopsis::CVariant(777)

            << std::string("col3")
            << synopsis::CVariant("col3 filter string")

            << std::string("UPDATE tbl SET col0=555, col1='col1 string' WHERE col3='col3 filter string' AND id=777");
}

void Test_synopsis_DataAccessUtils::testCase12()
{
    // Test for SQL SELECT clause generator
    QFETCH(std::string, table);
    QFETCH(std::string, expected);

    QFETCH(std::string, filt_col0);
    QFETCH(std::string, filt_col1);

    QFETCH(synopsis::CVariant, filt_val0);
    QFETCH(synopsis::CVariant, filt_val1);

    {
        synopsis::CRow rowSelection;
        rowSelection.setColumnValue(filt_col0, filt_val0);
        rowSelection.setColumnValue(filt_col1, filt_val1);

        std::stringstream ss;
        synopsis::GenerateDeleteClause(ss, table, rowSelection);
        std::string sRes = ss.str();
        QVERIFY(sRes == expected);
    }

}

void Test_synopsis_DataAccessUtils::testCase12_data()
{
    // Test for SQL DELETE + WHERE clause generator

    // table name
    QTest::addColumn<std::string>("table");

    // filter columns
    // #1 filter column
    //column name
    QTest::addColumn<std::string>("filt_col0");
    //column value
    QTest::addColumn<synopsis::CVariant>("filt_val0");

    // #2 filter column
    //column name
    QTest::addColumn<std::string>("filt_col1");
    //column value
    QTest::addColumn<synopsis::CVariant>("filt_val1");

    //expected result
    QTest::addColumn<std::string>("expected");

    QTest::newRow("int")
            << std::string("tbl")

            << std::string("id")
            << synopsis::CVariant(777)

            << std::string("col3")
            << synopsis::CVariant("col3 filter string")

            << std::string("DELETE FROM tbl WHERE col3='col3 filter string' AND id=777");
}
