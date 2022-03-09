#pragma once

/*********************************************************************  
 ** Program Filename: pokedex.h
 ** Author: Sankalp Patil
 ** Date: 1/20/21
 ** Description: Houses the interface for the pokedex class
 ** Input: None
 ** Output:  
 *********************************************************************/

#include <iostream>
using namespace std;
#include <string>
#include <stdlib.h>
#include "pokemon.h"

class Pokedex{
    private:
        string trainer;
        int num_pokemon;
        Pokemon* pokemon_array;
    
    public:
        //Default values set. You can either enter the number of pokemon in the constructor or leave it blank
        Pokedex(int numPoke = 0, string trainer = "No Name ");

        //Destructor: frees the space that was allocated for the Pokemon array
        ~Pokedex();

        void setTrainer();

        string getTrainer();

        void setNumPoke(int numPoke);

        int getNum_pokemon();

        //This method prompts the user for values.
        void addPokemon(char* fileName);

        //This method is for creating the inital pokemon that were read in from the file.
        void addPokemon(int pos, int dex, string name, string type, string move1, string move2, string move3, string move4);

        //Returns a Pokemon at element num
        Pokemon getListPokemon(int num);

    private:
        //Dynamically grows the array by one element;
        void growPokedex();

        void updateFile(char* fileName, int dex, string name, string type, string move1, string move2, string move3, string move4);



};