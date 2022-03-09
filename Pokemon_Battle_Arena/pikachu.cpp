/*********************************************************************  
 ** Program Filename: Pikachu.cpp
 ** Author: Sankalp Patil
 ** Date: 1/20/21
 ** Description: Houses the implemenation for the Pikachu class
 ** Input: None
 ** Output:  
 *********************************************************************/

#include "pikachu.h"



/*********************************************************************  
 ** Function:  Pikachu()
 ** Description: Initializes all member variables 
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  A Pikachu object is created
 *********************************************************************/
Pikachu::Pikachu(){
    name = "Pikachu";
    type = "Electric";
    maxHealth = 35;
    health = 35;
    attack = 55;
    defense = 40;
    speed = 90;
}



/*********************************************************************  
 ** Function:  attackPokemon()
 ** Description: Damages the opposing pokemon and returns the calculated damage dealt to the passed in pokemon
 ** Parameters:  Pokemon& opponent
 ** Pre-Conditions: A Pikachu object must've been created
 ** Post-Conditions:  Opponent has been damaged and damage is returned
 *********************************************************************/
float Pikachu::attackPokemon(Pokemon& opponent){
    float damage;

    if(opponent.getType() == "Water"){
        cout << "Very effective!" << endl;
        damage = 15 * (attack/opponent.getDefense()) * 2.0 * genRandomFloat();

    }else if (opponent.getType() == "Fire"){
        damage = 15 * (attack/opponent.getDefense()) * genRandomFloat();

    }else{
        cout << "Not very effective..." << endl;
        damage = 15 * (attack/opponent.getDefense()) * 0.5 * genRandomFloat();
    }
    opponent.damage(damage);
    return damage;
}
    