#pragma once
/*********************************************************************  
 ** Program Filename: node.hpp
 ** Author: Sankalp Patil
 ** Date: 2/28/22
 ** Description: The file for the template class node. Holds the definition and implementation
 ** Input: None
 ** Output:  None
 *********************************************************************/

#include <stdlib.h>
#include <iostream>

using namespace std;

template <class T>
class Node{

    public:
        T value;
        Node* next;
    
    public:
        Node(T value);

};



/*********************************************************************  
 ** Function: Node<T>::Node
 ** Description: Constructor
 ** Parameters: T value
 ** Pre-Conditions: N/a
 ** Post-Conditions: Node created. Member variable value set equal to passed in value, next pointer set to nullptr
 *********************************************************************/
template<class T>
Node<T>::Node(T value){
    this->value = value;
    next = nullptr;
}

