#include "qtmeta.h"
#include "test_variant.h"

Test_synopsis_CVariant::Test_synopsis_CVariant()
{
}

void Test_synopsis_CVariant::initTestCase()
{

}

void Test_synopsis_CVariant::cleanupTestCase()
{

}

void Test_synopsis_CVariant::testCase1()
{
    QFETCH(synopsis::CVariant, data);
    QFETCH(int, expected);
    QVERIFY(data.ToInt() == expected);
}

void Test_synopsis_CVariant::testCase1_data()
{
    QTest::addColumn<synopsis::CVariant>("data");
    QTest::addColumn<int>("expected");

    QTest::newRow("zero")     << synopsis::CVariant(0)    <<    0;
    QTest::newRow("positive") << synopsis::CVariant(100)  <<  100;
    QTest::newRow("negative") << synopsis::CVariant(-100) << -100;
}

