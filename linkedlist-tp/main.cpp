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

bool pertenece(int x, LinkedList xs) {
    ListIterator ixs = getIterator(xs);
    while (!atEnd(ixs) && current(ixs) != x) { 
        Next(ixs);
    }
    bool existeX = !atEnd(ixs); // Si no se llegó al final, se encontró el elemento.
    DisposeIterator(ixs);
    return existeX;    
}

int unoSi(bool b){
    if (b) {
        return 1;
    }
    return 0;
    
}

//Indica la cantidad de elementos iguales a x.
int apariciones(int x, LinkedList xs){
    ListIterator ixs = getIterator(xs);
    int contador = 0;
    while (!atEnd(ixs)) {
        contador += unoSi(current(ixs) == x);
        Next(ixs);
    }
    DisposeIterator(ixs);
    return(contador);   
}

int elMasChico(int n, int m){ //PROPOSITO: Describe el menor valor entre los dados
    if (n < m){
        return n;
    }
    return m;
    
}

int minimo(LinkedList xs){ // PRECONDICION: Existe al menos un elemento en la lista dada
    ListIterator ixs = getIterator(xs);
    int minimo = current(ixs);
    Next(ixs);
    while (!atEnd(ixs)) {
        minimo = elMasChico(minimo, current(ixs));
        Next(ixs);
    }
    DisposeIterator(ixs);
    return(minimo);
}

LinkedList copy(LinkedList xs){
    ListIterator ixs = getIterator(xs);
    LinkedList nuevaL = nil();

    while (!atEnd(ixs)) {
        Snoc(nuevaL, current(ixs));
        Next(ixs);
    }
    DisposeIterator(ixs);
    return nuevaL;
}


int main(){
    LinkedList miLista = nil();
    Cons(1, miLista);
    Cons(2, miLista);
    Cons(3, miLista);
    Cons(4, miLista);
    Snoc(miLista,5);
    Snoc(miLista,6);

    LinkedList miLista2 = copy(miLista);

    ListIterator ite = getIterator(miLista);

    cout << "Mi lista " << endl;
    for (int i = 0; i < length(miLista); i++) {
        cout << "Elemento " << current(ite)<< endl;
        Next(ite);
    }
    

}