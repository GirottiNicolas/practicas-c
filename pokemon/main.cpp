#include <iostream>
#include "Entrenador.h"
using namespace std;



int main(){
    // Crear un array dinámico de 4 Pokemon
    Pokemon* pokemonArray = new Pokemon[4];
    pokemonArray[0] = consPokemon(Agua);
    pokemonArray[1] = consPokemon(Agua);
    pokemonArray[2] = consPokemon(Fuego);
    pokemonArray[3] = consPokemon(Agua);
    Entrenador ash = consEntrenador("Ash", 4,pokemonArray);


    Pokemon* pokemonArray2 = new Pokemon[4];
    pokemonArray2[0] = consPokemon(Fuego);
    pokemonArray2[1] = consPokemon(Fuego);
    pokemonArray2[2] = consPokemon(Fuego);
    pokemonArray2[3] = consPokemon(Planta);
    Entrenador rocket = consEntrenador("Rocket", 4,pokemonArray2);

    cout << "Supera a todos? -> "<<leGanaATodos(ash,rocket)<< endl;
}

