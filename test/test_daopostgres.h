#ifndef TEST_DAOPOSTGRES_H
#define TEST_DAOPOSTGRES_H

#include <dao/drivers/postgres/inc/connection_postgr.h>

#include <QTest>


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

private:
    synopsis::ConnectionPostgr m_conn;
};


#endif // TEST_DAOPOSTGRES_H
