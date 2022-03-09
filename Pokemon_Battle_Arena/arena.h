#pragma once
/*********************************************************************  
 ** Program Filename: arena.h 
 ** Author: Sankalp Patil
 ** Date: 1/31/22
 ** Description: Is the definition for the facilitator file for all the files in Project 2
 ** Input: Various User Inputs
 ** Output:  Various Game Outputs
 *********************************************************************/
#include "human.h"
#include "computer.h"
#include <iostream>

using namespace std;

class Arena{
    private:
        Human human;
        Computer computer;
    
    public:
        Arena();
        void play();
    
    private:
        void init();
        void humanTurn();
        void compTurn();

        int genRandom123();
        void declareWinner();
        int printChoices();
        void printTeams();
        void clearScreen();





};