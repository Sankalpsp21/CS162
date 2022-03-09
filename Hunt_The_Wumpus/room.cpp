/*********************************************************************  
 ** Program Filename: room.cpp
 ** Author: Sankalp Patil
 ** Date: 2/18/22
 ** Description: The definition for the Room class 
 ** Input: None
 ** Output:  None
 *********************************************************************/
#include "room.h"




/*********************************************************************  
 ** Function:  Room()
 ** Description: The default constructor
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  Rooms object is created and member variables are initialized
 *********************************************************************/
Room::Room(){
    event = nullptr;
    symbol = " ";
}




/*********************************************************************  
 ** Function:  ~Room()
 ** Description: The default destructor
 ** Parameters:  None
 ** Pre-Conditions: A Room object must've been created
 ** Post-Conditions:  If the event pointer is not nullptr, it's contents are deleted
 *********************************************************************/
Room::~Room(){

    if(event){ //If the event pointer is not nullptr, delete whatever it's pointing at
        delete event;
    }
}




/*********************************************************************  
 ** Function:  getSymbol()
 ** Description: An accessor for the symbole member variable
 ** Parameters:  None
 ** Pre-Conditions: A Room object must've been created
 ** Post-Conditions:  The symbol is returned as a string
 *********************************************************************/
string Room::getSymbol(){
    return symbol;
}




//For manually setting a specific room's event. 
//Can also remove an event, changing it to an empty room
/*********************************************************************  
 ** Function:  setEvent()
 ** Description: A mutator function for setting the Room's event
 ** Parameters:  string event
 ** Pre-Conditions: A Room object must've been created
 ** Post-Conditions:  The event pointer is pointed to a new event and the symbol member variable is updated
 *********************************************************************/
void Room::setEvent(string event){
    if(event == "W"){
        this->event = new Wumpus();
        symbol = "W";

    }else if(event == "G"){
        this->event = new Gold();
        symbol = "G";

    }else if(event == "B"){
        this->event = new Bat();
        symbol = "B";

    }else if(event == "P"){
        this->event = new Pit();
        symbol = "P";

    }else if(event == "R"){
        this->event = new Rope();
        symbol = "R";
        
    }else{
        delete this->event; //deleting whatver was previously allocated at the event pointer;
        this->event = nullptr;
        symbol = " ";
    }
}



/*********************************************************************  
 ** Function:  getEvent()
 ** Description: An Accesor function that returns the event pointer
 ** Parameters:  None
 ** Pre-Conditions: A Room object must've been created
 ** Post-Conditions:  The event pointer is returned 
 *********************************************************************/
Event* Room::getEvent(){
    return event;
}




/*********************************************************************  
 ** Function:  hasEvent()
 ** Description: Checker to see if the event pointer is not nullptr
 ** Parameters:  None
 ** Pre-Conditions: A Room object must've been created
 ** Post-Conditions:  True is returned if event pointer is not nullptr, vice versa
 *********************************************************************/
bool Room::hasEvent(){
    return event;
}