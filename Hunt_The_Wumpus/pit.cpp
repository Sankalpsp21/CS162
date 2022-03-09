/*********************************************************************  
 ** Program Filename: pit.cpp
 ** Author: Sankalp Patil
 ** Date: 2/18/22
 ** Description: The definition for the Pit class 
 ** Input: None
 ** Output:  None
 *********************************************************************/
#include "pit.h"


/*********************************************************************  
 ** Function:  pit()
 ** Description: The default constructor
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  pit object created
 *********************************************************************/
Pit::Pit(){}


/*********************************************************************  
 ** Function:  precept()
 ** Description: Prints out the precept
 ** Parameters:  None
 ** Pre-Conditions: pit object must've been created
 ** Post-Conditions:  Precept has been printed
 *********************************************************************/
void Pit::precept(){
    cout << "You feel a breeze." << endl;
}


/*********************************************************************  
 ** Function:  encounter()
 ** Description: Prints out a message for the encounter
 ** Parameters:  None
 ** Pre-Conditions: pit object must've been created
 ** Post-Conditions:  Message has been printed
 *********************************************************************/
void Pit::encounter(){
    cout << "You fell to your death..." << endl;
}
