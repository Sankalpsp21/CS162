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
#include <sstream>

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
    dex = 0;
    name = "";

    for (int i = 0; i < 4; i++){
        abilities[i] = "";
    }

}



/*********************************************************************  
 ** Function:  setDex
 ** Description: A mutator function that changes the dex member variable
 ** Parameters:  int dex
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's dex value is changed
 *********************************************************************/ 
void Pokemon::setDex(int dex){
    this->dex = dex;
}



/*********************************************************************  
 ** Function:  getDex
 ** Description: An accesor function that returns the dex member variable
 ** Parameters:  None
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's dex value is returned
 *********************************************************************/ 
int Pokemon::getDex(){
    return dex;
}



/*********************************************************************  
 ** Function:  setName
 ** Description: A mutator function that changes the name member variable
 ** Parameters:  string name
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's name variable is changed
 *********************************************************************/ 
void Pokemon::setName(string name){
    this->name = name;
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
 ** Function:  setType
 ** Description: A mutator function that changes the type member variable
 ** Parameters:  string type
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's type variable is changed
 *********************************************************************/ 
void Pokemon::setType(string type){
    this->type = type;
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
 ** Function:  setabilities
 ** Description: A mutator function that changes the abilities member variables
 ** Parameters:  string move1, string move2, string move3, string move4
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's abilities variables are changed
 *********************************************************************/ 
void Pokemon::setAbilities(string move1, string move2, string move3, string move4){
    abilities[0] = move1;
    abilities[1] = move2;
    abilities[2] = move3;
    abilities[3] = move4;
}



/*********************************************************************  
 ** Function:  getabilities
 ** Description: An accesor function that returns the abilities member variables
 ** Parameters:  None
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's abilities variables are returned
 *********************************************************************/
string Pokemon::getAbilities(){
    string output = abilities[0] + " " + abilities[1] + " " + abilities[2] + " " + abilities[3];
    return output;
}




/*********************************************************************  
 ** Function:  printPokemon
 ** Description: An printing function that returns pokemon information 
 ** Parameters:  None
 ** Pre-Conditions: A pokemon object must have been created
 ** Post-Conditions:  The pokemon object's information is returned as a string
 *********************************************************************/
string Pokemon::printPokemon(){
    stringstream ss;
    ss << dex;
    string dex1;
    ss >> dex1;
    string output = "";
    output = output + "Dex: " + dex1 + "\n";
    output = output + "Name: " + name + "\n";
    output = output + "Type: " + type + "\n";
    output = output + "Abilities: " + this->getAbilities() + "\n";
    output = output + " \n";
    return output;
}