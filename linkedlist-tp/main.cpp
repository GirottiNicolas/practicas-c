#include <iostream>
using namespace std;
#include "LinkedList.h"



int main(){
    LinkedList miLista = nil();
    Cons(1, miLista);
    Cons(2, miLista);
    Cons(3, miLista);
    Cons(4, miLista);
    Tail(miLista);
    Snoc(10,miLista);


    cout << "Mi lista " << endl;
    cout << "head -> " << head(miLista)<< endl;
    cout << "Esta vacia? -> " << isEmpty(miLista)<< endl; 
    cout << "Cantidad -> " << length(miLista)<< endl;
}