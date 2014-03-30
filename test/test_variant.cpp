#include "test_variant.h"

Test_synopsis_Variant::Test_synopsis_Variant()
{
}

void Test_synopsis_Variant::initTestCase()
{

}

void Test_synopsis_Variant::cleanupTestCase()
{

}

void Test_synopsis_Variant::testCase1()
{
    QFETCH(synopsis::Variant, data);
    QFETCH(int, expected);
    QVERIFY(data.ToInt() == expected);
}

void Test_synopsis_Variant::testCase1_data()
{
    QTest::addColumn<synopsis::Variant>("data");
    QTest::addColumn<int>("expected");

    QTest::newRow("zero")     << synopsis::Variant(0)    <<    0;
    QTest::newRow("positive") << synopsis::Variant(100)  <<  100;
    QTest::newRow("negative") << synopsis::Variant(-100) << -100;
}

