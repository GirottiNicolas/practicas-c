#include <iostream>
using namespace std;
#include "Tree.h"
#include  "../arrayList-tp/ArrayList.h"



//Dado un árbol binario de enteros devuelve la suma entre sus elementos.
int sumarT(Tree t){

    if (isEmptyT(t)) {
        return 0;
    }   
    
    return rootT(t) + sumarT(left(t)) + sumarT(right(t));
}

int maximoEntre(int m, int n){
    if (m>n) {
        return m;
    }
    return n;    
}

//Dado un árbol binario devuelve su cantidad de elementos, es decir, el tamaño del árbol (size
//en inglés).
int sizeT(Tree t){
    if (isEmptyT(t))  {
        return 0;
    }
    return 1 + sizeT(left(t))+ sizeT(right(t));
}

// Dados un elemento y un árbol binario devuelve True si existe un elemento igual a ese en el
// árbol.
bool perteneceT(int e, Tree t){
    if (isEmptyT(t)){
        return false;
    }
    return rootT(t) == e || perteneceT(e,left(t)) ||  perteneceT(e,right(t));
    
}

int unoSi(bool b){
    if (b){
        return 1;
    }
    return 0;
    
}

//Dados un elemento e y un árbol binario devuelve la cantidad de elementos del árbol que son
//iguales a e.
int aparicionesT(int e, Tree t){
    if (isEmptyT(t)) { 
        return 0; 
    }
    return unoSi(rootT(t) == e) + aparicionesT(e,left(t)) + aparicionesT(e,right(t));
    
    
}

// Dado un árbol devuelve su altura
int heightT(Tree t){
    if (isEmptyT(t))  {
        return 0;
    }
    return 1 + maximoEntre(heightT(left(t)), heightT(right(t)));
}

//Crea una nueva lista a partir de la primera y la segunda (en ese orden)
ArrayList append(ArrayList xs, ArrayList ys){
    ArrayList listaN = newArrayListWith(lengthAL(xs) + lengthAL(ys));
    for (int i = 0; i < lengthAL(xs); i++){
        add(get(i,xs),listaN);
    }
    for (int i = 0; i < lengthAL(ys); i++){
        add(get(i,ys),listaN);
    }
    return(listaN);
}


//Dado un árbol devuelve una lista con todos sus elementos
ArrayList toList(Tree t){
    if (isEmptyT(t)){
        return newArrayList();
    }
    ArrayList xs = toList(right(t));
    ArrayList ys = toList(left(t));
    
    add(rootT(t), xs);
    
    return(append(xs,ys));

}




int main(){
    Tree nodoIzq = nodeT(30,emptyT(),emptyT());
    Tree nodoDer = nodeT(20,emptyT(),nodoIzq);

    Tree miArbol = nodeT(10,nodoIzq,nodoDer);
    

    ArrayList lista = toList(miArbol);

    for (int i = 0; i < lengthAL(lista); i++) {
        cout << " " <<  i << " -> " << get(i,lista) << endl;
    }
    return 0;
}