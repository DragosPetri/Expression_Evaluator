#include "Solver.h"

Solver::Solver() {

}

Solver::~Solver() {

}

int Solver::isoperator(string c) {
    if ( c=="^")
        return 3;
    else if (c=="*" || c=="/")
        return 2;
    else if (c=="+" || c=="-")
        return 1;
    else
        return -1;
}

string Solver::infix_to_postix(string infix) {
    Stack s;

    string postfix = "";//string unde  ne salvam rezultatul

    for(int i=0;i<infix.length();i++)
    { //parcurgem expresia in infix
        char c = infix.at(i);
        if (isalnum(c))
            postfix += c;
        else if (c == '(')
            s.Push(to_string(c));
        else if (c == ')') {
            while (s.Peek() != "(") {
                postfix += s.Peek();
                s.Pop();
            }
            s.Pop();
        }
    }
    return postfix;
}

string Solver::eval_postfix(string postfix) {
    return std::string();
}
