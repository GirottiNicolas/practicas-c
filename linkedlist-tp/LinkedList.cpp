#include <iostream>
using namespace std;
#include "LinkedList.h"



struct NodoL {
    int elem; // valor del nodo
    NodoL* siguiente; // puntero al siguiente nodo
};


struct LinkedListSt {
    // INV.REP.: cantidad indica la cantidad de nodos que se pueden recorrer
    // desde primero por siguiente hasta alcanzar a NULL
    int cantidad; // cantidad de elementos
    NodoL* primero; // puntero al primer nodo
};

typedef LinkedListSt* LinkedList; // INV.REP.: el puntero NO es NULL


struct IteratorSt {
    NodoL* current;
};

//Crea una lista vacía.
LinkedList nil(){
    LinkedListSt* lls = new LinkedListSt;
    lls->cantidad = 0;
    lls->primero = NULL;
    return lls;
}

//Indica si la lista está vacía.
bool isEmpty(LinkedList xs){
    return(xs->cantidad == 0);
}

//Devuelve el primer elemento.
int head(LinkedList xs){
    return(xs->primero->elem);
}

//Agrega un elemento al principio de la lista.
void Cons(int x, LinkedList xs){
    NodoL* nodo = new NodoL;    // Creo un nuevo nodo
    nodo->elem = x;             // Asigno valores
    nodo->siguiente = xs->primero; // Apunto el puntero al primero de la LinkedList
    xs->primero = nodo;             // Apunto el primero de la lista al nuevo nodo
    xs->cantidad++;         
}

//Quita el primer elemento.
void Tail(LinkedList xs){
    NodoL* tmp = xs->primero;
    xs->primero = xs->primero->siguiente;
    xs->cantidad--;
    delete tmp;
}

//Devuelve la cantidad de elementos.
int length(LinkedList xs){
    return(xs->cantidad);
}

//Agrega un elemento al final de la lista.
void Snoc(LinkedList xs, int x){
    NodoL* nodo = new NodoL; // Creo el nodo que se va a agregar
    nodo->elem = x;          // Añado el valor
    nodo->siguiente = NULL; // y el siguiente

    if (xs->primero == NULL) { // Si la lista xs esta vacia
        xs->primero = nodo;
    } 
    else {
        ListIterator ixs = new IteratorSt;
        ixs->current = xs->primero; // Inicio el iterador

       while (ixs->current->siguiente != NULL) {
            ixs->current = ixs->current->siguiente;
        }
        ixs->current->siguiente = nodo; // Conecto el último nodo con el nuevo nodo
        delete ixs; // Libero la memoria del iterador
    }
    xs->cantidad++;   // aumento cantidad de nodos
}

//Apunta el recorrido al primer elemento.
ListIterator getIterator(LinkedList xs){
    IteratorSt* ixs = new IteratorSt;
    ixs->current = xs->primero;
    return ixs;
}

//Devuelve el elemento actual en el recorrido.
// PRECONDICION: El nodo actual no debe ser NULL.
int current(ListIterator ixs){
    return ixs->current->elem;
}

//Reemplaza el elemento actual por otro elemento.
void SetCurrent(int x, ListIterator ixs){
    ixs->current->elem = x;
}

//Pasa al siguiente elemento.
void Next(ListIterator ixs){
    NodoL* siguiente = ixs->current->siguiente;
    ixs->current = siguiente;
}

//Indica si el recorrido ha terminado.
bool atEnd(ListIterator ixs){
    return(ixs->current == NULL);
}

//Libera la memoria ocupada por el iterador.
void DisposeIterator(ListIterator ixs){
    delete ixs;
}

//Libera la memoria ocupada por la lista.
void DestroyL(LinkedList xs){
    IteratorSt* ixs = new IteratorSt;
    ixs->current = xs->primero;
    while (ixs->current != NULL) {
        ixs->current = xs->primero->siguiente;
        delete xs->primero;
        xs->cantidad--;
    }
    delete ixs;
    delete xs;    
}


