#include "Queue.h"
#include <exception>
#include <iostream>
#include <tuple>

using namespace std;

Queue::Queue() {

    cap=5;
    size=0;
    head=-1;
    arr = new tuple<int,TElem>[cap];
    for(int i=0;i<cap;i++)
    {
        get<1>(arr[i]) = NULL_TELEM;
        get<0>(arr[i]) = NULL_TELEM;
    }
    first_empty=0;
}


void Queue::push(TElem elem) {

    if(size==cap)
    {
        tuple<int,TElem> *aux;
        cap*=2;
        aux = new tuple<int,TElem>[cap];

        for(int i=0;i<cap;i++)
        {
            get<0>(aux[i])=NULL_TELEM;
            get<1>(aux[i])=NULL_TELEM;
        }

        for (int i = 0; i < size; i++)
            aux[i]=arr[i];

        first_empty = size;

        delete[] arr;
        arr=aux;
    }

    if ( head == -1 )

    {
        get<1>(arr[first_empty])=elem;
        get<0>(arr[first_empty])=-1;
        head=first_empty;
        first_empty=first_empty+1;
        size++;
    }
    else
    {
        int nod = head;
        while (get<0>(arr[nod]) != -1)
        {
            nod = get<0>(arr[nod]);
        }

        get<0>(arr[nod]) = first_empty;
        get<1>(arr[first_empty]) = elem;
        get<0>(arr[first_empty]) = -1;

        for (int i = 0; i < cap; i++)
            if (get<0>(arr[i]) == NULL_TELEM)
            {
                first_empty = i;
                break;
            }
        size++;
    }

}



TElem Queue::top() const {

    if(isEmpty())
        throw exception();
    return get<1>(arr[head]);
}

TElem Queue::pop() {

    if(isEmpty())
        throw exception();

    TElem sters = top();

    if(size==1)
    {
        get<0>(arr[head]) = NULL_TELEM;
        get<1>(arr[head]) = NULL_TELEM;
        head=-1;
        first_empty=0;
        size--;
    }
    else
    {

        int old_pos = head;
        first_empty = head;
        head = get<0>(arr[head]);
        get<0>(arr[old_pos]) = NULL_TELEM;
        get<1>(arr[old_pos]) = NULL_TELEM;
        size--;
    }




    return sters;

}
void Queue::print() {
    for (int i = 0; i <= size; i++)
        cout<<get<1>(arr[i])<<" ";

}
bool Queue::isEmpty() const {

    if(size==0)
        return true;
    return false;

}


Queue::~Queue() {

    delete[] arr;

}
