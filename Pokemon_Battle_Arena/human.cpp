/*********************************************************************  
 ** Program Filename: human.cpp
 ** Author: Sankalp Patil
 ** Date: 1/31/22
 ** Description: Is the implementation file for the human class
 ** Input: None
 ** Output:  None
 *********************************************************************/

#include "human.h"




/*********************************************************************  
 ** Function:  Human()
 ** Description: The default constructor with one argument that has a default value
 ** Parameters:  string name
 ** Pre-Conditions: None
 ** Post-Conditions:  Human object has been created with initialized name variable
 *********************************************************************/
Human::Human(string name){
    this->name = name;
}



/*********************************************************************  
 ** Function:  setName()
 ** Description: The mutator method for the name member variable
 ** Parameters:  string name
 ** Pre-Conditions: human object must've been created
 ** Post-Conditions:  name member variable has been given a new value
 *********************************************************************/
void Human::setName(string name){
    this->name = name;
}




/*********************************************************************  
 ** Function:  heal()
 ** Description: Heals the specified pokemon on the team
 ** Parameters:  None
 ** Pre-Conditions: human object must've been created
 ** Post-Conditions:  The specified pokemon has been healed
 *********************************************************************/
void Human::heal(){
    int choice;
    
    cout << "Choose pokemon to heal: " << endl;
    printTeam();
    cin >> choice;

    team[choice-1] -> heal();

}




/*********************************************************************  
 ** Function:  swap()
 ** Description: swaps the active pokemon for any of the available pokemon
 ** Parameters:  None
 ** Pre-Conditions: human object must've been created
 ** Post-Conditions:  The active pokemon has been swapped
 *********************************************************************/
void Human::swap(){
    if(!isBeaten()){
        int choice;

        cout << "Choose pokemon to swap to: " << endl;
        printTeam();
        cin >> choice;

        activePokemon = team[choice - 1];

        cout << "Swapped!" << endl;
    }
}




/*********************************************************************  
 ** Function:  addPokemon()
 ** Description: Adds a pokemon to the team array
 ** Parameters:  None
 ** Pre-Conditions: human object must've been created
 ** Post-Conditions:  Based off the entered choice, a pokemon object is added to the team array
 *********************************************************************/
void Human::addPokemon(){
    presentFighters();
    int choice;
    cin >> choice;

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
 ** Function:  presentFighters()
 ** Description: Prints out the avaiable pokemon to choose from
 ** Parameters:  None
 ** Pre-Conditions: human object must've been created
 ** Post-Conditions:  The menu of fighters is printed to the screen
 *********************************************************************/
void Human::presentFighters(){
    cout << "Pokemon Options" << endl;
    cout << "---------------" << endl;
    cout << "1. Bulbasaur" << endl;
    cout << "2. Charmander" << endl;
    cout << "3. Pikachu" << endl;
    cout << "4. Squirtle" << endl;
}
