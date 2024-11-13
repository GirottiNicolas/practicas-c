#include <iostream>
using namespace std;
#include "Persona.h"
#include "Mascota.h"


struct PersonaSt {
    string nombre;
    int edad;
    Mascota mascota;
};

Persona nacer(string n){
    PersonaSt* p = new PersonaSt;
    (*p).nombre = n;
    p->edad = 0;
    p->mascota = mascotaNula();
    return p;
}


void cumplirEdad(Persona p){
    (p->edad++);
}

string nombre(Persona p){
    return(p->nombre);
}


int edad(Persona p){
    return(p->edad);
}


void showPersona(Persona p){
   
    cout << "Persona -> " << p << endl;
    cout << "( nombre -> "  << p->nombre;
    cout << "-> edad: "    << p->edad ; 
    cout << "-> mascota: ";
    showMascota (p->mascota);
    cout << " )" << endl;
    
}


void morir(Persona p){
    delete p;
}


bool tieneMascota(Persona p){
    return(!(mascota(p) == mascotaNula() ) );
    
}


Mascota mascota(Persona p){
   return(p->mascota);
}


void AdoptarMascota(Persona p, Mascota m){
    p->mascota = m;
}


void LiberarMascota(Persona p){
    p->mascota = mascotaNula();
}

void cambioDeNombre(string nombre, Persona p){
    p->nombre = nombre;
}


bool esMayorQueLaOtra(Persona p1, Persona p2){
    return (p1->edad) > (p2->edad);
}

Persona laQueEsMayor(Persona p1, Persona p2){
    if (esMayorQueLaOtra(p1 ,p2) ) {
        return(p1);
    }
    return p2;
}