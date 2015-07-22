#include <iostream>
#include <QString>
#include <QtTest>
#include "test_variant.h"
#include "test_row.h"
#include "test_dataaccessutils.h"
#include "test_daopostgres.h"
#include "test_facade.h"


template <typename T>
void test(int& iRes, int argc = 0, char **argv = 0)
{
    T testCase;
    int iResTest = QTest::qExec(&testCase, argc, argv);
    if (iResTest) {
        iRes = -1;
    }
}

int main(int argc, char *argv[])
{
    int iRes = 0;

    test<Test_synopsis_CVariant>(iRes);
    test<Test_synopsis_CRow>(iRes);
    test<Test_synopsis_DataAccessUtils>(iRes);
    test<Test_synopsis_ConnectionPostgr>(iRes);
    //test<Test_synopsis_Facade>(iRes);

    std::cout << "TEST "
              << (iRes ? "FAILED": "PASSED")
              << std::endl;

    return iRes;

}

