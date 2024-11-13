#include <iostream>
using namespace std;
#include "PersonasXMascotas.h"
#include "Mascota.h"


struct PersonaSt{
    string nombre;
    int edad;
    int maxMascotas;// INDICA EL TAMAÑO DEL ARRAY
    int cantMascotas;   // INDICA CUANTOS ELEMENTOS HAY EN EL ARRAY
    Mascota* mascotas; // ES UN PUNTERO. NO SE CUANTAS MASCOTAS HAY, POR ESO LO GUARDO SEPARADO
};     // struct PersonaSt no es parte de la interfaz
       // la interfaz comienza desde Persona (luego del typedef)
// ES IMPORTANTE: TENER ESTAS TRES VARIABLES, ES DECIR.
// max, cant y el puntero. Sino no puedo determinar el array de forma valida.



Persona nacer(string n){
    PersonaSt* p = new PersonaSt; // reservo un espacio y devuelvo un puntero
    p->nombre = n;
    p->edad   = 0;
    p->maxMascotas = 2;
    p->cantMascotas = 0;
    p->mascotas = new Mascota[p->maxMascotas]; // CREO UN ARRAY DE MASCOTAS, CON LA CANTIDAD QUE ME DIJERON
                    // ESTO ES UN PUNTERO A MASCOTAS, POR ESO LO GUARDO EN MI PUNTERO
    return(p);
}


void cumplirEdad(Persona p){

}


string nombre(Persona p){

}


int edad(Persona p){

}


void showPersona(Persona p){

}


void morir(Persona p){

}


int cantidadDeMascotas(Persona p){

}


Mascota mascotaNro(Persona p,int i){

}


void AdoptarNuevaMascota(Persona p, Mascota m){

}


void LiberarMascota(Persona p, string nombre){

}