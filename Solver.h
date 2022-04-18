#include <string>
#include "Stack.h"
#include <iostream>

class Solver {

private:


public:
    Solver();
    ~Solver();

    int isoperator (string c);

    string infix_to_postix(string infix);
    string eval_postfix(string postfix);

};