#pragma once

/*********************************************************************  
 ** Program Filename: squirtle.h
 ** Author: Sankalp Patil
 ** Date: 1/20/21
 ** Description: Houses the definition for the Squirtle class. Inherits Pokemon
 ** Input: None
 ** Output: None
 *********************************************************************/
#include "pokemon.h"


class Squirtle : public Pokemon {
    public:
        Squirtle();
        float attackPokemon(Pokemon&) override;


};