#include <iostream>
using namespace std;
#include "Entrenador.h"



struct EntrenadorSt{
    string nombre;
    int cantPokemon;
    Pokemon* pokemon;

};

// Dado un nombre, una cantidad de pokémon, y un array de pokémon de ese tamaño, devuelve
// un entrenador.
Entrenador consEntrenador(string nombre, int cantidad, Pokemon* pokemon){
    Entrenador e = new EntrenadorSt;
    e->nombre = nombre;
    e->cantPokemon = cantidad;
    e->pokemon = new Pokemon[cantidad]; // Se crea un array de Pokemon(punteros) del tamaño de la cantidad dada
    
     // Copiar cada puntero a `Pokemon` del array de entrada en el nuevo array del entrenador
    for (int i = 0; i < cantidad; ++i) {
        e->pokemon[i] = pokemon[i];
    }
    
    return e;
}

// Devuelve el nombre del entrenador.
string nombreDeEntrenador(Entrenador e){
    return(e->nombre);
}

// Devuelve la cantidad de pokémon que posee el entrenador.
int cantidadDePokemon(Entrenador e){
    return(e->cantPokemon);
}

// Devuelve la cantidad de pokémon de determinado tipo que posee el entrenador.
int cantidadDePokemonDe(TipoDePokemon tipo, Entrenador e){
// CONSULTAR QUE PASA SI EL ARRAY DE POKEMON NO ESTA COMPLETO
    int cantidadDelTipo = 0;
    for (int i = 0; i < (e->cantPokemon); i++)
    {
        cantidadDelTipo = unoSi(tipoDePokemon(e->pokemon[i]) == tipo ) + cantidadDelTipo;
    }
    return cantidadDelTipo;
}

int unoSi(bool b){
    if (b)
    {
        return 1;
    }
    return 0;    
}

// Devuelve el pokémon número i de los pokémon del entrenador.
// Precondición: existen al menos i − 1 pokémon.
Pokemon pokemonNro(int i, Entrenador e){
    return(e->pokemon[i]);
    
}

// Dados dos entrenadores, indica si, para cada pokémon del segundo entrenador, el primero
// posee al menos un pokémon que le gane.
bool leGanaATodos(Entrenador e1, Entrenador e2){
   /* Observaciones:
      Tenemos que recorrer 2 estructuras.
      Iteramos sobre los pokemon del entrenador 2.
      Usamos for, porque vamos a recorrerlos todos.
   */ 
   // Recorrido de procesamiento sobre los pokemon del entrenador 2.
   for (int i = 0; i < (e2->cantPokemon); i++) {

        // Es un recorrido de busqueda, buscando un pokemon que supere al pokemon
        // del entrenador 2. (Si no lo supera pasa al proximo del entrenador 1)
       int j = 0;
       while (j < (e1->cantPokemon) && !(superaA(pokemonNro(j,e1), pokemonNro(i,e2)) )) {
            j++;
       }
       // Cuando corta el while, verificamos si llego al maximo de pokemon.
       // Si es asi, quiere decir que no lo encontro.
       if (j == (e1->cantPokemon) ) {
        return false;
       }
   }
   return true;
}



bool leGanaATodos2(Entrenador e1,Entrenador e2){
    bool rp = false;

    for (int i = 0; i < (e1->cantPokemon)  && !rp; i++){ // Recorre los pokemon del entrenador 1, y en cada iteracion recorre todos los pokemon del entrenador 2
        rp = true;
        
        for (int j = 0; j < (e2->cantPokemon); j++) { // Recorre los pokemon del entrenador 2
            rp = superaA(pokemonNro(i,e1),pokemonNro(j,e2)) && rp;
        }        
    }
    return rp;

}
