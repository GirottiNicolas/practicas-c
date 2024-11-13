#include <iostream>
using namespace std;


struct MascotaSt;
typedef MascotaSt* Mascota;
Mascota mascotaNula();
bool esMascotaNula(Mascota m);
Mascota nacerMascota(string n, string hab);
void MorirMascota(Mascota m); // Precondicion: La mascota no es nula
string nombreMascota(Mascota m);
string habilidad(Mascota m);
void showMascota(Mascota m);