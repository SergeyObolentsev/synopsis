#ifndef TEST_ROW_H
#define TEST_ROW_H

#include <dao/inc/row.h>
#include <QTest>


class Test_synopsis_CRow : public QObject
{
    Q_OBJECT

public:
    Test_synopsis_CRow();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase1_data();

private:
    synopsis::CRow m_row;
};


#endif // TEST_ROW_H
