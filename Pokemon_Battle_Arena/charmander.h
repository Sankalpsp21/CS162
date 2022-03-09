#pragma once
/*********************************************************************  
 ** Program Filename: charmander.h
 ** Author: Sankalp Patil
 ** Date: 1/20/21
 ** Description: Houses the definition for the Charmander class. Inherits Pokemon
 ** Input: None
 ** Output: None
 *********************************************************************/
#include "pokemon.h"


class Charmander : public Pokemon {
    public:
        Charmander();
        float attackPokemon(Pokemon&) override;


};