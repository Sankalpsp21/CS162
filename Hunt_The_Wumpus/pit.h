#pragma once
/*********************************************************************  
 ** Program Filename: pit.h
 ** Author: Sankalp Patil
 ** Date: 2/18/22
 ** Description: The definition for the Pit class, inherits abstract class Event
 ** Input: None
 ** Output:  None
 *********************************************************************/
#include <iostream>
#include "event.h"

using namespace std;

class Pit : public Event{
    public:
        Pit();
        void precept();
        void encounter();
};