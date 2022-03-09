/*********************************************************************  
 ** Program Filename: arena.cpp 
 ** Author: Sankalp Patil
 ** Date: 1/31/22
 ** Description: Is the implementation for the facilitator file for all the files in Project 2
 ** Input: Various User Inputs
 ** Output:  Various Game Outputs
 *********************************************************************/

#include "arena.h"


/*********************************************************************  
 ** Function:  Arena
 ** Description: The default constructor. Prints out a welcome message and calls init()
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  init() has been called
 *********************************************************************/ 
Arena::Arena(){
    cout << "Welcome to Pokemon Battle Arena!" << endl;
    init();
}




/*********************************************************************  
 ** Function:  init()
 ** Description: Obtains user's name and populates the two teams
 ** Parameters:  None
 ** Pre-Conditions: An Arena object must have been created
 ** Post-Conditions:  
 *********************************************************************/ 
void Arena::init(){

    string name;
    cout << "Enter your name!" << endl;
    cin >> name;
    human.setName(name);
    

    for(int i = 0; i < 3; i++){
        cout << "Pick fighter #" << i + 1 << endl;
        human.addPokemon();
        computer.addPokemon();
    }
    printTeams();
}




/*********************************************************************  
 ** Function:  play()
 ** Description: Facilitates player turns and when to end the game
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  The Game has concluded
 *********************************************************************/ 
void Arena::play(){
    string cont;

    do{
        if(human.getActivePokemon().getSpeed() >= computer.getActivePokemon().getSpeed()){
            humanTurn();

            if(human.isBeaten() || computer.isBeaten()){
                break;
            }

            cout << "Enter any key to continue to opponent's turn" << endl;
            cin >> cont;
            
            clearScreen();
            compTurn();

        }else{

            compTurn();

            if(human.isBeaten() || computer.isBeaten()){
                break;
            }

            cout << "Enter any key to continue to your turn" << endl;
            cin >> cont;

            humanTurn();
        }

        cout << "Enter any key to continue to next round" << endl;
        cin >> cont;

    }while(!(human.isBeaten() || computer.isBeaten()));

   declareWinner();
}




/*********************************************************************  
 ** Function:  humanTurn()
 ** Description: Facilitates the human player's turn
 ** Parameters:  None
 ** Pre-Conditions: A Arena object must've been created
 ** Post-Conditions:  Human's turn has been complete
 *********************************************************************/ 
void Arena::humanTurn(){

    cout << "It's your turn!" << endl;
    int choice = printChoices();
    
    if(choice == 1){
        human.fight(computer);
        computer.updateStatus();

    }else if(choice == 2){
        human.heal();

    }else if(choice == 3){
        human.swap();
    }

    printTeams();
    
}




/*********************************************************************  
 ** Function:  compTurn()
 ** Description: Facilitates the computer player's turn
 ** Parameters:  None
 ** Pre-Conditions: A Arena object must've been created
 ** Post-Conditions:  Computer's turn has been complete
 *********************************************************************/ 
void Arena::compTurn(){

    cout << "Computer's turn!" << endl;
    int choice = genRandom123();

    if(choice == 1){
        cout << "Computer chose fight!" << endl;
        computer.fight(human);
        human.updateStatus();

    }else if(choice == 2){
        cout << "Computer chose heal!" << endl;
        computer.heal();

    }else if(choice == 3){
        cout << "Computer chose swap!" << endl;
        computer.swap();
    }

    printTeams();
}





/*********************************************************************  
 ** Function:  genRandom123()
 ** Description: Generates a random integer from 1-3 for the computer's play selection
 ** Parameters:  None
 ** Pre-Conditions: A Arena object must've been created
 ** Post-Conditions:  A random integer 1-3 has been returned
 *********************************************************************/ 
int Arena::genRandom123(){
    return(rand() % 3 + 1);
}




/*********************************************************************  
 ** Function:  declareWinner()
 ** Description: Prints out the winner of the game
 ** Parameters:  None
 ** Pre-Conditions: A Arena object must've been created
 ** Post-Conditions:  The winning player is printed to the screen.
 *********************************************************************/ 
void Arena::declareWinner(){

    if(human.isBeaten()){
        cout << computer.getName() << " wins!" << endl;
    }else{
        cout << human.getName() << " wins!" << endl;
    }


}




/*********************************************************************  
 ** Function:  printChoices()
 ** Description: Outputs a menu of choices that the player can choose and returns their choice
 ** Parameters:  None
 ** Pre-Conditions: A Arena object must've been created
 ** Post-Conditions:  Returns the player's choice as an int
 *********************************************************************/ 
int Arena::printChoices(){
    cout << "MENU" << endl;
    cout << "---------" << endl;
    cout << "1. Fight" << endl;
    cout << "2. Heal" << endl;
    cout << "3. Swap" << endl;

    int choice;
    cin >> choice;
    return choice;
}




/*********************************************************************  
 ** Function:  printTeams()
 ** Description: Outputs a both player's teams
 ** Parameters:  None
 ** Pre-Conditions: A Arena object must've been created
 ** Post-Conditions:  Both player's teams have been printed
 *********************************************************************/ 
void Arena::printTeams(){
    cout << "\n\n" << human.getName() << "'s Team\n-----------" << endl;
    human.printTeam(); 

    cout << computer.getName() << "'s Team\n-----------" << endl;
    computer.printTeam(); 
}




/*********************************************************************  
 ** Function:  clearScreen()
 ** Description: Prints a bunch of \n characters to clear the screen
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  The screen has been cleared
 *********************************************************************/ 
void Arena::clearScreen(){
    for(int i = 0; i < 100; i++){
        cout << '\n' << endl;
    }
}