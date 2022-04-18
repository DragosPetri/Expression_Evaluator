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
    string postfix;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isalnum(c))
        {
            postfix += c;
            postfix += " ";
        }
        else if (c == '(')
        {
            std::string s1(1,c);
            s.Push(s1);
        }
        else if (c == ')')
        {
            std::string s1(1,'(');
            while (s.Peek() != s1){
                postfix += s.Peek();
                postfix += " ";
                if(!s.isEmpty()) s.Pop();
            }
            s.Pop();
        }
        else {
            std::string s2(1, infix[i]);
            while (!s.isEmpty() && isoperator(s2) <= isoperator(s.Peek()))
            {
                if (c == '^' && s.Peek() == "^")
                    break;
                else
                {
                    postfix += s.Peek();
                    postfix += " ";
                    s.Pop();
                }
            }
            std::string s1(1,c);
            s.Push(s1);
        }
    }

    while (!s.isEmpty())
    {
        postfix += s.Peek();
        postfix += " ";
        s.Pop();
    }

    return postfix;
}

string Solver::eval_postfix(string postfix) {
    return std::string();
}
