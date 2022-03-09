#pragma once
/*********************************************************************  
 ** Program Filename: wumpus.h
 ** Author: Sankalp Patil
 ** Date: 2/18/22
 ** Description: The definition for the Wumpus class, inherits abstract class Event 
 ** Input: None
 ** Output:  None
 *********************************************************************/
#include <iostream>
#include "event.h"

using namespace std;

class Wumpus : public Event{
    public:
        Wumpus();
        void precept();
        void encounter();
};