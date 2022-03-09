/*********************************************************************  
 ** Program Filename: pokedex.cpp
 ** Author: Sankalp Patil
 ** Date: 1/20/21
 ** Description: Houses the implemenation for the pokedex class
 ** Input: None
 ** Output:  
 *********************************************************************/

#include <iostream>
#include "pokedex.h"
#include <fstream>

using namespace std;
#include <string>
#include <stdlib.h>


/*********************************************************************  
 ** Function:  Pokedex
 ** Description: The default constructor with optional arguments. Initializes all member variables
 ** Parameters:  int num_pokemon = 0, string trainer = ""
 ** Pre-Conditions: None
 ** Post-Conditions:  A pokedex object is constructed with initialized member variables
 *********************************************************************/ 
Pokedex::Pokedex(int num_pokemon, string trainer){
    this->num_pokemon = num_pokemon;
    pokemon_array = new Pokemon[num_pokemon];
    this->trainer = trainer;

}


/*********************************************************************  
 ** Function:  ~Pokedex
 ** Description: The destructor. Frees memory allocated to the dynamic Pokemon array
 ** Parameters:  None
 ** Pre-Conditions: pokemon_array must have been allocated
 ** Post-Conditions:  The pokedex object is deleted and the pokemon_array is freed from memory
 *********************************************************************/ 
Pokedex::~Pokedex(){
   delete[] pokemon_array;
}


/*********************************************************************  
 ** Function:  setTrainer
 ** Description: A mutator method setting the trainer member variable
 ** Parameters:  None
 ** Pre-Conditions: A pokedex object must have been created
 ** Post-Conditions:  The trainer member variable has been changed
 *********************************************************************/ 
void Pokedex::setTrainer(){
    string trainer;
    cout << "Enter the trainer's name: " << endl;
    cin >> trainer;
    this->trainer = trainer;
}


/*********************************************************************  
 ** Function:  getTrainer
 ** Description: An accesor method setting the trainer member variable
 ** Parameters:  None
 ** Pre-Conditions: A pokedex object must have been created
 ** Post-Conditions:  The trainer member variable has been changed
 *********************************************************************/ 
string Pokedex::getTrainer(){
    return trainer;
}



/*********************************************************************  
 ** Function:  getNum_pokemon
 ** Description: An accesor method getting the num_pokemon variable
 ** Parameters:  None
 ** Pre-Conditions: A pokedex object must have been created
 ** Post-Conditions:  The num_pokemon variable is returned
 *********************************************************************/ 
int Pokedex::getNum_pokemon(){
    return num_pokemon;
}


/*********************************************************************  
 ** Function:  addPokemon
 ** Description: An overloaded method meant for user-created pokemon
 **              Gets information and Adds a pokemon object to the pokemon array
 ** Parameters:  char* fileName
 ** Pre-Conditions: A pokedex object must have been created
 ** Post-Conditions:  The pokemon array has grown by 1 and now holds the new pokemon. 
 **                   New pokemon informaitno is also written to the original file.
 *********************************************************************/ 
void Pokedex::addPokemon(char* fileName){
    growPokedex();

    int dex;
    string name, type, move1, move2, move3, move4;

    cout << "Enter the Pokemon dex number" << endl;
    cin >> dex;

    cout << "Enter the Pokemon name" << endl;
    cin >> name;

    cout << "Enter the Pokemon's type" << endl;
    cin >> type;

    cout << "Enter the Pokemon's first move" << endl;
    cin >> move1;

    cout << "Enter the Pokemon's second move" << endl;
    cin >> move2;

    cout << "Enter the Pokemon's third move" << endl;
    cin >> move3;

    cout << "Enter the Pokemon's fourth move" << endl;
    cin >> move4;
    cout << " " << endl;

    updateFile(fileName, dex, name, type, move1, move2, move3, move4);
    addPokemon(num_pokemon, dex, name, type, move1, move2, move3, move4);
}


/*********************************************************************  
 ** Function:  addPokemon
 ** Description: An overloaded method meant for the initial file reading/loading
 ** Parameters:  int pos, int dex, string name, string type, string move1, string move2, string move3, string move4
 ** Pre-Conditions: A pokedex object must have been created
 ** Post-Conditions:  A pokemon object is added to the pokemon array.
 *********************************************************************/ 
void Pokedex::addPokemon(int pos, int dex, string name, string type, string move1, string move2, string move3, string move4){
    pokemon_array[pos].setDex(dex);
    pokemon_array[pos].setName(name);
    pokemon_array[pos].setType(type);
    pokemon_array[pos].setAbilities(move1, move2, move3, move4);
    num_pokemon = num_pokemon + 1;
}



/*********************************************************************  
 ** Function:  growPokedex
 ** Description: Dynamically increases the size of the pokemon array by one
 ** Parameters:  None
 ** Pre-Conditions: A pokedex object must have been created
 ** Post-Conditions:  The pokemon array size is increased by one.
 *********************************************************************/ 
void Pokedex::growPokedex(){

    //Creating a temp array that is 1 element longer
    Pokemon* temp = new Pokemon[num_pokemon + 1];

    //Copying over the elements to a temporary array
    for(int i = 0; i < num_pokemon; i++){
        temp[i] = pokemon_array[i];
    }

    //Freeing the memory allocated to the old array
    delete[] pokemon_array;

    //Creating a new array that is one element larger
    pokemon_array = new Pokemon[num_pokemon + 1];

    //Copying over the objects from our temp array
    for(int i = 0; i < num_pokemon + 1; i++){
        pokemon_array[i] = temp[i];
    }

    //Freeing the memory allocated to the temp array
    delete[] temp;

}


/*********************************************************************  
 ** Function:  updateFile
 ** Description: Updates the original file with the passed in information
 ** Parameters:  char* fileName, int dex, string name, string type, string move1, string move2, string move3, string move4
 ** Pre-Conditions: A pokedex object must have been created
 ** Post-Conditions:  The passed in information is correctly formatted and appended to the file that was passed in
 *********************************************************************/ 
void Pokedex::updateFile(char* fileName, int dex, string name, string type, string move1, string move2, string move3, string move4){
    ofstream f;
    f.open(fileName, ios::app);
    f << dex;
    f << ' ' + name + ' ';
    f << type + '\n';
    f << move1 + ' ';
    f << move2 + ' ';
    f << move3 + ' ';
    f << move4 + '\n';
    f.close();
}


/*********************************************************************  
 ** Function:  getListPokemon
 ** Description: An accesor function that returns pokemon from within the pokemon array
 ** Parameters:  int num
 ** Pre-Conditions: A pokedex object must have been created
 ** Post-Conditions:  The pokemon at the specified int num position is returned
 *********************************************************************/ 
Pokemon Pokedex::getListPokemon(int num){
    return pokemon_array[num];
}

