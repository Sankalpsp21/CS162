/*********************************************************************  
 ** Program Filename: game.cpp 
 ** Author: Sankalp Patil
 ** Date: 2/18/22
 ** Description: The implementation file for the Game class
 ** Input: None
 ** Output:  None
 *********************************************************************/


#include <iostream>
#include <stdlib.h>
#include "game.h"


/*********************************************************************  
 ** Function:  Game()
 ** Description: The only Constructor (This is the only way the Game object is instantiated)
 ** Parameters:  int size, bool debug
 ** Pre-Conditions: an int and boolean command argument must have been entered
 ** Post-Conditions:  Time is seeded, member variables debig and size are initialized, init() called
 *********************************************************************/
Game::Game(int size, bool debug){
    srand(time(0));

    this->debug = debug;
    this->size = size;

    init();
}




//Properly sizes and populates the map
//---------------------
/*********************************************************************  
 ** Function:  init()
 ** Description: Initializes the game and all the member variables 
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  Game object is fully initialized
 *********************************************************************/
void Game::init(){
    arrows = 3;
    gold = false;
    dead = false;
    win = false;
    wumpus = true;

    map.resize(size);

    for(int i = 0; i < size; i++){
        map[i].resize(size, Room());
    }

    populate();
}




/*********************************************************************  
 ** Function:  populate()
 ** Description: Populates the map member variable with events randomly. 
                 Keeps track of where the wumpus, gold, and player were placed
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created. Map must've been resized
 ** Post-Conditions:  Map is populated and player position is assigned
 *********************************************************************/
void Game::populate(){
    string events[6] = {"W", "G", "P", "P", "B", "B"};
    int row, col;

    for(string event : events){
        do{
            row = genRandom(size);
            col = genRandom(size);

        }while(map[row][col].hasEvent());
        
        if(event == "W"){
            w_Row = row;
            w_Col = col;

        }else if(event == "G"){
            g_Row = row;
            g_Col = col;
        }

        map[row][col].setEvent(event);
    }

    do{
            row = genRandom(size);
            col = genRandom(size);

    }while(map[row][col].hasEvent());
    
    playerRow = row;
    pCopyRow = row;

    playerCol = col;
    pCopyCol = col;

    map[row][col].setEvent("R");
}




/*********************************************************************  
 ** Function:  genRandom()
 ** Description: Returns a random int from 0 to limit 
 ** Parameters:  int limit
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  A random int between 0 and limit is returned
 *********************************************************************/
int Game::genRandom(int limit){
    return(rand() % limit);
}
//---------------------





//Main driver of the game!
/*********************************************************************  
 ** Function:  play()
 ** Description: Is the main driver of the game 
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created and initialized
 ** Post-Conditions:  Game is finished
 *********************************************************************/
void Game::play(){
    do{
        //This section prints the current map
        display();

        //This section will print precepts
        scanSurroundings();

        //This section will move the player or facilitate shooting an arrow
        playerTurn();

        //Will look at the current room and preform actions as neccesary
        updateStatus();


    }while(!(dead || win));

    if(win){
        cout << "Congratulations!! You got the gold and escaped the cave! \nGAME OVER" << endl;

    }else{
        cout << "GAME OVER" << endl;
        replay();
    }
}




/*********************************************************************  
 ** Function:  replay()
 ** Description: Presents and facilitates options to play again or quit the game 
 ** Parameters:  None
 ** Pre-Conditions: Player has died
 ** Post-Conditions:  Game is either replayed or quit
 *********************************************************************/
void Game::replay(){
    int choice = printAgainOptions();

    if(choice == 1){
        playSame();
        play();

    }else if(choice == 2){
        playNew();
        play();
    }

}




/*********************************************************************  
 ** Function:  printAgainOptions()
 ** Description: Prints options, obtains and returns the user's choice for playing again or quitting
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  An int is returned
 *********************************************************************/
