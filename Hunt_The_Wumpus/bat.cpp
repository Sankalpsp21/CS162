/*********************************************************************  
 ** Program Filename: bat.cpp
 ** Author: Sankalp Patil
 ** Date: 2/18/22
 ** Description: The definition for the Bat class 
 ** Input: None
 ** Output:  None
 *********************************************************************/
#include "bat.h"



/*********************************************************************  
 ** Function:  Bat()
 ** Description: The default constructor
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  Bat object created
 *********************************************************************/
Bat::Bat(){
}



/*********************************************************************  
 ** Function:  precept()
 ** Description: Prints out the precept
 ** Parameters:  None
 ** Pre-Conditions: Bat object must've been created
 ** Post-Conditions:  Precept has been printed
 *********************************************************************/
void Bat::precept(){
    cout << "You hear wings flapping." << endl;
}



/*********************************************************************  
 ** Function:  encounter()
 ** Description: Prints out a message for the encounter
 ** Parameters:  None
 ** Pre-Conditions: Bat object must've been created
 ** Post-Conditions:  Message has been printed
 *********************************************************************/
void Bat::encounter(){
    cout << "You stumble upon a Super Bat! It grabs your shoulders and takes off..." << endl;
}

