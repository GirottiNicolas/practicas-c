#include <iostream>
using namespace std;
#include "ArrayList.h"

/* Invariantes de representacion:
    - capacidad debe tener la longitud del array de elementos.
    - la cantidad se corresponde al numero de elementos que hay en el array elementos.
*/
struct ArrayListSt {
    int cantidad; // cantidad de elementos
    int* elementos; // array de elementos
    int capacidad; // tamaño del array
};


// Crea una lista con 0 elementos.
// Nota: empezar el array list con capacidad 16.
ArrayList newArrayList(){
    ArrayList lst = new ArrayListSt;
    lst->cantidad  = 0;
    lst->elementos = new int[16]; // Crea un array con 16 espacios
    lst->capacidad = 16;
    return(lst);
}

// Crea una lista con 0 elementos y una capacidad dada por parámetro.
ArrayList newArrayListWith(int capacidad){
    ArrayList lst = new ArrayListSt;
    lst->cantidad  = 0;
    lst->elementos = new int[capacidad];
    lst->capacidad = capacidad;
    return(lst);
}

// Devuelve la cantidad de elementos existentes.
int lengthAL(ArrayList xs){
    return(xs->cantidad);
}

// Devuelve el iésimo elemento de la lista.
int get(int i, ArrayList xs){
    if (i< xs->cantidad) {
        return(xs->elementos[i]);
    }
    return -3;
    
}

// Reemplaza el iésimo elemento por otro dado.
void set(int i, int x, ArrayList xs){
    if (xs->cantidad <= i) {
        xs->elementos[i] = x;
    }
    else {
        -1;
    }
}

// Decrementa o aumenta la capacidad del array.
// Nota: en caso de decrementarla, se pierden los elementos del final de la lista.
void resize(int capacidad, ArrayList xs){
    
    int* newAL = new int[capacidad]; // Creo un array con la capacidad deseada
    
    for (int i = 0; i < capacidad && i < (xs->cantidad); i++) { // Recorro los elementos del array anterior, 
            newAL[i] = xs->elementos[i]; // y copio los elementos al nuevo array.
        }
    delete xs->elementos;   // Elimino el array anterior
    xs->capacidad = capacidad; // Modifico la capacidad del array
    xs->elementos = newAL;  // Asigno el nuevo array
}



// Agrega un elemento al final de la lista.
void add(int x, ArrayList xs){
    if (xs->cantidad == xs->capacidad){ // Si esta al maximo de la capacidad el array
        int* temp = new int[xs->capacidad *2]; // Creo un array con el doble de capacidad

    // Copio los elementos del primer array en el temporal    
        for (int i = 0; i < xs->cantidad; i++) {
            temp[i] = xs->elementos[i];
        }
        // Elimino el array anterior
        delete xs->elementos;
        // Reemplazo el anterior por el nuevo
        xs->elementos = temp;
    }
    // Agrego en el indice del array el elemento x
    xs->elementos[xs->cantidad] = x;
    xs->cantidad++;
}




// Borra el último elemento de la lista.
void remove(ArrayList xs){
    xs->cantidad--; // Porque para añadir elementos tomo como indice la cantidad, que es donde se agregara, si decremento cantidad, se sobreeescribira ese espacio.
}
