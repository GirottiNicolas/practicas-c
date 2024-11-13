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
bool tieneMascota(Persona p);
Mascota mascota(Persona p);
void AdoptarMascota(Persona p, Mascota m);
void LiberarMascota(Persona p);
void cambioDeNombre(string nombre, Persona p);
bool esMayorQueLaOtra(Persona p1, Persona p2);
Persona laQueEsMayor(Persona p1, Persona p2);


