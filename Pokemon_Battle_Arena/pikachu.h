#pragma once

/*********************************************************************  
 ** Program Filename: Pikachu.h
 ** Author: Sankalp Patil
 ** Date: 1/20/21
 ** Description: Houses the definition for the Pikachu class. Inherits Pokemon
 ** Input: None
 ** Output: None
 *********************************************************************/
#include "pokemon.h"


class Pikachu : public Pokemon {
    public:
        Pikachu();
        float attackPokemon(Pokemon&) override;


};