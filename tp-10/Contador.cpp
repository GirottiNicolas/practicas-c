#include "Contador.h"



Contador crearContador(){
    int* punteroANum = new int;
    *punteroANum     = 0;
    return punteroANum;
}

int leerContador(Contador c){
    return(*c);
}

void incrementar(Contador c){
    (*c)++;
}