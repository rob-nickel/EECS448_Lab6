/**
*	@author Rob Nickel
*	@date October 31, 2018
*	@file main.cpp
*	@brief driver for LinkedList demo
*/
#include <iostream>
#include "LinkedListOfInts.h"
#include "test.h"

int main(int argc, char** argv)
{

	std::cout << "Running..." << std::endl << std::endl;

	test myTester;
	myTester.runTests();


	std::cout << "And we're done.\nGoodbye.\n";

	return (0);

}
