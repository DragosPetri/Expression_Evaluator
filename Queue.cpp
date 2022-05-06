#include "Queue.h"
#include <exception>
#include <tuple>

using namespace std;

Queue::Queue() {

    cap=5;
    size=0;
    head=nullpt;
    arr = new tuple<int,TElem>[cap];
    for(int i=0;i<cap;i++)
    {
        arr[i] = make_tuple(i+1,NULL_TELEM);
    }
    first_empty=0;
}


void Queue::push(TElem e) {


    if ( head == -1 )

    {
        get<element>(arr[first_empty])=e;
        get<next_e>(arr[first_empty])=nullpt;
        head=first_empty;
        first_empty++;
        size++;
    }
    else
    {
        int nod = head;
        while (get<next_e>(arr[nod]) != nullpt)
        {
            nod = get<next_e>(arr[nod]);
        }

        get<next_e>(arr[nod]) = first_empty;
        get<element>(arr[first_empty]) = e;
        int pos = first_empty;
        first_empty = get<next_e>(arr[first_empty]);
        get<next_e>(arr[pos]) = nullpt;

        size++;
    }

    if(size==cap)
    {
        tuple<int,TElem> *aux;
        cap*=2;
        aux = new tuple<int,TElem>[cap];

        for(int i=0;i<cap;i++)
        {
            get<0>(aux[i])=i+1;
            get<1>(aux[i])=NULL_TELEM;
        }

        for (int i = 0; i < size; i++)
            aux[i]=arr[i];

        first_empty = size;

        delete[] arr;
        arr=aux;
    }

    /*
     * Best Case: Θ(1)
     * Worst case: Θ(n)
     * Average Case: O(n)
     */

}



TElem Queue::top() const {

    if(isEmpty())
        throw exception();
    return get<element>(arr[head]);

    /*
    * Θ(1)
    */
}

TElem Queue::pop() {

    if(isEmpty())
        throw exception();

    TElem sters = top();

    if(size==1)
    {
        get<next_e>(arr[head]) = 1;
        get<element>(arr[head]) = NULL_TELEM;
        head=nullpt;
        first_empty=0;
        size--;
    }
    else
    {

        int old_pos = head;
        head = get<next_e>(arr[head]);
        get<next_e>(arr[old_pos]) = first_empty;
        first_empty = old_pos;
        get<element>(arr[old_pos]) = NULL_TELEM;
        size--;
    }

    if (size <= cap/4 && cap>5) size_down();

    return sters;

    /*
    * Θ(1)
    */
}


bool Queue::isEmpty() const {

    if(size==0)
        return true;
    return false;

    /*
    * Θ(1)
    */
}

void Queue::size_down() {

    cap/=2;
    tuple<int,TElem> *aux = new tuple<int,TElem>[cap];

    for(int i=0;i<cap;i++)
    {
        aux[i] = make_tuple(NULL_TELEM,NULL_TELEM);
    }

    int ct = 0;
    int nod = head;
    while (get<next_e>(arr[nod]) != nullpt)
    {
        aux[ct] = arr[nod];
        ct++;
        nod = get<next_e>(arr[nod]);
    }

    aux[ct] = arr[nod];
    int next = 1;
    ct = 0;

    while (get<element>(aux[ct])!=NULL_TELEM) {
        get<next_e>(aux[ct]) = next;
        next++;
        ct++;
    }
    get<next_e>(aux[ct-1]) = nullpt;
    first_empty = ct;
    head = 0;

    delete[] arr;
    arr=aux;
}


Queue::~Queue() {
    delete[] arr;

    /*
    * Θ(1)
    */
}
