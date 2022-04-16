#include "Queue.h"
#include <exception>
#include <iostream>
#include <tuple>

using namespace std;


Queue::Queue() {
	//TODO - Implementation
    cap=5;
    size=0;
    head=-1;
    arr = new tuple<int,TElem>[cap];
    for(int i=0;i<cap;i++) {
        get<1>(arr[i]) = NULL_TELEM;
        get<0>(arr[i]) = NULL_TELEM;
    }
    first_empty=0;
}


void Queue::push(TElem elem) {
    //TODO - Implementation

    if(size==cap)
    {
        tuple<int,TElem> *aux;
        cap*=2;
        aux = new tuple<int,TElem>[cap];
        for(int i=0;i<cap;i++)
            get<0>(aux[i])=i;
        for (int i = 0; i < size+1; i++)
            aux[i] = arr[i];
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

        get<0>(arr[first_empty])=-1;
        get<1>(arr[first_empty])=elem;
        get<0>(arr[first_empty-1])=first_empty;
        if(first_empty<head)
        {
            get<0>(arr[first_empty])=first_empty+1;
            head=first_empty;
        }
        while((first_empty != head && get<0>(arr[first_empty]) == -1) || (get<0>(arr[first_empty])==head && first_empty<head))
        {
            first_empty=first_empty+1;
        }

        size++;
    }




}

TElem Queue::top() const {
	//TODO - Implementation
    if(isEmpty())
        throw exception();
    return get<1>(arr[head]);
}

TElem Queue::pop() {
	//TODO - Implementation

    if(isEmpty())
        throw exception();

    TElem sters = top();

    if(size==1)
    {
        head=-1;
        first_empty=0;
        size--;
    } else {

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
	//TODO - Implementation
    if(size==0)
        return true;
	return false;
}


Queue::~Queue() {
	//TODO - Implementation
    delete[] arr;
}

