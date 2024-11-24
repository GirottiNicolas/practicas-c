#include <iostream>
#include "Set.h"
using namespace std;



void MostrarLista(Set s){
    LinkedList ls = setToList(s);
    ListIterator ixs = getIterator(ls);
    cout << "[ " ;
    
    while (!atEnd(ixs)) {
        cout << " " << current(ixs) << " " ;
        Next(ixs);
    }
    cout << "] "<< endl ;
    DisposeIterator(ixs);
}

int main(){
    Set s = emptyS();
    cout << "Esta vacio? ->" << isEmptyS(s) << endl;
    AddS(1,s);
    AddS(2,s);
    AddS(3,s);
    AddS(4,s);
    AddS(5,s);

    cout << "Esta vacio? -> " << isEmptyS(s) << endl;
    cout << "Tamaño de set? -> " << sizeS(s) << endl;
    MostrarLista(s);
        
    DestroyS(s);
}