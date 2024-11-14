#include <iostream>
using namespace std;
#include "ArrayList.h"


//Devuelve la suma de todos los elementos.
int sumatoria(ArrayList xs){
    int total = 0;

    for (int i = 0; i < (lengthAL(xs)); i++) {
        total+= get(i,xs);
    }
    return(total);
}

//Incrementa en uno todos los elementos.
void sucesores(ArrayList xs){
    for (int i = 0; i < lengthAL(xs); i++) {
       set(i, get(i,xs) + 1, xs) ;
    }
}


//Indica si el elemento pertenece a la lista.
bool pertenece(int x, ArrayList xs){
    int i = 0;
    /* Mientras que i es menor que la longitud del arreglo, 
    y x es diferente al elemento i del array*/
    while (i < lengthAL(xs) && (x != get(i,xs) ) ) { 
        i++;
    }
    return(x == get(i,xs));
}

int unoSi(bool b){
  if (b){
    return 1;
  }
  return 0;  
}

//Indica la cantidad de elementos iguales a x.
int apariciones(int x, ArrayList xs){
    int cant = 0;
    for (int i = 0; i < lengthAL(xs); i++){
        cant += unoSi(x == get(i,xs));
    }
    return cant;
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


// Devuelve el elemento más chico de la lista.
int minimo(ArrayList xs){
    int minimo = get(0, xs);
    for (int i = 1; i < lengthAL(xs); i++){
        minimo = min(minimo, get(i,xs));
    }
    return(minimo);
}

int main(){
    ArrayList myList = newArrayList();
    ArrayList myList2 = newArrayList();
    add(1, myList);
    add(2,myList);
    add(3, myList2);
    add(4,myList2);
    cout << "Mi lista " << get(0,myList) << endl;
    cout << "Mi lista " << get(1,myList) << endl;
    cout << "Mi lista2 " << get(0,myList2) << endl;
    cout << "Mi lista2 " << get(1,myList2) << endl;
    ArrayList miNuevaLista = append(myList,myList2);
    cout << "Mi nueva lista "<< endl;
    remove(miNuevaLista);

    for (int i = 0; i < lengthAL(miNuevaLista); i++) {
        cout << " " <<  i << " -> " << get(i,miNuevaLista) << endl;
    }
}