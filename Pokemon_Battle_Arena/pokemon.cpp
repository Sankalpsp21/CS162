/*********************************************************************  
 ** Program Filename: pokemon.cpp
 ** Author: Sankalp Patil
 ** Date: 1/20/21
 ** Description: Houses the implemenation for the pokemon class
 ** Input: None
 ** Output:  
 *********************************************************************/

#include <iostream>
#include "pokemon.h"

using namespace std;
#include <string>


/*********************************************************************  
 ** Function:  Pokemon
 ** Description: The default constructor. Initializes all member variables
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  A pokemon object is constructed with initialized member variables
 *********************************************************************/ 
Pokemon::Pokemon(){
    attack = 10;
    health = 10;
    defense = 10;
    type = "";
    name = "";
    dead = false;
    srand(time(0));
}




/*********************************************************************  
 ** Function:  ~Pokemon
 ** Description: A Virtual Destructor that tells the compiler to also destroy child classes when destroying pokemon
 ** Parameters:  None
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object has been destroyed
 *********************************************************************/ 
Pokemon::~Pokemon(){
    
}





/*********************************************************************  
 ** Function:  getAttack
 ** Description: An accesor function that returns the attack member variable
 ** Parameters:  None
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's attack value is returned
 *********************************************************************/ 
float Pokemon::getAttack(){
    return attack;
}




/*********************************************************************  
 ** Function:  getHealth
 ** Description: An accesor function that returns the health member variable
 ** Parameters:  None
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's health variable is returned
 *********************************************************************/ 
float Pokemon::getHealth(){
    return health;
}




/*********************************************************************  
 ** Function:  getDefense
 ** Description: An accesor function that returns the defense member variable
 ** Parameters:  None
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's defense variable is returned
 *********************************************************************/ 
float Pokemon::getDefense(){
    return defense;
}




/*********************************************************************  
 ** Function:  getSpeed
 ** Description: An accesor function that returns the Speed member variable
 ** Parameters:  None
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's Speed variable is returned
 *********************************************************************/ 
float Pokemon::getSpeed(){
    return speed;
}




/*********************************************************************  
 ** Function:  getType
 ** Description: An accesor function that returns the type member variable
 ** Parameters:  None
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's type variable is returned
 *********************************************************************/ 
string Pokemon::getType(){
    return type;
}




/*********************************************************************  
 ** Function:  getName
 ** Description: An accesor function that returns the name member variable
 ** Parameters:  None
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's name variable is returned
 *********************************************************************/ 
string Pokemon::getName(){
    return name;
}




/*********************************************************************  
 ** Function:  isDead
 ** Description: An accesor function that returns the dead member variable
 ** Parameters:  None
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's dead variable is returned
 *********************************************************************/ 
bool Pokemon::isDead(){
    return dead;
}




/*********************************************************************  
 ** Function:  heal
 ** Description: Increment's the pokemon object's health variable by 15. 
                 If the resulting health is higher than the Max Health, health is set to Max Health
 ** Parameters:  None
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's healt variable is incremented
 *********************************************************************/ 
void Pokemon::heal(){
    health += 15;

    if(health > maxHealth){
        health = maxHealth;
    }
}




/*********************************************************************  
 ** Function:  damage
 ** Description: Decrements the pokemon's health variable by the amount passed in.
                 If the resulting health < 0, sets the dead variable to true
 ** Parameters:  float damage
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's health variable is decremented
 *********************************************************************/ 
void Pokemon::damage(float dam){
    health -= dam;

    if(health <= 0){
        dead = true;
    }
}




/*********************************************************************  
 ** Function:  genRandomFloat
 ** Description: Returns a random float between 0.85-1.15
 ** Parameters:  None
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  A random float between 0.85-1.15 is returned
 *********************************************************************/ 
float Pokemon::genRandomFloat(){
    float ran = (((float)rand()) / ((float)RAND_MAX) * (1.15 - 0.85)) + 0.85;
    return ran;
}