int Game::printAgainOptions(){
    int choice;

    do{
        cout << "1. Play again in the same cave." << endl;
        cout << "2. Play again in a different cave." << endl;
        cout << "3. Quit" << endl;
        cin >> choice;
    }while(choice < 1 || choice > 3);

    return choice;
}





/*********************************************************************  
 ** Function:  playNew()
 ** Description: Reinitialies all member variables and populates a new map 
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  A new "game" is fully initialized (Not a new game object)
 *********************************************************************/
void Game::playNew(){
    arrows = 3;
    gold = false;
    dead = false;
    win = false;
    wumpus = true;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            map[i][j].setEvent("Empty");
        }
    }

    populate();
}




/*********************************************************************  
 ** Function:  playSame()
 ** Description: Reinitializes all member variables and resets map to original state
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  The same "game" is fully initialized (Not a new game object)
 *********************************************************************/
void Game::playSame(){
    arrows = 3;
    gold = false;
    dead = false;
    win = false;
    wumpus = true;

    playerRow = pCopyRow;
    playerCol = pCopyCol;

    for(int i = 0; i < size; i++){ //Finding and removing current wumpus (In case it moved)
        for(int j = 0; j < size; j++){
            if(map[i][j].getSymbol() == "W"){
                map[i][j].setEvent("Empty");
            }
        }
    }

    map[w_Row][w_Col].setEvent("Empty");
    map[w_Row][w_Col].setEvent("W");

    map[g_Row][g_Col].setEvent("Empty");
    map[g_Row][g_Col].setEvent("G");

}




//Following 4 are used in play() 
//-------------------

/*********************************************************************  
 ** Function:  display()
 ** Description: Prints out the map to the terminal based off of the debug true/false value
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  Map is printed to the terminal
 *********************************************************************/
void Game::display(){
    if(debug){
        printMapDebug();
    }else{
        printMap();
    }
}





/*********************************************************************  
 ** Function:  scanSurroundings()
 ** Description: Prints the precepts of all adjacent rooms if they have an event
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  Precepts are printed
 *********************************************************************/
void Game::scanSurroundings(){

    if(playerRow > 0){
        if(map[playerRow - 1][playerCol].hasEvent()){
            map[playerRow - 1][playerCol].getEvent()->precept();
        }
    }

     if(playerRow < (size - 1)){
        if(map[playerRow + 1][playerCol].hasEvent()){
            map[playerRow + 1][playerCol].getEvent()->precept();
        }
    }

     if(playerCol > 0){
        if(map[playerRow][playerCol - 1].hasEvent()){
            map[playerRow][playerCol - 1].getEvent()->precept();
        }
    }

     if(playerRow < (size - 1)){
        if(map[playerRow][playerCol + 1].hasEvent()){
            map[playerRow][playerCol + 1].getEvent()->precept();
        }
    }

}




/*********************************************************************  
 ** Function:  playerTurn()
 ** Description: Get's the player's move and preforms it
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  The player's move has been executed
 *********************************************************************/
void Game::playerTurn(){
    char playerMove = getPlayerMove();
    char playerShoot;

    if(playerMove == ' '){

        playerShoot = getPlayerShoot();
        shoot(playerShoot);

        if(wumpus){ //If the wumpus is still alive after arrow has been shot, he might move
            wumpusMove();
        }
    }else{
        move(playerMove); //Changes player's position
    }
}




/*********************************************************************  
 ** Function:  updateStatus()
 ** Description: Looks at the current map and preforms any encounters, ends the game, as appropriate
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  Encounters have been called and the game status has been updated
 *********************************************************************/
