#include "Par.h"
#include <iostream>
using namespace std;

// Propósito: construye un par
Par consPar(int x, int y){
    Par p;
    p.x = x; 
    p.y = y;
    return (p);
}


// Propósito: devuelve la primera componente
int fst(Par p){
    return(p.x);
}

// Propósito: devuelve la segunda componente
int snd(Par p){
    return(p.y);
}


// Propósito: devuelve la mayor componente
int maxDelPar(Par p){
    if ((p.x) >= (p.y)) {
        return(p.x);
    }
    return(p.y);
}
// Propósito: devuelve un par con las componentes intercambiadas
Par swap(Par p){
    return(consPar(snd (p),fst (p) ));
}
// Propósito: devuelve un par donde la primer componente
// es la división y la segunda el resto entre ambos números
Par divisionYResto(int n, int m){
    return(consPar (n / m, n % m ) ) ;
}

void imprimir(Par p){
    cout << "(" << "";
    cout << p.x << "," ;
    cout << p.y << ")" << endl;
    
}