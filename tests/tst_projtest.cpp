#include <QtTest>

// add necessary includes here

class projtest : public QObject
{
    Q_OBJECT
//a
public:
    projtest();
    ~projtest();

private slots:
    void test_case1();

};

projtest::projtest()
{

}

projtest::~projtest()
{

}

void projtest::test_case1()
{

}

QTEST_APPLESS_MAIN(projtest)

#include "tst_projtest.moc"
