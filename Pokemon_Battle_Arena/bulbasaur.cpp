/*********************************************************************  
 ** Program Filename: bulbasaur.cpp
 ** Author: Sankalp Patil
 ** Date: 1/20/21
 ** Description: Houses the implemenation for the bulbasaur class
 ** Input: None
 ** Output:  
 *********************************************************************/

#include "bulbasaur.h"



/*********************************************************************  
 ** Function:  Bulbasaur()
 ** Description: Initializes all member variables 
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  A Bulbasaur object is created
 *********************************************************************/
Bulbasaur::Bulbasaur(){
    name = "Bulbasaur";
    type = "Grass";
    maxHealth = 45;
    health = 45;
    attack = 49;
    defense = 49;
    speed = 45;
}




/*********************************************************************  
 ** Function:  attackPokemon()
 ** Description: Damages the opposing pokemon and returns the calculated damage dealt to the passed in pokemon
 ** Parameters:  Pokemon& opponent
 ** Pre-Conditions: A Bulbasaur object must've been created
 ** Post-Conditions:  Opponent has been damaged and damage is returned
 *********************************************************************/
float Bulbasaur::attackPokemon(Pokemon& opponent){
    float damage;
    if(opponent.getType() == "Fire" || opponent.getType() == "Grass"){
        cout << "Not very effective..." << endl;
        damage = 15 * (attack/opponent.getDefense()) * 0.5 * genRandomFloat();

    }else if (opponent.getType() == "Water"){
        cout << "Very effective!" << endl;
        damage = 15 * (attack/opponent.getDefense()) * 2.0 * genRandomFloat();

    }else{
        damage = 15 * (attack/opponent.getDefense()) * genRandomFloat();
    }
    opponent.damage(damage);
    return(damage);    
}