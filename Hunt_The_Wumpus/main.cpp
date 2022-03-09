/*********************************************************************  
 ** Program Filename: main.cpp 
 ** Author: Sankalp Patil
 ** Date: 2/18/22
 ** Description: Is the driver file for all the files in Project 3
 ** Input: int and bool command line arguments
 ** Output:  Message if the int argument was less than 4
 *********************************************************************/

#include <iostream>
#include "game.h"
#include <string>
using namespace std;


/*********************************************************************  
 ** Function:  main()
 ** Description: The main method. 
 ** Parameters:  int argc, char* argv[]
 ** Pre-Conditions: an int and boolean command line argument must have been entered
 ** Post-Conditions:  Game object is instantiated and played
 *********************************************************************/

int main(int argc, char* argv[]){
    bool debug = false;
    int size = atoi(argv[1]);

    if(string(argv[2]) == "true"){
        debug = true;
    }

    while(size < 4){
        cout << "Please enter a grid size greater than 3: ";
        cin >> size;
    }

    Game game(size, debug);
    game.play();


}