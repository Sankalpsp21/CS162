#pragma once
/*********************************************************************  
 ** Program Filename: game.h
 ** Author: Sankalp Patil
 ** Date: 2/18/22
 ** Description: The definition for the Game class 
 ** Input: None
 ** Output:  None
 *********************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib> //gives rand()
#include <ctime> //gives time() which is seconds since 1970 something. Needed to generate new seeds in srand()

#include "room.h"

using namespace std;

class Game{
    private:
        vector<vector<Room>> map;

        bool debug, gold, win, dead, wumpus;
        int size, playerRow, playerCol, pCopyRow, pCopyCol, w_Row, w_Col, g_Row, g_Col, arrows;
    
    private:
        void init();
        void populate();
        int genRandom(int limit);

        void display();
        void scanSurroundings(); //Looks in 4 directions and prints any precepts
        void playerTurn(); //Facilitates the player's turn, shooting or moving
        void updateStatus(); //Preform's any actions based off where the player is now.

        void printMapDebug();
        void printMap();

        char getPlayerMove();
        char getPlayerShoot();
        void printOptions();
        bool isValidMove(char move);

        void shoot(char shot);
        void move(char move);
        void wumpusMove();
        bool seventyFivePercentTrue();

        void replay();
        int printAgainOptions();
        void playNew();
        void playSame();
        

    public:
        Game(int size, bool debug);
        void play();
        




};
