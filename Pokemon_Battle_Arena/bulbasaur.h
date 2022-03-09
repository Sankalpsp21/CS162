#pragma once

/*********************************************************************  
 ** Program Filename: bulbasaur.h
 ** Author: Sankalp Patil
 ** Date: 1/20/21
 ** Description: Houses the definition for the Bulbasaur class. Inherits Pokemon
 ** Input: None
 ** Output: None
 *********************************************************************/
#include "pokemon.h"


class Bulbasaur : public Pokemon {
    public:
        Bulbasaur();
        float attackPokemon(Pokemon&) override;


};