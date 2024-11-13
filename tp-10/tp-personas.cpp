#include <iostream>
#include "Persona.h"
using namespace std;





int main(){
    cout << "Quien es mayor entre";

    Persona ale = nacer("Alejandra");
    cumplirEdad(ale);
    Persona nicolas = nacer("Nicolas");
    showPersona(nicolas);
    cambioDeNombre("Alejandro",nicolas);
    showPersona(nicolas);
    showPersona(laQueEsMayor(nicolas,ale));
    return 0;
}