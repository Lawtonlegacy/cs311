// Andrew Player, Robert Lawton, Gannon Higgins
// Project 8 
// 11/30/2020
// Source for Project 8, Part B


// squarer_test.cpp  
// Glenn G. Chappell
// 2020-11-20
//
// For CS 311 Fall 2020
// Test program for class Squarer
// For Project 8, Exercise B
// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, squarer.h

// Includes for code to be tested
#include "squarer.h"         // For class Squarer
#include "squarer.h"         // Double-inclusion check, for testing only

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT
                             // We write our own main
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
                             // Reduce compile time
#include "doctest.h"         // For doctest

// Includes for all test programs
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;

// Additional includes for this test program
// NONE

// Printable name for this test suite
const std::string test_suite_name =
"class Squarer"
" - CS 311 Proj 8, Ex B";


// *********************************************************************
// Test Cases
// *********************************************************************

TEST_CASE("Squarer: positive ints")
{
	Squarer sq;

	SUBCASE("Square 0") {
		INFO("0 squared is 0");
		REQUIRE(sq(0) == 0);
	}

	SUBCASE("Square 1") {
		INFO("1 squared is 1");
		REQUIRE(sq(1) == 1);
	}

	SUBCASE("Square 5") {
		INFO("5 squared is 25");
		REQUIRE(sq(5) == 25);
	}

	SUBCASE("Square 7829") {
		INFO("7829 squared is 61293241");
		REQUIRE(sq(7829) == 61293241);
	}
}

TEST_CASE("Squarer: negative ints")
{
	Squarer sq;

	SUBCASE("Square -1") {
		INFO("-1 squared is 1");
		REQUIRE(sq(-1) == 1);
	}

	SUBCASE("Square -5") {
		INFO("-5 squared is 25");
		REQUIRE(sq(-5) == 25);
	}

	SUBCASE("Square -7829") {
		INFO("-7829 squared is 61293241");
		REQUIRE(sq(-7829) == 61293241);
	}
}


TEST_CASE("Squarer: doubles") 
{
	Squarer sq;

	SUBCASE("Square 1.1") {
		INFO("1.1 squared is 1.21");
		REQUIRE(sq(1.1) == doctest::Approx(1.21));
	}

	SUBCASE("Square 18.23") {
		INFO("18.23 squared is 332.3329");
		REQUIRE(sq(18.23) == doctest::Approx(332.3329));
	}

	SUBCASE("Square 100.50") {
		INFO("100.50 squared is 10100.25");
		REQUIRE(sq(100.50) == doctest::Approx(10100.25));
	}
}

TEST_CASE("Squarer: negative doubles")
{
	Squarer sq;

	SUBCASE("Square -1.1") {
		INFO("-1.1 squared is 1.21");
		REQUIRE(sq(-1.1) == doctest::Approx(1.21));
	}

	SUBCASE("Square -18.23") {
		INFO("-18.23 squared is 332.3329");
		REQUIRE(sq(-18.23) == doctest::Approx(332.3329));
	}

	SUBCASE("Square -100.50") {
		INFO("-100.50 squared is 10100.25");
		REQUIRE(sq(-100.50) == doctest::Approx(10100.25));
	}
}


TEST_CASE("Squarer: const types") 
{
	const Squarer sq;

	SUBCASE("Square 5") {
		INFO("5 squared is 25");
		REQUIRE(sq(5) == 25);
	}

	SUBCASE("Square -7829") {
		INFO("-7829 squared is 61293241");
		REQUIRE(sq(-7829) == 61293241);
	}

	SUBCASE("Square 18.23") {
		INFO("18.23 squared is 332.3329");
		REQUIRE(sq(18.23) == doctest::Approx(332.3329));
	}

	SUBCASE("Square -100.50") {
		INFO("-100.50 squared is 10100.25");
		REQUIRE(sq(-100.50) == doctest::Approx(10100.25));
	}
}



// *********************************************************************
// Main Program
// *********************************************************************


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n');
}


// Main program
// Run all tests. Prompt for ENTER before exiting.
int main(int argc,
    char* argv[])
{
    doctest::Context dtcontext;
    // Primary doctest object
    int dtresult;            // doctest return code; for return by main

    // Handle command line
    dtcontext.applyCommandLine(argc, argv);
    dtresult = 0;            // doctest flags no command-line errors
                             //  (strange but true)

    if (!dtresult)           // Continue only if no command-line error
    {
        // Run test suites
        cout << "BEGIN tests for " << test_suite_name << "\n" << endl;
        dtresult = dtcontext.run();
        cout << "END tests for " << test_suite_name << "\n" << endl;
    }

    // If we want to do something else here, then we need to check
    // context.shouldExit() first.

    // Wait for user
    std::cout << "Press ENTER to quit ";
    userPause();

    // Program return value is return code from doctest
    return dtresult;
}