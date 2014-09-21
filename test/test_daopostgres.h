#ifndef TEST_DAOPOSTGRES_H
#define TEST_DAOPOSTGRES_H

#include <auto_ptr.h>

#include <QTest>

#include <dao/drivers/postgres/inc/connection_postgr.h>
#include <dao/drivers/postgres/inc/dataaccessor_postgr.h>

class Test_synopsis_ConnectionPostgr : public QObject
{
    Q_OBJECT

public:
    Test_synopsis_ConnectionPostgr();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase1_data();
    void testCase2();
    void testCase2_data();
    void testCase3();
    void testCase3_data();
    void testCase4();
    void testCase4_data();

private:
    synopsis::ConnectionPostgr m_Connection;
    std::auto_ptr<synopsis::CDataAccessorPostgr> m_PtrDataAccessor;

    unsigned long m_ulLastRowId;
};


#endif // TEST_DAOPOSTGRES_H
