#pragma once
/*********************************************************************  
 ** Program Filename: event.h
 ** Author: Sankalp Patil
 ** Date: 2/18/22
 ** Description: The definition for the event class 
 ** Input: None
 ** Output:  None
 *********************************************************************/
#include <iostream>

using namespace std;

class Event{
    public:
        Event();
        virtual ~Event();
        virtual void precept() = 0;
        virtual void encounter() = 0;

};