void Game::updateStatus(){
    if(map[playerRow][playerCol].getSymbol() == "W" || map[playerRow][playerCol].getSymbol() == "P"){
        map[playerRow][playerCol].getEvent()->encounter();
        dead = true;


    }else if(map[playerRow][playerCol].getSymbol() == "B"){
        map[playerRow][playerCol].getEvent()->encounter();

        playerRow = genRandom(size);
        playerCol = genRandom(size);
        updateStatus(); //Needed in case player gets dropped off at another event


    }else if(map[playerRow][playerCol].getSymbol() == "G"){
        map[playerRow][playerCol].getEvent()->encounter();
        gold = true;
        map[playerRow][playerCol].setEvent("Empty"); //After gold is picked up, remove "Gold" event from room


    }else if(map[playerRow][playerCol].getSymbol() == "R" && gold){ //Winning conditions
        win = true;
    }

}
//--------------------





//Map Printing Functions
//----------------------

/*********************************************************************  
 ** Function:  printMapDebug()
 ** Description: Prints the map in it's debug mode (Shows all events)
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  Map is printed in debug mode
 *********************************************************************/
void Game::printMapDebug(){
    for(unsigned int row = 0; row < map.size(); row++){
        cout << "+";

        for (unsigned int i = 0; i < map.size(); i++){ // Top and Bottom of each square in the map
            cout << "-----+";
        }
    
        for (int i = 0; i < 3; i++){ // Height of each square within the map
            cout << '\n';
            cout << "|"; // Left side of each square within the map

            for(unsigned int col = 0; col < map.size(); col++){
                if(i == 1 && row == playerRow && col == playerCol){
                    cout << "  *  |";

                }else if(i == 1){
                    cout << "  " << map[row][col].getSymbol() <<  "  |"; // Inside and Right border of each square within the map

                }else{
                    cout << "     |";
                }
            }
        }
        
        cout << endl;
    }

    cout << "+";

    for (unsigned int i = 0; i < map.size(); i++){ // Bottom of map
        cout << "-----+";
    }
    cout << endl;
}




/*********************************************************************  
 ** Function:  printMap()
 ** Description: Prints the map in regular mode (Doesn't show any events)
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  Map is printed in regular mode
 *********************************************************************/
void Game::printMap(){
    for(unsigned int row = 0; row < map.size(); row++){
        cout << "+";

        for (unsigned int i = 0; i < map.size(); i++){ // Top and Bottom of each square in the map
            cout << "-----+";
        }
    
        for (int i = 0; i < 3; i++){ // Height of each square within the map
            cout << '\n';
            cout << "|"; // Left side of each square within the map

            for(unsigned int col = 0; col < map.size(); col++){
                if(i == 1 && row == playerRow && col == playerCol){
                    cout << "  *  |";

                }else{
                    cout << "     |";
                }
            }
        }
        
        cout << endl;
    }

    cout << "+";

    for (unsigned int i = 0; i < map.size(); i++){ // Bottom of map
        cout << "-----+";
    }
    cout << endl;
}
//----------------------





//Following 4 are used to get valid move from user
//----------------
/*********************************************************************  
 ** Function:  getPlayerMove()
 ** Description: Returns a valid player move as a char
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  A char has been returned that is a valid player move
 *********************************************************************/
char Game::getPlayerMove(){
    char playerMove;

    do{
        printOptions();

        system("stty -echo"); // supress echo
        system("stty cbreak"); // go to RAW mode

        playerMove = getchar();

        system ("stty echo"); // Make echo work
        system("stty -cbreak");// go to COOKED mode 

    }while(!isValidMove(playerMove));

    return playerMove; //A move that is valid
}




/*********************************************************************  
 ** Function:  getPlayerShoot()
 ** Description: Returns a valid player shoot as a char
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created and the player move must've been a space " "
 ** Post-Conditions:  A char has been returned that is a player shoot
 *********************************************************************/
char Game::getPlayerShoot(){
    char playerShoot;

    cin >> playerShoot;

    return playerShoot; //A Shoot direction
}




/*********************************************************************  
 ** Function:  printOptions()
 ** Description: Prints out available moves that the user can do
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  Available moves have been printed
 *********************************************************************/
void Game::printOptions(){
    cout << "'w'  'a'  's'  'd' to move" << endl;
    cout << "' w' ' a' ' s' ' d' to shoot arrow" << endl;
}




