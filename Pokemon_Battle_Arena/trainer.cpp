#include "trainer.h"
/*********************************************************************  
 ** Program Filename: trainer.cpp
 ** Author: Sankalp Patil
 ** Date: 1/31/22
 ** Description: Is the implementation file for the trainer class
 ** Input: None
 ** Output:  None
 *********************************************************************/




/*********************************************************************  
 ** Function:  Trainer()
 ** Description: The default constructor. Initializes member variables
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  Member variables have been initialized
 *********************************************************************/
Trainer::Trainer(){
    name = "General Trainer";
    num_pokemon = 0;
    activePokemon = nullptr;
}




/*********************************************************************  
 ** Function:  ~Trainer()
 ** Description: Destructor. Deletes the contents of the team array since they
                 were dynamically allocated pokemon
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  Contents of the team array have been deleted
 *********************************************************************/


Trainer::~Trainer(){
    for (int i = 0; i < 3; i++){
        delete team[i];
    }
}




/*********************************************************************  
 ** Function:  getName()
 ** Description: Accesor for the member variable name.
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  Name has been returned
 *********************************************************************/
string Trainer::getName(){
    return name;
}




/*********************************************************************  
 ** Function:  fight()
 ** Description: Attacks the opponent's active pokemon with the trainer's active pokemon
                 Prints out a summary of the attack
 ** Parameters:  Trainer& opponent
 ** Pre-Conditions: None
 ** Post-Conditions:  The opponent's active pokemon has been damaged by the trainer's active pokemon
 *********************************************************************/
void Trainer::fight(Trainer& opponent){
    float damage = activePokemon->attackPokemon(opponent.getActivePokemon());
    cout << opponent.getName() << "'s " << opponent.getActivePokemon().getName() << " took " << damage << " damage. Now has " << opponent.getActivePokemon().getHealth() << " health." << endl;
}




/*********************************************************************  
 ** Function:  getActivePokemon()
 ** Description: Is an accesor function to get the current object's active pokemon. 
                 Meant to be used by other trainer objects
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  A reference to the trainer's active pokemon has been returned
 *********************************************************************/
Pokemon& Trainer::getActivePokemon(){
    return *activePokemon;
}




/*********************************************************************  
 ** Function:  printTeam()
 ** Description: Prints the trainer's team, their HP, and an indicator for the active pokemon
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  The trainer's team has been printed
 *********************************************************************/
void Trainer::printTeam(){

    for(int i = 0; i < num_pokemon; i++){

        if(!team[i]->isDead()){

            if(team[i] == activePokemon){
                cout << i + 1 << ". " << team[i]->getName() << " HP: " << team[i] -> getHealth() << " (Active Pokemon)" << endl;

            }else{
                cout << i + 1 << ". " << team[i]->getName() << " HP: " << team[i] -> getHealth() << endl;
            }
        }
    }

    cout << "\n" << endl;
}




/*********************************************************************  
 ** Function:  isBeaten()
 ** Description: Returns a boolean value to determine if the trainer object has been defeated
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  A boolean value has been returned
 *********************************************************************/
bool Trainer::isBeaten(){
    return(team[0]->isDead() && team[1]->isDead() && team[2]->isDead());

}




/*********************************************************************  
 ** Function:  updateStatus()
 ** Description: Checks to see if the active pokemon has died, if so, calls swap()
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  swap() has been called if the active pokemon is dead
 *********************************************************************/
void Trainer::updateStatus(){
    if(activePokemon -> isDead()){
        swap();
    }
}

