#include <iostream>
using namespace std;
#include "Pokemon.h"



struct PokemonSt {
    TipoDePokemon tipo;
    int vida;
};

//Dado un tipo devuelve un pokémon con 100 % de energía.
Pokemon consPokemon(TipoDePokemon tipo){
    Pokemon p = new PokemonSt;
    p->tipo = tipo;
    p->vida = 100;
    return p;
}


//Devuelve el tipo de un pokémon.
TipoDePokemon tipoDePokemon(Pokemon p){
    return(p->tipo);
}

// Devuelve el porcentaje de energía.
int energia(Pokemon p){
    return(p->vida);
}


// Le resta energía al pokémon.
void perderEnergia(int energia, Pokemon p){
    p->vida = (p->vida) - energia;
}


// Dados dos pokémon indica si el primero, en base al tipo, es superior al segundo. Agua supera
// a fuego, fuego a planta y planta a agua. Y cualquier otro caso es falso
bool superaA(Pokemon p1, Pokemon p2){



    if (((tipoDePokemon(p1) == Agua) && (tipoDePokemon(p2) == Fuego ))) {
        return true;
    }
    else if (((tipoDePokemon(p1) == Fuego) && (tipoDePokemon(p2) == Planta ))) {
        return true;
    }
    else if (((tipoDePokemon(p1) == Planta) && (tipoDePokemon(p2) == Agua ))) {
        return true;
    }
    else {
        return false;
    }
}


void ShowPokemon(Pokemon p){
    cout << "Pokemon de tipo -> " << tipoDePokemon(p);
    cout << "-> energia-> "  << energia(p) << endl;
}