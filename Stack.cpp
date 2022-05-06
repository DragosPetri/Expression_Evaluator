#include "Stack.h"

Stack::Stack() {
    cap = 5;
    size = 0;
    head = nullpt;
    tail = nullpt;
    next_empty = 0;
    arr = new tuple<int,int,TElem2>[cap];
    for(int i=0;i<cap;i++)
    {
        arr[i] = make_tuple(i-1,i+1,NULL_STRING);
    }
}

Stack::~Stack() {

    delete[] arr;

    /*
    * Θ(1)
    */
};

void Stack::Push(TElem2 e) {

    if (head==nullpt) {

        head = next_empty;
        tail = head;
        next_empty++;
        arr[head] = make_tuple(nullpt,nullpt,e);
        size++;

    } else {

        if (size == cap) resize();

        int pos = next_empty;
        next_empty = get<next_e>(arr[next_empty]);
        arr[pos] = make_tuple(head,nullpt,e);
        get<next_e>(arr[head]) = pos;
        head = pos;

        size++;
    }

    /*
     * Best Case: Θ(1)
     * Worst case: Θ(n)
     * Average Case: O(n)
     */

};

TElem2 Stack::Pop() {

    if (isEmpty()) throw exception();

    TElem2 to_pop = Peek();

    if (head == tail) {

        arr[head] = make_tuple(nullpt,1,NULL_STRING);
        head = tail = nullpt;
        size--;
        next_empty = 0;
        return  to_pop;

    } else {

        int old_head = head;
        head = get<prev_e>(arr[head]);
        get<next_e>(arr[head]) = nullpt;
        arr[old_head] = make_tuple(NULL_TELEM,next_empty,NULL_STRING);
        size--;
        next_empty = old_head;
        if (size <= cap/4 && cap>5) size_down();
        return to_pop;
    }



    /*
    * Θ(1)
    */


};

TElem2 Stack::Peek() {
    if (!isEmpty()) return get<element>(arr[head]);
    else return NULL_STRING;

    /*
    * Θ(1)
    */

};

bool Stack::isEmpty() {
    if (head == nullpt) return true;
    return false;
    /*
    * Θ(1)
    */

}

void Stack::resize() {

    cap*=2;
    tuple<int,int,TElem2> *aux = new tuple<int,int,TElem2>[cap];

    for(int i=0;i<cap;i++)
    {
        aux[i] = make_tuple(i-1,i+1,NULL_STRING);
    }

    for (int i = 0; i < size; i++)
        aux[i]=arr[i];

    next_empty = size;

    delete[] arr;
    arr=aux;

};

void Stack::size_down() {

    cap/=2;
    tuple<int,int,TElem2> *aux = new tuple<int,int,TElem2>[cap];

    for(int i=0;i<cap;i++)
    {
        aux[i] = make_tuple(NULL_TELEM,NULL_TELEM,NULL_STRING);
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

    int prev = nullpt;
    int next = 1;
    ct = 0;
    while (get<element>(aux[ct])!=NULL_STRING) {
        get<prev_e>(aux[ct]) = prev;
        get<next_e>(aux[ct]) = next;
        prev++;
        next++;
        ct++;
    }
    get<next_e>(aux[ct-1]) = nullpt;
    next_empty = ct;
    head = 0;

    delete[] arr;
    arr=aux;
}