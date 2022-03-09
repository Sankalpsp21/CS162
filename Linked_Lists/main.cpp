/*********************************************************************  
 ** Program Filename: main.cpp
 ** Author: Sankalp Patil
 ** Date: 2/28/22
 ** Description: The main file that drives the program 
 ** Input: Various user choices
 ** Output: Prompts, the linked list, number of prime numbers
 *********************************************************************/

#include "Linked_List.hpp"
#include <iostream>
#include <string>

using namespace std;

/*********************************************************************  
 ** Function: add_nums_front
 ** Description: Allows user to add values to front of linked list.
 ** Parameters: linked_list
 ** Pre-Conditions: linked_list exists
 ** Post-Conditions: linked_list added value.
 *********************************************************************/
template <typename T>
void add_nums_front(Linked_List<T> &list){
    string u_input;
    while (u_input != "n"){
        cout << "Would you like to add a number to the front of the list? (y/n): ";
        cin >> u_input;
        if (u_input != "n"){
            cout << "Enter a number: ";
            T new_num;
            cin >> new_num;
            list.push_front(new_num);
            cout << "Your list is now:" << endl;
            list.print();
        }    
    }
};

/*********************************************************************  
 ** Function: add_nums_back
 ** Description: Allows user to add values to end of linked list.
 ** Parameters: linked_list
 ** Pre-Conditions: linked_list exists
 ** Post-Conditions: linked_list added value.
 *********************************************************************/
template <typename T>
void add_nums_back(Linked_List<T> &list){
    string u_input;
    while (u_input != "n"){
        cout << "Would you like to add a number to the back of the list? (y/n): ";
        cin >> u_input;
        if (u_input != "n"){
            cout << "Enter a number: ";
            T new_num;
            cin >> new_num;
            list.push_back(new_num);
            cout << "Your list is now:" << endl;
            list.print();
        }    
    }
};

/*********************************************************************  
 ** Function: insert_nums
 ** Description: Allows user to insert vals into linked_list
 ** Parameters: linked_list
 ** Pre-Conditions: linked_list exists
 ** Post-Conditions: linked_list added a value at index
 *********************************************************************/
template <typename T>
void insert_nums(Linked_List<T> &list){
    string u_input;
    while (u_input != "n"){
        cout << "Would you like to insert a number into the list? (y/n): ";
        cin >> u_input;
        if (u_input != "n"){
            cout << "Enter a number: ";
            T new_num;
            cin >> new_num;
            cout << "Enter an index to enter it at: ";
            unsigned int index;
            cin >> index;
            list.insert(new_num, index);
            cout << "Your list is now:" << endl;
            list.print(); 
        }
    }
}

/*********************************************************************  
 ** Function: ascend_descend
 ** Description: Routes user to sort_ascending/sort_descending functions
 ** Parameters: linked_list
 ** Pre-Conditions: linked_list exists
 ** Post-Conditions: linked_list sorted
 *********************************************************************/
template <typename T>
void ascend_descend(Linked_List<T> &list){
    string u_input;
    cout << "Sort ascending or descending? (a/d): ";
    cin >> u_input;
    if (u_input == "a"){
        cout << "Your sorted list is:" << endl;
        list.sort_ascending();
        list.print();
    } else if (u_input == "d"){
        cout << "Your sorted list is:" << endl;
        list.sort_descending();
        list.print();
    }
}

int main(){

    char playing;
    int choice;

    do{
        cout << "Would you like to enter signed(1) or unsigned(2) integers?: ";
        cin >> choice;

        if(choice == 1){
            Linked_List<int> list; 
    
            add_nums_front(list);     // uncomment this line if you want to test push_front.
            add_nums_back(list);      // uncomment this line if you want to test push_back.
            insert_nums(list);        // uncomment this line it you want to test insert.
            ascend_descend(list);       // choose sort ascending or sort descending
            list.prime_count();         // function to count the number of primes
            list.clear();               // function to clear the linked_list

        }else{
            Linked_List<unsigned int> list;  
    
            add_nums_front(list);     // uncomment this line if you want to test push_front.
            add_nums_back(list);      // uncomment this line if you want to test push_back.
            insert_nums(list);        // uncomment this line it you want to test insert.
            ascend_descend(list);       // choose sort ascending or sort descending
            list.prime_count();         // function to count the number of primes
            list.clear();               // function to clear the linked_list
        }

        cout << "Do you want to do this again (y or n)?" << endl;
        cin >> playing;

    }while(playing != 110);          
};



