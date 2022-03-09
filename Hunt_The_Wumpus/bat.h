#pragma once

/*********************************************************************  
 ** Program Filename: bat.h
 ** Author: Sankalp Patil
 ** Date: 2/18/22
 ** Description: The definition for the Bat class, inherits abstract class Event
 ** Input: None
 ** Output:  None
 *********************************************************************/
#include <iostream>
#include "event.h"
#include <cstdlib> //gives rand()
#include <ctime> //gives time() which is seconds since 1970 something. Needed to generate new seeds in srand()

using namespace std;

class Bat : public Event{
    public:
        Bat();
        void precept();
        void encounter();
};