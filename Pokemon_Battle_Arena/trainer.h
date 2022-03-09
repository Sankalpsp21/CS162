#pragma once
/*********************************************************************  
 ** Program Filename: trainer.h
 ** Author: Sankalp Patil
 ** Date: 1/31/22
 ** Description: Is the definition file for the trainer class
 ** Input: None
 ** Output:  None
 *********************************************************************/

#include "bulbasaur.h"
#include "charmander.h"
#include "pikachu.h"
#include "squirtle.h"
#include <iostream>
#include <string>

class Trainer{
    protected:
        Pokemon* team[3];
        Pokemon* activePokemon;
        string name;
        int num_pokemon;

    
    public:
        Trainer();
        ~Trainer();
        string getName();

        void fight(Trainer&); 

        virtual void heal() = 0; 
        virtual void swap() = 0; 
        virtual void addPokemon() = 0; //Meant to be overriden since human will need menu printed out whereas computer will just pick

        Pokemon& getActivePokemon(); 
        void printTeam(); 
        bool isBeaten(); 
        void updateStatus(); 
        


};