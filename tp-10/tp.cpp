#include <iostream>
#include "Contador.h"
using namespace std;





int main(){
    Contador m = crearContador();
    cout << "Contador: " << m << " tiene " << *m << endl;
    (*m)++;
    cout << "Contador: " << m << " tiene " << leerContador(m) << endl;
    incrementar(m);
    cout << "Contador: " << m << " tiene " << leerContador(m) << endl;

}