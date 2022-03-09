/*********************************************************************  
 ** Program Filename: wumpus.cpp
 ** Author: Sankalp Patil
 ** Date: 2/18/22
 ** Description: The definition for the Wumpus class 
 ** Input: None
 ** Output:  None
 *********************************************************************/
#include "wumpus.h"


/*********************************************************************  
 ** Function:  wumpus()
 ** Description: The default constructor
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  wumpus object created
 *********************************************************************/
Wumpus::Wumpus(){}


/*********************************************************************  
 ** Function:  precept()
 ** Description: Prints out the precept
 ** Parameters:  None
 ** Pre-Conditions: wumpus object must've been created
 ** Post-Conditions:  Precept has been printed
 *********************************************************************/
void Wumpus::precept(){
    cout << "You smell a terrible stench." << endl;
}



/*********************************************************************  
 ** Function:  encounter()
 ** Description: Prints out a message for the encounter
 ** Parameters:  None
 ** Pre-Conditions: wumpus object must've been created
 ** Post-Conditions:  Message has been printed
 *********************************************************************/
void Wumpus::encounter(){
    cout << "You stumble upon the Wumpus! The Discord logo is a lot cuter, you think as it bashes your skull in..." << endl;
}

