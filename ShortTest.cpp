#include "ShortTest.h"
#include "Queue.h"
#include <assert.h>
#include "Stack.h"

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
    s.Push(5);
    s.Push(1);
    s.Push(10);
    assert(s.isEmpty() == false);
    assert(s.Peek() == 10);
    assert(s.Pop() == 10);
    assert(s.Peek() == 1);
    assert(s.Pop() == 1);
    assert(s.Peek() == 5);
    assert(s.Pop() == 5);
    assert(s.isEmpty() == true);
}