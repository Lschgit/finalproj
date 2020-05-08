#include <QtTest>
#include <iostream>
#include <vector>
#include <string>
#include "shop.h"

// add necessary includes here

class projtest : public QObject
{
    Q_OBJECT
//aa
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
    shop testshop(0);
    std::string petTest = "Cat";
    std::string petTest2 = "Cat";
    testshop.insertPetType(petTest);//inserts petTest into the shop's vector of pets
    std::string result = "";
    result = testshop.checkPetTypes(petTest2);//checks if petTest2 matches any elements of the shop's vector of pets

    QCOMPARE(petTest, result);
    //will only pass if petTest and the result from the checkPetTypes function are the same,
    //with petTest2 being the input used in the function
    //will be used later to check if a certain shop sells a certain type of pet
}

QTEST_APPLESS_MAIN(projtest)

#include "tst_projtest.moc"