/*********************************************************************  
 ** Function:  isValidMove()
 ** Description: Checks to see if the move passed in is valid given the current game state
 ** Parameters:  char playerMove
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  A bool is returned based off whether the passed in move was valid or not
 *********************************************************************/
bool Game::isValidMove(char playerMove){
    if (playerMove == ' '){

        if(arrows > 0){
            return true;
        }else{
            return false;
        }
    }

    if (playerMove == 'w' && playerRow > 0){ //Player not currently at top row
        return true;
    }

    if (playerMove == 's' && playerRow < (size - 1)){ //Player not currently at bottom row
        return true;
    }

    if (playerMove == 'a' && playerCol > 0){ //Player not currently at leftmost column
        return true;
    }

    if (playerMove == 'd' && playerCol < (size - 1)){//Player not currently at rightmost column
        return true;
    }

    return false;
}
//------------------





//Following 2 are used to preform the user's move.
//------------------
/*********************************************************************  
 ** Function:  shoot()
 ** Description: Shoots an arrow in the passed in direction and carries out any consequences
 ** Parameters:  char shot
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  Shoots an arrow in the passed in direction and carries out any consequences
 *********************************************************************/
void Game::shoot(char shot){
    int rowArrow = playerRow; //Setting the starting position of the arrow's flight
    int colArrow = playerCol;
    int distance = 0;

    do{
        if(shot == 'w'){
            rowArrow--; //Moving up

        }else if(shot == 's'){
            rowArrow++; //Moving down

        }else if(shot == 'a'){
            colArrow--; //Moving left

        }else{
            colArrow++; //Moving right
        }

        if (rowArrow < 0 || rowArrow >= size || colArrow < 0 || colArrow >= size){ //Hitting a wall/out of bounds
            break;
        }

        if(map[rowArrow][colArrow].getSymbol() == "W"){ //Hitting the Wumpus, sets the room to empty. Wumpus no longer on map!
            map[rowArrow][colArrow].setEvent("Empty");
            wumpus = false;
            cout << "You hear a terrible roar, the creature is dead!" << endl;
            break;
        }

        distance++;
    }while(distance < 3);

    arrows--; //User has one less arrow
}




/*********************************************************************  
 ** Function:  move()
 ** Description: changes the players coordinates based off the move passed in
 ** Parameters:  char move
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  Player coordinates have been updated
 *********************************************************************/
void Game::move(char move){

    if (move == 'w'){
        playerRow--;
    }

    if (move == 's'){
        playerRow++;
    }

    if (move == 'a'){
        playerCol--;
    }

    if (move == 'd'){
        playerCol++;
    }

}




/*********************************************************************  
 ** Function:  whumpusMove()
 ** Description: Changes the wumpus's position 75% of the time
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  75% chance that the wumpus has moved to another room
 *********************************************************************/
void Game::wumpusMove(){
    if(seventyFivePercentTrue()){
        int newRow, newCol;

        for(int i = 0; i < size; i++){ //Finding and removing current wumpus
            for(int j = 0; j < size; j++){
                if(map[i][j].getSymbol() == "W"){
                    map[i][j].setEvent("Empty");
                }
            }
        }

        do{ //Randomly assigning wumpus to an empty room
            newRow = genRandom(size);
            newCol = genRandom(size);

        }while(map[newRow][newCol].hasEvent());

        map[newRow][newRow].setEvent("W");
    }

}




/*********************************************************************  
 ** Function:  seventyFivePercentTrue()
 ** Description: Returns true 75% of the time and false the other 25%
 ** Parameters:  None
 ** Pre-Conditions: A Game object must've been created
 ** Post-Conditions:  True is returned 75% of the time and False the other 25%
 *********************************************************************/
bool Game::seventyFivePercentTrue(){
    int num = rand() % 100 + 1;

    if(num < 75){
        return true;

    }else{
        return false;
    }
}
//-------------------




