#include "ExtendedTest.h"
#include "ShortTest.h"
#include <iostream>
#include "Solver.h"

using namespace std;

int main() {

	testAll();
	//testAllExtended();
    Solver s;
    cout<<s.infix_to_postix("10+2-3")<<endl;

	cout << "Test end" << endl;

}