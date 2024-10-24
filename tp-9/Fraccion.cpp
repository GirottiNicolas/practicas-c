#include "Fraccion.h"

// Propósito: construye una fraccion
// Precondición: el denominador no es cero
Fraccion consFraccion(int numerador, int denominador){
    Fraccion f;
    f.numerador   = numerador;
    f.denominador = denominador;
    return(f);
}

// Propósito: devuelve el numerador
int numerador(Fraccion f){
    return(f.numerador);
}


// Propósito: devuelve el denominador
int denominador(Fraccion f){
     return(f.denominador);
}


// Propósito: devuelve el resultado de hacer la división
float division(Fraccion f){
    return(f.numerador / f.denominador);
}


