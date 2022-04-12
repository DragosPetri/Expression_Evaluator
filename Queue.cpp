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
    for(int i=0;i<cap;i++)
        get<0>(arr[i])=i;
    get<0>(arr[cap])=-1;
    first_empty=0;
}


void Queue::push(TElem elem) {
    //TODO - Implementation


    if(size==cap)
    {
        tuple<int,TElem> *aux;
        cap*=2;
        aux = new tuple<int,TElem>[cap];
        for (int i = 0; i < size; i++)
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
        int newelem=first_empty;
        get<0>(arr[newelem])=-1;
        get<1>(arr[newelem])=elem;
        get<0>(arr[newelem-1])=first_empty;
        first_empty=first_empty+1;
        size++;
    }

}

TElem Queue::top() const {
	//TODO - Implementation
    if(isEmpty())
        throw exception();
    return get<1>(arr[0]);
}
TElem Queue::pop() {
	//TODO - Implementation

    if(isEmpty())
        throw exception();

    TElem sters = top();


    int nodc=head;
    int prevnode=-1;

//    while(nodc!=-1 && get<1>(arr[nodc])!=get<1>(arr[0]))
//    {
//        prevnode=nodc;
//        nodc=get<0>(arr[nodc]);
//    }






    size--;


    if (size<=cap/4)
    {
        tuple<int, TElem> *aux;
        cap /= 2;
        aux = new tuple<int,TElem>[cap];
        for (int i = 0; i < size; i++)
            aux[i] = arr[i];

        delete[] arr;
        arr = aux;
    }

    return sters;

//	return NULL_TELEM;
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

