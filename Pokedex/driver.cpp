/*********************************************************************  
 ** Program Filename: Driver 
 ** Author: Sankalp Patil
 ** Date: 1/20/22
 ** Description: Is the driver file for all the files in Project 1
 ** Input: Takes in a file name as a command line argument 
 ** Output:  A menu with options on how to search through the pokedex
 *********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "pokedex.h"
#include <sstream>

using namespace std;

/*********************************************************************  
 ** Function:  getFileName
 ** Description: Prompts the user for a fileName and returns it as a string
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  string fileName is returned
 *********************************************************************/ 
string getFileName(){
    string fileName;
    cout << "Enter the name of the file you'd like your results in: ";
    cin >> fileName;
    cout << " ";
    return fileName;
}


/*********************************************************************  
 ** Function:  fileOutput
 ** Description: Writes whatever text was passed in to a file
 ** Parameters:  string result
 ** Pre-Conditions: A string should be passed in that has whatever search info. getFileName() should return the name of a file.
 ** Post-Conditions:  the file fileName is either created or appended to with the string info that was passed in.
 *********************************************************************/ 
void fileOutput(string result){
    string fileName = getFileName();
    ofstream newFile;
    newFile.open(fileName.c_str(), ios::app);
    newFile << result;
    newFile.close();
    
}


/*********************************************************************  
 ** Function:  getOutputOption
 ** Description: returns an int signifying how the user wants their data outputted
 ** Parameters:  None
 ** Pre-Conditions: None
 ** Post-Conditions:  An int is returned signifying the user's choice
 *********************************************************************/ 
int getOutputOption(){
    int option;
    cout << "How would you like your results displayed?" << endl;
    cout << "1. Printed to the screen" << endl;
    cout << "2. Written to a file" << endl;
    cin >> option;

    while(cin.fail()){
        cout << "Not a valid option! \n" << endl;
        cin.clear();
        cin.ignore();
        cout << "How would you like your results displayed?" << endl;
        cout << "1. Printed to the screen" << endl;
        cout << "2. Written to a file" << endl;
        cin >> option;
    }

    return option;
    
}


/*********************************************************************  
 ** Function:  outputOption
 ** Description: Coordinates the output of whatever string was passed in
 ** Parameters:  string result
 ** Pre-Conditions: A string should be passed in that has whatever search info.
 ** Post-Conditions:  The string result is outputted, either to the terminal or to a file
 *********************************************************************/ 
void outputOption(string result){
    if (result == ""){
        cout << "No Pokemon matching your search was found\n" << endl;
    }else{
        int choice = getOutputOption();
        if(choice == 1){
            cout << result << endl;
        }else{
            fileOutput(result);
        }
    }
}



/*********************************************************************  
 ** Function:  searchByDex
 ** Description: Searches a pokedex based off a dex number
 ** Parameters:  Pokedex* myDex
 ** Pre-Conditions: A Pokedex pointer should be passed in 
 ** Post-Conditions:  The string result is filled with whatever information the search found and is passed to outputOption()
 *********************************************************************/ 
void searchByDex(Pokedex* myDex){
    int dexToSearch;
    cout << "Enter the dex number: ";
    cin >> dexToSearch;
    string result = "";

    for(int i = 0; i < (*myDex).getNum_pokemon(); i++){
        if((*myDex).getListPokemon(i).getDex() == dexToSearch){
            result = (*myDex).getListPokemon(i).printPokemon();
            break;
        }
    }
    outputOption(result);
}


/*********************************************************************  
 ** Function:  searchByName
 ** Description: Searches a pokedex based off a the name
 ** Parameters:  Pokedex* myDex
 ** Pre-Conditions: A Pokedex pointer should be passed in 
 ** Post-Conditions:  The string result is filled with whatever information the search found and is passed to outputOption()
 *********************************************************************/ 
void searchByName(Pokedex* myDex){
    string nameToSearch;
    cout << "Enter the name: ";
    cin >> nameToSearch;
    string result = "";

    for(int i = 0; i < (*myDex).getNum_pokemon(); i++){
        if((*myDex).getListPokemon(i).getName() == nameToSearch){
            result = (*myDex).getListPokemon(i).printPokemon();
            break;
        }
    }
    outputOption(result);
}


/*********************************************************************  
 ** Function:  searchByType
 ** Description: Searches a pokedex based off a type
 ** Parameters:  Pokedex* myDex
 ** Pre-Conditions: A Pokedex pointer should be passed in 
 ** Post-Conditions:  The string result is filled with whatever information the search found and is passed to outputOption()
 *********************************************************************/ 
