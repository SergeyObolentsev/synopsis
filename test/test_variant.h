#ifndef TEST_VARIANT_H
#define TEST_VARIANT_H

#include "../base/inc/variant.h"
#include <QTest>

Q_DECLARE_METATYPE(synopsis::Variant)

class Test_synopsis_Variant : public QObject
{
    Q_OBJECT

public:
    Test_synopsis_Variant();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase1_data();

};


#endif // TEST_VARIANT_H
