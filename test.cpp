#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "LinkedListOfInts.h"
#include "test.h"
#include "Node.h"
#include "List.h"
using namespace std;

test::test(){}

void test::runTests()
{
        test01();
        test02();
        test03();
        test04();
        test05();
        test06();
        test07();
        test08();
        test09();
        test10();
        test11();
        test12();
        test13();
        test14();
        test15();
        test16();
}

void test::result(bool boolean)
{
        if (boolean){
                cout << "    PASSED" << endl << endl;
        }
        else{
                cout << "    ***** FAILED *****" << endl << endl;
        }
}

void test::error()
{
        cout << "    ERROR" << endl << endl;
}

void test::test01()
{
        cout << "Test 01: verifies new list from constructor is empty" << endl;
        LinkedListOfInts testList;
        vector<int> testVector = testList.toVector();
        result(testVector.empty());
}

void test::test02()
{
        cout << "Test 02: verifies that isEmpty() returns true on an empty list" << endl;
        LinkedListOfInts testList;
        result(testList.isEmpty());
}

void test::test03()
{
        cout << "Test 03: verifies that isEmpty() returns false on a nonempty list" << endl;
        LinkedListOfInts testList;
        testList.addFront(5);
        testList.addFront(28);
        testList.addFront(12);
        vector<int> testVector = testList.toVector();
        if (testVector.size() > 0)
                result(!(testList.isEmpty()));
        else{
                error();
                cout << "    The vector was: ";
                for (int i=0; i < testVector.size(); i++)
                        cout << testVector.at(i) << " ";
        }
}

void test::test04()
{
        cout << "Test 04: verifies that size() returns the number of elements in a list for empty and nonempty lists" << endl;
        LinkedListOfInts testList;
        vector<int> testVector1 = testList.toVector();
        cout << "  empty list:    ";
        if (testVector1.size() == 0){
                result(testList.size() == 0);
        }
        else{
                error();
                cout << "    The vector was: ";
                for (int i=0; i < testVector1.size(); i++)
                        cout << testVector1.at(i) << " ";
        }
        testList.addFront(5);
        vector<int> testVector2 = testList.toVector();
        cout << "  list of 1: ";
        if (testVector2.size() == 1){
                result(testList.size() == 1);
        }
        else{
                error();
                cout << "    The vector was: ";
                for (int i=0; i < testVector2.size(); i++)
                        cout << testVector2.at(i) << " ";
        }
        testList.addFront(28);
        testList.addFront(12);
        vector<int> testVector3 = testList.toVector();
        cout << "  nonempty list: ";
        if (testVector3.size() == 3){
                result(testList.size() == 3);
        }
        else{
                error();
                cout << "    The vector was: ";
                for (int i=0; i < testVector3.size(); i++)
                        cout << testVector3.at(i) << " ";
        }
}

void test::test05()
{
        cout << "Test 05: verifies that search() returns false if the list is empty or if the value matches nothing in the list" << endl;
        LinkedListOfInts testList;
        cout << "  empty list:    ";
        result(!(testList.search(1)));
        testList.addFront(5);
        testList.addFront(28);
        testList.addFront(12);
        cout << "  nonempty list: ";
        result(!(testList.search(22)));
}

void test::test06()
{
        cout << "Test 06: verifies that search() returns true if the value matches something in the list and the front, middle, and end" << endl;
        LinkedListOfInts testList;
        testList.addFront(5);
        testList.addFront(28);
        testList.addFront(12);
        vector<int> testVector = testList.toVector();
        if ((testVector.at(0) == 12) && (testVector.at(1) == 28) && (testVector.size()==3) && (testVector.at(2) == 5)){
                cout << endl << "  front : ";
                if (find(testVector.begin(), testVector.end(), 12) != testVector.end())
                        result(testList.search(12));
                else{
                        error();
                        cout << "    The vector was: ";
                        for (int i=0; i < testVector.size(); i++)
                                cout << testVector.at(i) << " ";
                }
                cout << "  middle: ";
                if (find(testVector.begin(), testVector.end(), 28) != testVector.end())
                        result(testList.search(12));
                else{
                        error();
                        cout << "    The vector was: ";
                        for (int i=0; i < testVector.size(); i++)
                                cout << testVector.at(i) << " ";
                }
                cout << "  end:    ";
                if (find(testVector.begin(), testVector.end(), 5) != testVector.end())
                        result(testList.search(12));
                else{
                        error();
                        cout << "    The vector was: ";
                        for (int i=0; i < testVector.size(); i++)
                                cout << testVector.at(i) << " ";
                }
        }
        else{
                error();
                cout << "    The vector was: ";
                for (int i=0; i < testVector.size(); i++)
                        cout << testVector.at(i) << " ";
        }
}

