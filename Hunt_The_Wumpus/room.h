#pragma once

/*********************************************************************  
 ** Program Filename: room.h
 ** Author: Sankalp Patil
 ** Date: 2/18/22
 ** Description: The definition for the Room class 
 ** Input: None
 ** Output:  None
 *********************************************************************/
#include <iostream>

#include "event.h"
#include "gold.h"
#include "bat.h"
#include "wumpus.h"
#include "pit.h"
#include "rope.h"


using namespace std;



class Room{
    private:
        Event* event;
        string symbol;
    
    public:
        Room();//Default constructor, sets room equal to nullptr
        ~Room();


        string getSymbol();
        
        void setEvent(string name);
        Event* getEvent();

        bool hasEvent();

};