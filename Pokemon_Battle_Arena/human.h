#pragma once

/*********************************************************************  
 ** Program Filename: human.h
 ** Author: Sankalp Patil
 ** Date: 1/31/22
 ** Description: Is the definition file for the human class. It inherits Trainer
 ** Input: None
 ** Output:  None
 *********************************************************************/
#include "trainer.h"

class Human : public Trainer{
    public:
        Human(string = "Human");

        void setName(string);
        void heal();
        void swap(); //Prints out all pokemon that are still alive. User enters choice and activePokemon is chosen.
        void addPokemon(); //Prints out pokemon to choose from. Adds a pokemon to the team
        void presentFighters(); // Lists out the avaiable pokemon to choose from


};