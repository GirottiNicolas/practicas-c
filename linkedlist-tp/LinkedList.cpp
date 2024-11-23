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

/*
    Costo: O(N) Ya que se realizan N veces operaciones constantes, siendo N la cantidad de elementos que tenga la linked list dada.

                Si bien se realizan multiples operaciones constantes: 
                            new NodoL -> Al crear el nodo,
                            nodo->elem = ..            -> asignarle valores a sus campos,
                            nodo->siguiente = NULL
                            -> Comprobar que la linked list dada no este vacia
                            new IteratorSt -> Crear un iterador
                            Asignarle valor..
                            Etcetera
                El foco del costo yace en el caso de que la lista no este vacia, ya que debe recorrer los elementos de dicha lista hasta
                que el siguiente del nodo actual sea NULL, por eso se deben realizar N veces las operaciones del while que es su condicion 
                como tambien avanzar hacia el siguiente nodo.
*/ 





//Apunta el recorrido al primer elemento.
ListIterator getIterator(LinkedList xs){
    IteratorSt* ixs = new IteratorSt;
    ixs->current = xs->primero;
    return ixs;
}
// Costo O(1): Ya que las operaciones realizadas son de costo constante, tanto como new Iterator, y asignarle el nodo.
    // Memoria: Se reserva en la memoria heap un espacio para el registro del iterador.



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
    IteratorSt* ixs = new IteratorSt; // Creo el iterador O(1)
    ixs->current = xs->primero; // Inicializo el iterador O(1)
    while (ixs->current != NULL) { // Mientras que el iterador no sea NULL O(1)
        ixs->current = xs->primero->siguiente; // Next O(1)
        delete xs->primero; 
        xs->cantidad--; // Es innecesario pero para hacer la costumbre de decrementar
    }
    delete ixs; // Elimino iterador
    delete xs;  // Elimino header
}

/*
    Costo: O(N) Ya que se realizan N operaciones de costo constante, siendo N la cantidad de elementos que existan en la LinkedList xs.
                Operaciones constantes: new IteratorSt, inicializar el iterador, la condicion del while, pasar al siguiente nodo del iterador,
                                        delete xs->primero, incrementar la cantidad, delete iterador y delete header.
*/


/*

void Append(LinkedList xs, LinkedList ys){
    if(ys->ultimo != NULL){ // Si la segunda lista no es vacia
        xs->ultimo->siguiente = ys->primero; // 1°
        xs->ultimo = ys->ultimo; // 2° Cambio el ultimo puntero
        xs->cantidad += ys->cantidad; // 3° Incremento cantidades
        delete ys;    // 4° Elimino header ys
    }
}

Costo: O(1) -> Ya que las operaciones que se realizan no refieren a la cantidad de elementos de la estructura, sino que se utiliza el manejo de punteros 
                para las operaciones, y dicho manejo es Constante O(1), como asi tambien lo es acceder a los campos de un registro.
                    Operaciones realizadas:
                    - Comprobar que el ultimo nodo de la lista ys no sea NULL (La condicion del if) ,
                    - Asignar el siguiente del nodo al primer nodo de la lista ys,
                    - Incrementar cantidades de ambas listas, por lo que se accedio a ambas listas.
                    - Eliminar header (delete ys)
                    Todas estas operaciones son O(1). Por lo tanto, la funcion es CONSTANTE.
*/