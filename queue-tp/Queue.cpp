#include <iostream>
using namespace std;
#include "Queue.h"


struct NodoQ {
    int elem; // valor del nodo
    NodoQ* siguiente; // puntero al siguiente nodo
};

struct QueueSt {
    int cantidad; // cantidad de elementos
    NodoQ* primero; // puntero al primer nodo
    NodoQ* ultimo; // puntero al ultimo nodo
};

typedef QueueSt* Queue;


// Crea una cola vacía.
// Costo: O(1).
Queue emptyQ(){
    QueueSt* q = new QueueSt;
    q->cantidad = 0;
    q->primero = NULL;
    q->ultimo = NULL;
    return q;
}


// Indica si la cola está vacía.
// Costo: O(1).
bool isEmptyQ(Queue q){
    return q->cantidad == 0;
}


// Devuelve el primer elemento.
// Costo: O(1).
int firstQ(Queue q){
    return q->primero->elem;
}

// Agrega un elemento al final de la cola.
// Costo: O(1).
void Enqueue(int x, Queue q){
    NodoQ* nodo = new NodoQ;
    nodo->elem = x;
    nodo->siguiente = NULL;
    q->ultimo->siguiente = nodo;
    q->cantidad++;
}


// Quita el primer elemento de la cola.
// Costo: O(1).
void Dequeue(Queue q){
    if (q->cantidad > 0){
        NodoQ* current = q->primero;
        q->primero = current->siguiente;
        delete current;
        q->cantidad--;
    }
}


// Devuelve la cantidad de elementos de la cola.
// Costo: O(1).
int lengthQ(Queue q){
    return(q->cantidad);
}


// Anexa q2 al final de q1, liberando la memoria inservible de q2 en el proceso.
// Nota: Si bien se libera memoria de q2, no necesariamente la de sus nodos.
// Costo: O(1).
void MergeQ(Queue q1, Queue q2){
    if (q1->ultimo != NULL) {
        q1->ultimo->siguiente = q2->primero;
        q1->ultimo = q2->ultimo;
        q1->cantidad += q2->cantidad;
        delete q2;
    }
    else {
        q1->primero = q2->primero;
        q1->ultimo = q2->ultimo;
        q1->cantidad = q2->cantidad;
        delete q2;
    }    
}


// Libera la memoria ocupada por la cola.
// Costo: O(n).
void DestroyQ(Queue q){
    NodoQ* current = q->primero;
    while (current != NULL) {
        NodoQ* next = current->siguiente;
        delete current;
        current = next;
    }
    delete q;
}
