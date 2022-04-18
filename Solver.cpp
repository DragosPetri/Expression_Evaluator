#include "Solver.h"

int Solver::isoperator(string c) {

    if ( c=="^")
        return 3;
    else if (c=="*" || c=="/")
        return 2;
    else if (c=="+" || c=="-")
        return 1;
    else
        return -1;

    /*
    * Θ(1)
    */

}

string Solver::infix_to_postix(string infix) {

    Stack s;
    string postfix;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            string s1(1,c);
            s.Push(s1);
        }
        else if (c == ')')
        {
            string s1(1,'(');
            while (s.Peek() != s1)
            {
                postfix += s.Peek();
                postfix += " ";
                if(!s.isEmpty()) s.Pop();
            }
            s.Pop();
        }
        else {
            postfix += " ";
            string s2(1, infix[i]);
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
            string s1(1,c);
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

    /*
     * n = length of the string 'infix'
     * Best Case: Θ(n)
     * Worst case: Θ(n)
     * Average Case: Θ(n)
     */
}

string Solver::eval_postfix(string postfix) {

    Stack s;
    string num;

    for (int i = 0; i < postfix.length() ; i++) {

            if (isalnum(postfix[i])) {
               num.push_back(postfix[i]);
            } else {
                if (num!="")
                s.Push(num);
                num="";
                if (postfix[i]!=' ') {
                    string val1 = s.Pop();
                    string val2 = s.Pop();
                    switch (postfix[i])
                    {
                        case '+':
                            s.Push(to_string((stoi(val2) + stoi(val1))));
                            break;
                        case '-':
                            s.Push(to_string((stoi(val2) - stoi(val1))));
                            break;
                        case '*':
                            s.Push(to_string((stoi(val2) * stoi(val1))));
                            break;
                        case '/':
                            s.Push(to_string((stoi(val2) / stoi(val1))));
                            break;
                        case '^' :
                            s.Push(to_string(int(pow(stoi(val2),stoi(val1)))));
                            break;
                    }
                }

            }

    }

    /*
     * n = length of the string 'postfix'
     * Best Case: Θ(n)
     * Worst case: Θ(n)
     * Average Case: Θ(n)
     */

    return s.Pop();
}
