#include "qtmeta.h"
#include "test_row.h"


Test_synopsis_CRow::Test_synopsis_CRow()
{
}

void Test_synopsis_CRow::initTestCase()
{

}

void Test_synopsis_CRow::cleanupTestCase()
{

}

void Test_synopsis_CRow::testCase1()
{
    QFETCH(std::string, column);
    QFETCH(synopsis::CVariant, value);
    QFETCH(int, expected);

    m_row.addColumn(column, value);
    QVERIFY(m_row.getColumnValue(column).ToInt() == expected);
}

void Test_synopsis_CRow::testCase1_data()
{
    QTest::addColumn<std::string>("column");
    QTest::addColumn<synopsis::CVariant>("value");
    QTest::addColumn<int>("expected");

    QTest::newRow("zero")     << std::string("first")  << synopsis::CVariant(0)    <<    0;
    QTest::newRow("positive") << std::string("second") << synopsis::CVariant(100)  <<  100;
    QTest::newRow("negative") << std::string("third")  << synopsis::CVariant(-100) << -100;
}

