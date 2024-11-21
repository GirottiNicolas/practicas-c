#include <iostream>
using namespace std;
#include "LinkedList.h"


int sumatoria(LinkedList xs){
    int total = 0;
    ListIterator ixs = getIterator(xs);
    while (!atEnd(ixs)) {
        total += current(ixs);
        Next(ixs);
    }
    DisposeIterator(ixs);
    return total;
}



int main(){
    LinkedList miLista = nil();
    Cons(1, miLista);
    Cons(2, miLista);
    Cons(3, miLista);
    Cons(4, miLista);
    Tail(miLista);
    Snoc(miLista,10);


    cout << "Mi lista " << endl;
    cout << "head -> " << head(miLista)<< endl;
    cout << "Esta vacia? -> " << isEmpty(miLista)<< endl; 
    cout << "Sumatoria -> " << sumatoria(miLista)<< endl;
}