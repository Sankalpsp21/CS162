#pragma once
/*********************************************************************  
 ** Program Filename: pokemon.h
 ** Author: Sankalp Patil
 ** Date: 1/20/21
 ** Description: Houses the definition for the pokemon class
 ** Input: None
 ** Output:  
 *********************************************************************/

#include <iostream>
using namespace std;
#include <string>
#include <cstdlib> //gives rand()
#include <ctime> //gives time() which is seconds since 1970 something. Needed to create new seeds for srand()

class Pokemon{
    protected:
        float maxHealth, health, attack, defense, speed;
        string name, type;
        bool dead;
    
    public:
        Pokemon();
        virtual ~Pokemon();
        
        float getAttack(); 
        float getHealth(); 
        float getDefense(); 
        float getSpeed(); 
        string getType(); 
        string getName(); 
        bool isDead(); 

        void heal(); 
        void damage(float); 
        float genRandomFloat(); 
        
        virtual float attackPokemon(Pokemon&) = 0; //Virtual since each pokemon has different type
};

        


        





