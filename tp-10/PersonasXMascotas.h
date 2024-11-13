#include <iostream>
using namespace std;
#include "Mascota.h"


struct PersonaSt;   // struct PersonaSt no es parte de la interfaz
                    // la interfaz comienza desde Persona (luego del typedef)
typedef PersonaSt* Persona; // Persona es un puntero
Persona nacer(string n);
void cumplirEdad(Persona p);
string nombre(Persona p);
int edad(Persona p);
void showPersona(Persona p);
void morir(Persona p);
int cantidadDeMascotas(Persona p);
Mascota mascotaNro(Persona p,int i);
void AdoptarNuevaMascota(Persona p, Mascota m);
void LiberarMascota(Persona p, string nombre);