#pragma once

/*********************************************************************  
 ** Program Filename: computer.h
 ** Author: Sankalp Patil
 ** Date: 1/31/22
 ** Description: Is the definition file for the computer class. It inherits Trainer
 ** Input: None
 ** Output:  None
 *********************************************************************/

#include "trainer.h"
#include <cstdlib> //gives rand()
#include <ctime> //gives time() which is seconds since 1970 something. Needed to generate new seeds in srand()

class Computer : public Trainer{
    public:
        Computer(string = "Team Rocket");

        void heal();
        void swap(); //Randomly picks a pokemon to swap to
        void addPokemon(); //Randomly selects a pokemon to add to the team
        int randomGen123(); //Randomly returns a number 1-3 
        int randomGen1234(); //Randomly returns a number 1-4



};