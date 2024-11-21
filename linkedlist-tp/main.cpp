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


//Incrementa en uno todos los elementos.
void Sucesores(LinkedList xs){
    ListIterator ixs = getIterator(xs);
    while (!atEnd(ixs)) {
        int valor = current(ixs) + 1;
        SetCurrent(valor,ixs);
        Next(ixs);
    }
    DisposeIterator(ixs);
}


int main(){
    LinkedList miLista = nil();
    Cons(1, miLista);
    Cons(2, miLista);
    Cons(3, miLista);
    Cons(4, miLista);
    Tail(miLista);
    Snoc(miLista,5);


    cout << "Mi lista " << endl;
    cout << "head -> " << head(miLista)<< endl;
    cout << "Esta vacia? -> " << isEmpty(miLista)<< endl; 
    Sucesores(miLista);
    cout << "Sumatoria -> " << sumatoria(miLista)<< endl;
}