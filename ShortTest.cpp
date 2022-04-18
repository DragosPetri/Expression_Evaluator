#include "ShortTest.h"
#include "Queue.h"
#include <assert.h>
#include "Stack.h"
#include "Solver.h"

void testAll() { 
	Queue q;
	assert(q.isEmpty() == true);
	q.push(5);
	q.push(1);
	q.push(10);
	assert(q.isEmpty() == false);
	assert(q.top() == 5);
	assert(q.pop() == 5);
	assert(q.top() == 1);
	assert(q.pop() == 1);
	assert(q.top() == 10);
	assert(q.pop() == 10);
	assert(q.isEmpty() == true);

    Stack s;
    assert(s.isEmpty());
    s.Push("5");
    s.Push("1");
    s.Push("10");
    assert(s.isEmpty() == false);
    assert(s.Peek() == "10");
    assert(s.Pop() == "10");
    assert(s.Peek() == "1");
    assert(s.Pop() == "1");
    assert(s.Peek() == "5");
    assert(s.Pop() == "5");
    assert(s.isEmpty() == true);
}

void testSolver(){

    Solver s;
    string s1 = s.infix_to_postix("7^2+5+12-5+4/2");
    assert(s.eval_postfix(s1)=="63");
    s1 = "100 200 + 2 / 5 * 7 +";
    assert(s.eval_postfix(s1)=="757");
    s1 = s.infix_to_postix("3^3+4^2-16-37");
    assert(s.eval_postfix(s1)=="-10");

    cout<<"Solver Test end!"<<'\n';
}