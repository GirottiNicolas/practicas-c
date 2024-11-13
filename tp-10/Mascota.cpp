#include <iostream>
#include "Mascota.h"
using namespace std;

struct MascotaSt {
    string nombre;
    string habilidad;
};


Mascota mascotaNula(){
    return(NULL);
}


bool esMascotaNula(Mascota m){
    return(m == NULL);
}


Mascota nacerMascota(string n, string hab){

    Mascota m = new MascotaSt;
    m->nombre = n;
    m->habilidad = hab;

    return(m);
}

 // Precondicion: La mascota no es nula
void MorirMascota(Mascota m){
    if (!esMascotaNula(m)){
        delete m;
    }
}

string nombreMascota(Mascota m){
    return(m->nombre);
}

string habilidad(Mascota m){
    return(m->habilidad);
}


void showMascota(Mascota m){
    if (m != NULL) {
        cout << "Mascota -> "   << m << endl;
        cout << "nombre -> "    << m->nombre;
        cout << "-> habilidad " << m->habilidad << endl; 
    }
    else
    {
        cout << "Sin mascota";
    }
    
    
    
    
}