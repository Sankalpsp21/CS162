/*********************************************************************  
 ** Program Filename: charmander.cpp
 ** Author: Sankalp Patil
 ** Date: 1/20/21
 ** Description: Houses the implementation for the Charmander class
 ** Input: None
 ** Output: None
 *********************************************************************/
#include "charmander.h"


/*********************************************************************  
 ** Function:  Charmander()
 ** Description: Initializes all member variables 
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  A Charmander object is created
 *********************************************************************/
Charmander::Charmander(){
    name = "Charmander";
    type = "Fire";
    maxHealth = 39;
    health = 39;
    attack = 52;
    defense = 43;
    speed = 65;
}




/*********************************************************************  
 ** Function:  attackPokemon()
 ** Description: Damages the opposing pokemon and returns the calculated damage dealt to the passed in pokemon
 ** Parameters:  Pokemon& opponent
 ** Pre-Conditions: A Bulbasaur object must've been created
 ** Post-Conditions:  Opponent has been damaged and damage is returned
 *********************************************************************/
float Charmander::attackPokemon(Pokemon& opponent){
    float damage;

    if(opponent.getType() == "Electric"){
        damage = 15 * (attack/opponent.getDefense()) * genRandomFloat();

    }else if (opponent.getType() == "Fire" || opponent.getType() == "Water"){
        cout << "Not very effective..." << endl;
        damage = 15 * (attack/opponent.getDefense()) * 0.5 * genRandomFloat();

    }else{
        cout << "Very effective!" << endl;
        damage = 15 * (attack/opponent.getDefense()) * 2.0 * genRandomFloat();
    }
    opponent.damage(damage);
    return damage;    
}