void test::test07()
{
        cout << "Test 07: verifies that addBack adds a new element to an empty list" << endl;
        LinkedListOfInts testList;
        testList.addBack(5);
        vector<int> testVector = testList.toVector();
        result(testVector.at(0)==5 && testVector.size()==1);
}

void test::test08()
{
        cout << "Test 08: verifies that addBack adds a new element on the back of a nonempty list" << endl;
        LinkedListOfInts testList;
        testList.addBack(5);
        testList.addBack(28);
        testList.addBack(12);
        vector<int> testVector = testList.toVector();
        if (testVector.at(0)==12 && testVector.at(1)==28 && testVector.at(2)==5)
                cout << "    <added to the front>";
        result(testVector.at(2)==12 && testVector.at(1)==28 && testVector.at(0)==5 && testVector.size()==3);
}

void test::test09()
{
        cout << "Test 09: verifies that addFront adds a new element to an empty list" << endl;
        LinkedListOfInts testList;
        testList.addFront(5);
        vector<int> testVector = testList.toVector();
        result(testVector.at(0)==5 && testVector.size()==1);
}

void test::test10()
{
        cout << "Test 10: verifies that addFront adds a new element to the front of the list" << endl;
        LinkedListOfInts testList;
        testList.addFront(5);
        testList.addFront(28);
        testList.addFront(12);
        vector<int> testVector = testList.toVector();
        if (testVector.at(2)==12 && testVector.at(1)==28 && testVector.at(3)==5)
                cout << "<added to the back>";
        result(testVector.at(0)==12 && testVector.at(1)==28 && testVector.at(2)==5 && testVector.size()==3);
}

void test::test11()
{
        cout << "Test 11: verifies that removeBack returns false on an empty list" << endl;
        LinkedListOfInts testList;
        vector<int> testVector = testList.toVector();
        result(!(testList.removeBack()) && testVector.size() == 0);
}

void test::test12()
{
        cout << "Test 12: verifies that removeBack removes the only element from a list of length 1" << endl;
        LinkedListOfInts testList;
        testList.addFront(5);
        vector<int> testVector = testList.toVector();
        if (testVector.size() == 1){
                testList.removeBack();
                vector<int> testVector2 = testList.toVector();
                result(testVector2.size()==0);
        }
        else{
                error();
                cout << "    The vector was: ";
                for (int i=0; i < testVector.size(); i++)
                        cout << testVector.at(i) << " ";
        }
}

void test::test13()
{
        cout << "Test 13: verifies that removeBack removes the last element from a list of length > 1" << endl;
        LinkedListOfInts testList;
        testList.addFront(5);
        testList.addFront(28);
        testList.addFront(12);
        vector<int> intermediateVector = testList.toVector();
        if ((intermediateVector.at(0) == 12) && (intermediateVector.at(1) == 28) && intermediateVector.size()==3 && (intermediateVector.at(2) == 5)){
                testList.removeBack();
                vector<int> testVector = testList.toVector();
                result((testVector.at(0) == 12) && (testVector.at(1) == 28) && testVector.size()==2);
        }
        else{
                error();
                cout << "    The vector was: ";
                for (int i=0; i < intermediateVector.size(); i++)
                        cout << intermediateVector.at(i) << " ";
        }
}

void test::test14()
{
        cout << "Test 14: verifies that removeFront returns false on an empty list" << endl;
        LinkedListOfInts testList;
        result(!(testList.removeFront()));
}

void test::test15()
{
        cout << "Test 15: verifies that removeFront removes the only element from a list of length 1" << endl;
        LinkedListOfInts testList;
        testList.addFront(5);
        testList.removeFront();
        vector<int> testVector = testList.toVector();
        if (testVector.size() == 1){
                testList.removeFront();
                vector<int> testVector2 = testList.toVector();
                result(testVector2.size()==0);
        }
        else{
                error();
                cout << "    The vector was: ";
                for (int i=0; i < testVector.size(); i++)
                        cout << testVector.at(i) << " ";
        }
}

void test::test16()
{
        cout << "Test 16: verifies that removeFront removes the last element from a list of length > 1" << endl;
        LinkedListOfInts testList;
        testList.addFront(5);
        testList.addFront(28);
        testList.addFront(12);
        vector<int> intermediateVector = testList.toVector();
        if ((intermediateVector.at(0) == 12) && (intermediateVector.at(1) == 28) && intermediateVector.size()==3 && (intermediateVector.at(2) == 5)){
                testList.removeFront();
                vector<int> testVector = testList.toVector();
                result((testVector.at(0) == 12) && (testVector.at(1) == 28) && testVector.size()==2);
        }
        else{
                error();
                cout << "    The vector was: ";
                for (int i=0; i < intermediateVector.size(); i++)
                        cout << intermediateVector.at(i) << " ";
        }
}
