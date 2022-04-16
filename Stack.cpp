#include "Stack.h"


Stack::Stack() {
    cap = 5;
    size = 0;
    head = nullpt;
    tail = nullpt;
    next_empty = 0;
    arr = new tuple<int,int,TElem>[cap];
    for(int i=0;i<cap;i++)
    {
        arr[i] = make_tuple(NULL_TELEM,NULL_TELEM,NULL_TELEM);
    }
}

Stack::~Stack() {
    delete[] arr;
};

void Stack::Push(TElem e) {

    if (head==nullpt) {

        head = next_empty;
        tail = head;
        next_empty++;
        arr[head] = make_tuple(nullpt,nullpt,e);
        size++;

    } else {

        if (size == cap) resize();

        arr[next_empty] = make_tuple(head,nullpt,e);
        head = next_empty;

        for (int i = 0; i < cap; i++)
            if (get<0>(arr[i]) == NULL_TELEM)
            {
                next_empty = i;
                break;
            }
        size++;
    }

};

TElem Stack::Pop() {
    //TODO IMPLEMENTATION
};

TElem Stack::Peek() {
    //TODO IMPLEMENTATION
};

bool Stack::isEmpty() {
    //TODO IMPLEMENTATION
}

void Stack::resize() {

    cap*=2;
    tuple<int,int,TElem> *aux = new tuple<int,int,TElem>[cap];

    for(int i=0;i<cap;i++)
    {
        aux[i] = make_tuple(NULL_TELEM,NULL_TELEM,NULL_TELEM);
    }

    for (int i = 0; i < size; i++)
        aux[i]=arr[i];

    next_empty = size;

    delete[] arr;
    arr=aux;

};