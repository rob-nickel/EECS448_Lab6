#include <iostream>
#include <string>
#include "Node.h"
#include "LinkedListOfInts.h"
#include "List.h"

#ifndef TEST_H
#define TEST_H

class test
{
public:
        test();

        //calls test methods
        void runTests();

private:
        LinkedListOfInts testList;
        void result(bool boolean);
        void error();
        void test01();
        void test02();
        void test03();
        void test04();
        void test05();
        void test06();
        void test07();
        void test08();
        void test09();
        void test10();
        void test11();
        void test12();
        void test13();
        void test14();
        void test15();
        void test16();
};
#endif
