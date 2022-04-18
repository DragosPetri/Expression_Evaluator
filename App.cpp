#include "ExtendedTest.h"
#include "ShortTest.h"
#include <iostream>
#include "Solver.h"

using namespace std;

int main() {

	testAll();
	//testAllExtended();
    Solver s;
    cout<<s.infix_to_postix("a+b*(c^d-e)^(f+g*h)-i")<<endl;

	cout << "Test end" << endl;

}