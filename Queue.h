#pragma once
#include <iostream>
#include <tuple>
using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM (-11111)

class Queue
{
private:
	int cap;
    int size;
    int head;
    int first_empty;
    std::tuple<int, TElem> *arr;

public:
	Queue();

	//pushes an element to the end of the queue
	void push(TElem e);
    void print();
	//returns the element from the front of the queue
	//throws exception if the queue is empty
	TElem top() const;

	//removes and returns the element from the front of the queue
	//throws exception if the queue is empty
	TElem pop();

	//checks if the queue is empty
	bool isEmpty() const;

	// destructor
	~Queue();
};
