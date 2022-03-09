/*********************************************************************  
 ** Program Filename: computer.cpp
 ** Author: Sankalp Patil
 ** Date: 1/31/22
 ** Description: Is the implementation file for the computer class
 ** Input: None
 ** Output:  None
 *********************************************************************/

#include "computer.h"

/*********************************************************************  
 ** Function:  Computer()
 ** Description: The default constructor with one argument that has a default value. Creates new seed for rand()
 ** Parameters:  string name
 ** Pre-Conditions: None
 ** Post-Conditions:  Computer object has been created with initialized name variable
 *********************************************************************/
Computer::Computer(string name){
    this->name = name;
    srand(time(0));
}




/*********************************************************************  
 ** Function:  heal()
 ** Description: Heals a randomly selected pokemon from the team array
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  Randomly selected pokemon has been healed
 *********************************************************************/
void Computer::heal(){
    int choice;

    do{
        choice = randomGen123();

    }while(team[choice - 1] -> isDead()); 
    //The purpose of this loop is to keep choosing a pokemon to switch to if the selected one is dead

    team[choice - 1] -> heal();
}




/*********************************************************************  
 ** Function:  swap()
 ** Description: Heals a randomly selected pokemon from the team array
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  Active pokemon has been randomly swapped
 *********************************************************************/
void Computer::swap(){

    //Preventing an infinite loop if all pokemon are dead
    if(!isBeaten()){
        int choice;

        do{
            choice = randomGen123();

        }while(team[choice - 1] -> isDead()); 
        //The purpose of this loop is to keep choosing a pokemon to switch to if the selected one is dead

        activePokemon = team[choice - 1];
    }
}




/*********************************************************************  
 ** Function:  addPokemon()
 ** Description: Randomly selects a pokemon and adds it to the the team array
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  Random pokemon has been added to the team array
 *********************************************************************/
void Computer::addPokemon(){
    int choice = randomGen1234();

    if(choice == 1){
        team[num_pokemon] = new Bulbasaur();

    }else if(choice == 2){
        team[num_pokemon] = new Charmander();

    }else if(choice == 3){
        team[num_pokemon] = new Pikachu();

    }else if(choice == 4){
        team[num_pokemon] = new Squirtle();
    }
    
    activePokemon = team[0]; //Active pokemon automatically set to the first pokemon on the team
    num_pokemon++;
}




/*********************************************************************  
 ** Function:  randomGen123()
 ** Description: Randomly generates an integer from 1-3 and returns it
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  Random int 1-3 has been returned
 *********************************************************************/
int Computer::randomGen123(){
    return(rand() % 3 + 1);
}




/*********************************************************************  
 ** Function:  randomGen1234()
 ** Description: Randomly generates an integer from 1-4 and returns it
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  Random int 1-4 has been returned
 *********************************************************************/
int Computer::randomGen1234(){
    return(rand() % 4 + 1);
}


