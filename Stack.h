#pragma once
#include <tuple>
#include <exception>
#include <string>
using namespace std;

//DO NOT CHANGE THIS PART
typedef string TElem2;
#define NULL_TELEM (-1111)
#define NULL_STRING ("")
#define nullpt (-1)
#define next_e (1)
#define prev_e (0)
#define element (2)


class Stack
{

private:
    int cap;
    int size;
    int head;
    int tail;
    int next_empty;
    std::tuple<int,int,TElem2> *arr;
    void resize();

public:
    //constructor
    Stack();

    //destructor
    ~Stack();

    // Pushes Element on top of stack
    void Push(TElem2 e);

    // Pop (takes out) Element from the top of the stack
    //throws exception if the stack is empty
    TElem2 Pop();

    // returns the value on top of the stack without taking it out
    //throws exception if the stack is empty
    TElem2 Peek();

    // checks if the stack is empty
    bool isEmpty();
};
