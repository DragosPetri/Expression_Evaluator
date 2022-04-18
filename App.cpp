#include "ExtendedTest.h"
#include "ShortTest.h"
#include <iostream>
#include "Solver.h"

using namespace std;

int main() {

	testAll();
	//testAllExtended();
    Solver s;
    string s1 = s.infix_to_postix("9-5");
    cout<<s.eval_postfix(s1)<<'\n';

	cout << "Test end" << endl;

}