#ifndef TEST_DATAACCESSUTILS_H
#define TEST_DATAACCESSUTILS_H

#include <QTest>

class Test_synopsis_DataAccessUtils : public QObject
{
    Q_OBJECT

public:
    Test_synopsis_DataAccessUtils();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase1_data();
    void testCase2();
    void testCase2_data();
    void testCase3();
    void testCase3_data();
};



#endif // TEST_DATAACCESSUTILS_H
