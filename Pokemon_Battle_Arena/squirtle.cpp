/*********************************************************************  
 ** Program Filename: squirtle.cpp
 ** Author: Sankalp Patil
 ** Date: 1/20/21
 ** Description: Houses the implemenation for the Squirtle class
 ** Input: None
 ** Output:  
 *********************************************************************/

#include "squirtle.h"



/*********************************************************************  
 ** Function:  Squirtle()
 ** Description: Initializes all member variables 
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  A Squirtle object is created
 *********************************************************************/
Squirtle::Squirtle(){
    name = "Squirtle";
    type = "Water";
    maxHealth = 44;
    health = 44;
    attack = 48;
    defense = 65;
    speed = 43;
}



/*********************************************************************  
 ** Function:  attackPokemon()
 ** Description: Damages the opposing pokemon and returns the calculated damage dealt to the passed in pokemon
 ** Parameters:  Pokemon& opponent
 ** Pre-Conditions: A Squirtle object must've been created
 ** Post-Conditions:  Opponent has been damaged and damage is returned
 *********************************************************************/
float Squirtle::attackPokemon(Pokemon& opponent){
    float damage;

    if(opponent.getType() == "Fire"){
        cout << "Very effective!" << endl;
        damage = 15 * (attack/opponent.getDefense()) * 2.0 * genRandomFloat();

    }else if (opponent.getType() == "Electric"){
        damage = 15 * (attack/opponent.getDefense()) * genRandomFloat();

    }else{
        cout << "Not very effective..." << endl;
        damage = 15 * (attack/opponent.getDefense()) * 0.5 * genRandomFloat();
    }
    opponent.damage(damage);
    return damage;
}
    