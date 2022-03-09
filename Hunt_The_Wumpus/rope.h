#pragma once
/*********************************************************************  
 ** Program Filename: rope.h
 ** Author: Sankalp Patil
 ** Date: 2/18/22
 ** Description: The definition for the Rope class, inherits abstract class Event 
 ** Input: None
 ** Output:  None
 *********************************************************************/
#include <iostream>
#include "event.h"

using namespace std;

class Rope : public Event{
    public:
        Rope();
        void precept();
        void encounter();
};