#pragma once
#include <tuple>
using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM (-11111)


class Stack
{

private:
    int cap;
    int size;
    int head;
    int tail;
    int next_empty;
    std::tuple<int,int,TElem> *arr;
//piciorus

public:
    //constructor
    Stack();

    //destructor
    ~Stack();

    // Pushes Element on top of stack
    void Push(TElem e);

    // Pop (takes out) Element from the top of the stack
    //throws exception if the stack is empty
    TElem Pop();

    // returns the value on top of the stack without taking it out
    //throws exception if the stack is empty
    TElem Peek();

    // checks if the stack is empty
    bool isEmpty();
};
