#pragma once
/*********************************************************************  
 ** Program Filename: pokemon.h
 ** Author: Sankalp Patil
 ** Date: 1/20/21
 ** Description: Houses the interface for the pokemon class
 ** Input: None
 ** Output:  
 *********************************************************************/

#include <iostream>
using namespace std;
#include <string>

class Pokemon{
    private:
        int dex;
        string name, type;
        string abilities[4];
    
    public:
        Pokemon();

        // setter
        void setDex(int dex);

        // getter
        int getDex();

        // setter
        void setName(string name);

        // getter
        string getName();

        void setType(string type);

        string getType();

        void setAbilities(string move1, string move2, string move3, string move4);

        string getAbilities();

        string printPokemon();

};

        


        





