#include <iostream>
using namespace std;
#include "Set.h"



struct NodoS {
    int elem;
    NodoS* siguiente;
};

struct SetSt{
    int cantidad;
    NodoS* primero;
};

typedef SetSt* Set;

//Crea un conjunto vacío.
Set emptyS(){
    SetSt* st = new SetSt;
    st->cantidad = 0;
    st->primero = NULL;
    return st;
}

//Indica si el conjunto está vacío.
bool isEmptyS(Set s){
    return(s->cantidad == 0);
}

//Indica si el elemento pertenece al conjunto.
bool belongsS(int x, Set s){
    if (s->cantidad == 0) { // Verifico si el set esta vacio
        return false;
    }
    NodoS* current = s->primero; // Creo un nodo que me permite recorrer el set
    while ((current->siguiente != NULL) && current->elem != x) { // Si el nodo siguiente del actual es NULL, no avanzo mas y verifico el valor actual.
        current = current->siguiente; // Avanzo
    }    
    return current->elem == x; 
}

//Agrega un elemento al conjunto.
void AddS(int x, Set s){
    NodoS* nodo = new NodoS; // Creo el nodo que se va a agregar
    nodo->elem = x;          // Asigno valor
    nodo->siguiente = s->primero; // Asigno siguiente
    s->primero = nodo;          // Asigno como primero del set al nuevo nodo
    s->cantidad++;
}

//Quita un elemento dado.
void RemoveS(int x, Set s){
    NodoS* current = s->primero;
    while (current != NULL && (current->elem != x ) ) {
        current = current->siguiente;
    }
    if (current != NULL && (current->elem == x) ){
        delete current;
        s->cantidad--;
    }    
}

//Devuelve la cantidad de elementos.
int sizeS(Set s){
    return(s->cantidad);
}

//Devuelve una lista con los elementos del conjunto.
LinkedList setToList(Set s){
    LinkedList ls = nil();
    NodoS* current = s->primero;
    while (current != NULL){
        Cons(current->elem,ls);
        current = current->siguiente;
    }
    return(ls);    
}



//Libera la memoria ocupada por el conjunto.
void DestroyS(Set s) {
    NodoS* current = s->primero;
    while (current != NULL) {
        NodoS* next = current->siguiente; // Guarda el siguiente nodo antes de eliminar el actual
        delete current;                   // Libera la memoria del nodo actual
        current = next;                   // Avanza al siguiente nodo
    }
    s->primero = NULL; // Opcional: asegura que el puntero del conjunto quede limpio
    delete s;
}

