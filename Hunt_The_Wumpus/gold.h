#pragma once

/*********************************************************************  
 ** Program Filename: gold.h
 ** Author: Sankalp Patil
 ** Date: 2/18/22
 ** Description: The definition for the Gold class, inherits abstract class Event 
 ** Input: None
 ** Output:  None
 *********************************************************************/
#include <iostream>
#include "event.h"

using namespace std;

class Gold : public Event{
    public:
        Gold();
        void precept();
        void encounter();
};