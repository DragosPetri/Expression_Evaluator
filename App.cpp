#include "ExtendedTest.h"
#include "ShortTest.h"
#include <iostream>
#include "Solver.h"

using namespace std;

int main() {

	testAll();
    testSolver();
	testAllExtended();

	cout << "Test end" << endl;

}