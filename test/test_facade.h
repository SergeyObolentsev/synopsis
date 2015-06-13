#ifndef TEST_FACADE_H
#define TEST_FACADE_H

#include <auto_ptr.h>

#include <QTest>

namespace synopsis {
class IDataAccessor;
}

class Test_synopsis_Facade : public QObject
{
    Q_OBJECT

public:
    Test_synopsis_Facade();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();

private:
    std::auto_ptr<synopsis::IDataAccessor> m_ptrDataAccessor;
};

#endif // TEST_FACADE_H



