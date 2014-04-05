#ifndef TEST_CVariant_H
#define TEST_CVariant_H

#include <base/inc/variant.h>
#include <QTest>


class Test_synopsis_CVariant : public QObject
{
    Q_OBJECT

public:
    Test_synopsis_CVariant();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase1_data();

};


#endif // TEST_CVariant_H
