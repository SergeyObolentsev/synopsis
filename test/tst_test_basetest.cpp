#include <QString>
#include <QtTest>
#include "test_variant.h"
#include "test_row.h"
#include "test_dataaccessutils.h"
#include "test_daopostgres.h"

void test(int& iRes, QObject* pObject, int argc = 0, char **argv = 0)
{
    int iResTest = QTest::qExec(pObject, argc, argv);
    if (iResTest) {
        iRes = -1;
    }
}

int main(int argc, char *argv[])
{
    int iRes = 0;

    {
        Test_synopsis_CVariant tc;
        int iResTest = QTest::qExec(&tc, argc, argv);
        if (iResTest) {
            iRes = -1;
        }
    }

    {
        Test_synopsis_CRow tc;
        int iResTest = QTest::qExec(&tc, argc, argv);
        if (iResTest) {
            iRes = -1;
        }
    }

    {
        Test_synopsis_DataAccessUtils tc;
        int iResTest = QTest::qExec(&tc, argc, argv);
        if (iResTest) {
            iRes = -1;
        }
    }

    Test_synopsis_ConnectionPostgr t4;
    test(iRes, &t4);

    return iRes;

}