void searchByType(Pokedex* myDex){
    string typeToSearch;
    cout << "Enter the type: ";
    cin >> typeToSearch;
    string result = "";

    for(int i = 0; i < (*myDex).getNum_pokemon(); i++){
        if((*myDex).getListPokemon(i).getType() == typeToSearch){
            result = result + (*myDex).getListPokemon(i).printPokemon();
        }
    }
    outputOption(result);
}


/*********************************************************************  
 ** Function:  directory
 ** Description: directs the program towards the appropriate search based off user input
 ** Parameters:  char* fileName, int choice, Pokedex* myDex
 ** Pre-Conditions: The appropriate parameters are passed in
 ** Post-Conditions:  The function calls the appropriate search function, passing in myDex.
 **                   It also returns and error message if the input was not valid.
 *********************************************************************/ 
void directory(char* fileName, int choice, Pokedex* myDex){
    switch(choice){
        case(1):
            searchByDex(myDex);
            break;
        case(2):
            searchByName(myDex);
            break;
        case(3):
            searchByType(myDex);
            break;
        case(4):
            (*myDex).addPokemon(fileName);
            break;
        case(5):
            break;
        default:
            cout << "Invalid Entry" << endl;
    }
}


/*********************************************************************  
 ** Function:  presentUserOptions
 ** Description: Prints the menu of options, gets the user input.
 ** Parameters:  char* fileName, Pokedex* myDex
 ** Pre-Conditions: The appropriate parameters should be passed in.
 ** Post-Conditions:  int choice will take the user's option and pass it, 
**                    along with fileName and myDex to directory()
 *********************************************************************/ 
void presentUserOptions(char* fileName, Pokedex* myDex){
    int choice;
    do{
        cout << "OPTIONS MENU" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Search by Dex Number" << endl;
        cout << "2. Search by Name" << endl;
        cout << "3. Search by Type" << endl;
        cout << "4. Add New Pokemon" << endl;
        cout << "5. Quit" << endl;
        cin >> choice;

        if(cin.fail()){
            cout << "Not a valid option! \n" << endl;
            cin.clear();
            cin.ignore();
        }else{
            directory(fileName, choice, myDex);
        }

    }while(choice != 5);
}


/*********************************************************************  
 ** Function:  parseData
 ** Description: Populates the passed in pokedex object with the information in the passed in file
 ** Parameters:  char* fileName, Pokedex* myDex, int num
 ** Pre-Conditions: The appropriate parameters should be passed in. 
 **                 Also, the pokedex object should have an initialized pokemon array
 ** Post-Conditions:  The string result is filled with whatever information the search found and is passed to outputOption()
 *********************************************************************/ 
void parseData(char* fileName, Pokedex* myDex, int num){
    ifstream readFile;
    readFile.open(fileName);
    string dex, name, type, move1, move2, move3, move4;
    getline(readFile, dex);

    for(int i = 0; i < num; i++){
        getline(readFile, dex, ' ');
        getline(readFile, name, ' ');
        getline(readFile, type, '\n');
        getline(readFile, move1, ' ');
        getline(readFile, move2, ' ');
        getline(readFile, move3, ' ');
        getline(readFile, move4, '\n');
        stringstream container(dex);
        int dex1;
        container >> dex1;
       (*myDex).addPokemon(i, dex1, name, type, move1, move2, move3, move4);
   }
   readFile.close();
}


/*********************************************************************  
 ** Function:  getNum_pokemonmon
 ** Description: Returns the number at the top of the file if it exists. Displays error message if not
 ** Parameters:  char* fileName
 ** Pre-Conditions: The appropriate parameters should be passed in. 
 **                 Also, the file passed in should be formatted as outlined in the assignment
 ** Post-Conditions:  The int num will be filled with the number at the top of the file and returned.
 **                   If no file was found with the given name, an error message is printed and program exits.                  
 *********************************************************************/ 
int getNum_pokemonmon(char* fileName){
    int num;
    ifstream readFile;
    readFile.open(fileName);
    if(readFile.is_open()){
        readFile >> num;
        readFile.close();
        return num;
    }else{
        cout << "File doesn't exist..." << endl;
        exit(EXIT_SUCCESS);
    }
}


int main(int argc, char* argv[]){
    int num = getNum_pokemonmon(argv[1]);
    Pokedex myDex(num);

    parseData(argv[1], &myDex, num);
    presentUserOptions(argv[1], &myDex);

    return 0;
}