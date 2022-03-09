#pragma once

/*********************************************************************  
 ** Program Filename: Linked_List.hpp
 ** Author: Sankalp Patil
 ** Date: 2/28/22
 ** Description: The file for the template class Linked_List. Holds the definition and implementation
 ** Input: None
 ** Output:  None
 *********************************************************************/

#include "node.hpp"

template <class T>
class Linked_List{
   private:                         // DO NOT CHANGE THE STRUCTURE OF THIS CLASS' VARIABLES
      unsigned int length;          // the number of nodes contained in the list
      Node<T> *head;                   // a pointer to the first node in the list

   public:
      Linked_List();
      ~Linked_List();                        // creates the linked list
   
      unsigned int get_length();             // returns the length of the linked list
   
      void print();                          // output a list of all integers contained within the list
      void clear();                          // delete the entire list (remove all nodes and reset length to 0)
   
      unsigned int push_front(T);            // insert a new val at the front of the list (returns the new length of the list)
      unsigned int push_back(T);             // insert a new val at the back of the list (returns the new length of the list)
   
      void sort_ascending();                 // sorts list with smallest val at front
      void sort_descending();                // sorts list with largest val at front
   
      unsigned int insert(T, unsigned int);  // inserts val at given index (val, index)
   
      void prime_count();                    // display prime numbers to terminal.

      void selectionSort(Node<T> **head);

   private:
        bool isPrime(T val);

        void mergeSort(Node<T>** head);
        void split(Node<T>* headRef, Node<T>** frontRef, Node<T>** backRef);
        Node<T>* merge(Node<T>* a, Node<T>* b);

        void swap(Node<T>** head, int maxValue);
                                                                  
};




/*********************************************************************  
 ** Function: Linked_List::Linked_List
 ** Description: Constructor
 ** Parameters: N/a
 ** Pre-Conditions: N/a
 ** Post-Conditions: linked_list created. No return.
 *********************************************************************/
template<class T>
Linked_List<T>::Linked_List(){
    length = 0;
    head = nullptr;
}




/*********************************************************************  
 ** Function: Linked_List::~Linked_List
 ** Description: Destructor
 ** Parameters: N/a
 ** Pre-Conditions: linked_list exists
 ** Post-Conditions: linked_list destroyed. No return
 *********************************************************************/
template<class T>
Linked_List<T>::~Linked_List(){
    if(length > 0){
        clear();
    }
}





/*********************************************************************  
 ** Function: Linked_List::get_length
 ** Description: returns length
 ** Parameters: N/a
 ** Pre-Conditions: linked_list exists
 ** Post-Conditions: length returned to caller.
 *********************************************************************/
template<class T>
unsigned int Linked_List<T>::get_length(){
    return length;
}





/*********************************************************************  
 ** Function: Linked_List::print
 ** Description: prints list contents to terminal.
 ** Parameters: N/a
 ** Pre-Conditions: linked_list exists
 ** Post-Conditions: List contents printed to terminal
 *********************************************************************/
template<class T>
void Linked_List<T>::print(){
    Node<T> *n = head;

    while(n != nullptr){
        cout << n->value << " ";
        n = n->next;
    }

    cout << endl;
}




/*********************************************************************  
 ** Function: Linked_List::clear
 ** Description: deletes Linked_list from memory.
 ** Parameters: N/a
 ** Pre-Conditions: linked_list exists
 ** Post-Conditions: List contents cleared from memory.
 *********************************************************************/
template<class T>
void Linked_List<T>::clear(){
    if(head == nullptr){ //List already doesn't exist
        return;
    }

    Node<T> *c = head;
    Node<T> *next = nullptr;

    while(c != nullptr){
        next = c->next; //So we can still access the list

        delete c; //Deleting the front node

        c = next;
    }
    
    head = nullptr;
    length = 0;
}



/*********************************************************************  
 ** Function: Linked_List::push_front
 ** Description: Adds a new value value to the front of the list.
 ** Parameters: T new_value
 ** Pre-Conditions: linked_list exists
 ** Post-Conditions: List contents changed, new value pushed to front of list.
 *********************************************************************/
template<class T>
unsigned int Linked_List<T>::push_front(T new_value){
    Node<T> *newNode = new Node<T>(new_value);

    if(head == nullptr){
        head = newNode;
        length++;
        return length;
    }

    newNode->next = head;
    head = newNode;
    length++;
    return length;
}




/*********************************************************************  
 ** Function: Linked_List::push_back
 ** Description: Adds a new value to the back of the list.
 ** Parameters: T new_value
 ** Pre-Conditions: linked_list exists
 ** Post-Conditions: List contents changed, new value pushed to back of list.
 *********************************************************************/
template<class T>
unsigned int Linked_List<T>::push_back(T new_value){
    Node<T> *newNode = new Node<T>(new_value);
    Node<T> *n = head;

    if(n == nullptr){
        head = newNode;
        length++;
        return length;
    }

    while(n->next != nullptr){//Getting to the last node
        n = n->next;
    }

    n->next = newNode;
    length++;
    return length;
}





/*********************************************************************  
 ** Function: Linked_List::prime_count
 ** Description: Counts and outputs the primes in a linked_list to terminal
 ** Parameters: N/a
 ** Pre-Conditions: Linked list exists
 ** Post-Conditions: List contents printed to terminal.
 *********************************************************************/
template<class T>
void Linked_List<T>::prime_count(){
    int numPrimes = 0;

    if(head == nullptr){ //List already doesn't exist
        cout << numPrimes << endl;
        return;
    }

    Node<T> *n = head;

    while(n != nullptr){
        if(isPrime(n->value)){
            numPrimes++;
        }
        n = n->next; 
    }

    cout << numPrimes  << " primes" << endl;

}




/*********************************************************************  
 ** Function: Linked_List::isPrime
 ** Description: Takes a number and determines if it is prime
 ** Parameters: T val
 ** Pre-Conditions: Linked list exists
 ** Post-Conditions: boolean value returned
 *********************************************************************/
template<class T>
bool Linked_List<T>::isPrime(T val){
    if(val < 2){
        return false;

    }else if(val == 2){
        return true;

    }else{
        for(int divider = 2; divider <= val / 2; divider++){
            if(val % divider == 0){
                return false; //Not a prime
            }
        }

        return true;
    }

}







/*********************************************************************  
 ** Function: Linked_List::insert
 ** Description: Allows user to insert value to list at a given index.
 ** Parameters: T new_value and int index
 ** Pre-Conditions: linked_list exists
 ** Post-Conditions: list contents changed, new_val is inserted into list at given index.
 *********************************************************************/
template<class T>
unsigned int Linked_List<T>::insert(T new_value, unsigned int index){
    Node<T> *n = head;
    Node<T> *newNode = new Node<T>(new_value);

    if(head == nullptr){
        return length;
    }

    if(index > length){
        cout << "Invalid Index!" << endl;
        return length;
    }

    if(index == 0){
        push_front(new_value);
        return length;
    }

    for(int i = 0; i < index - 1; i++){

        if(n == nullptr){ //Index out of bounds
            return length;
        }

        n = n->next;
    }

    newNode->next = n->next;
    n->next = newNode;

    length++;
    return length;
}








/*********************************************************************  
 ** Function: Linked_List::sort_ascending
 ** Description: Uses mergesort method to sort list in ascending order
 ** Parameters: N/a
 ** Pre-Conditions: linked_list exists
 ** Post-Conditions: List contents reordered, sorted with smallest value at front.
 *********************************************************************/
template<class T>
void Linked_List<T>::sort_ascending(){
    mergeSort(&head);
}




/*********************************************************************  
 ** Function: Linked_List::mergeSort
 ** Description: Preforms ascending mergeSort on the passed in linkedList
 ** Parameters: Node<T> **actualHead
 ** Pre-Conditions: Linked list exists
 ** Post-Conditions: The LinkedList has been sorted
 *********************************************************************/
template<class T>
void Linked_List<T>::mergeSort(Node<T>** actualHead){
    Node<T> *localHead = *actualHead;
    Node<T> *left = nullptr;
    Node<T> *right = nullptr;

    if(localHead == nullptr || localHead->next == nullptr){
        return;
    }

    split(localHead, &left, &right);

    mergeSort(&left);
    mergeSort(&right);


    *actualHead = merge(left, right);//Changing the true head by dereferencing
}





/*********************************************************************  
 ** Function: Linked_List::split
 ** Description: Splits the passed in LinkedList into two halves which are assigned to the passed-by-reference lists
 ** Parameters: Node<T>*, Node<T>**, Node<T>**
 ** Pre-Conditions: Linked list exists
 ** Post-Conditions: The 2 passed in lists are equally assigned the 2 halves of the original
 *********************************************************************/
template<class T>
void Linked_List<T>::split(Node<T>* original, Node<T>** frontHalf, Node<T>** backHalf){
    //Setting front and back halves by reference
    //Obviously need the original full list, not as a ref since we aren't changing it

    Node<T>* mid = original;

    int len = 0;

    while(mid != nullptr){ //Getting the length of the list
        mid = mid->next;
        len++;
    }

    mid = original;

    for(int i = 0; i < (len / 2) - 1; i++){ //Putting mid at the middle of the list
        mid = mid->next;
    }


    *frontHalf = original; //Start of first half is at the beginning
    *backHalf = mid->next; //Start of second half is one after the mid point
    mid->next = nullptr; //Setting the end for the first half (cutting off the frontHalf)
}






/*********************************************************************  
 ** Function: Linked_List::merge
 ** Description: Recursively merges the 2 linked lists. Returns the head of the merged list
 ** Parameters: Node<T>*, Node<T>*
 ** Pre-Conditions: Linked list exists
 ** Post-Conditions: The 2 passed in lists are merged into a new list and returned
 *********************************************************************/
template<class T>
Node<T>* Linked_List<T>::merge(Node<T>* front, Node<T>* back){
    Node<T> *toReturn = nullptr;

    

    if(front == nullptr){ //Base Case for whenever one list runs out
        return back;

    }else if(back == nullptr){
        return front;
    }


    if(front->value <= back->value){
        toReturn = front;
        
        //Calling the same function, but with the head for the front list incremented
        toReturn->next = merge(front->next, back); 

    }else{
        toReturn = back;
        toReturn->next = merge(front, back->next);
    }



    return toReturn;
}











/*********************************************************************  
 ** Function: Linked_List::sort_descending
 ** Description: Uses selectionSort method to sort list in descending order
 ** Parameters: N/a
 ** Pre-Conditions: linked_list exists
 ** Post-Conditions: List contents reordered, sorted with smallest value at back.
 *********************************************************************/
template<class T>
void Linked_List<T>::sort_descending(){
    selectionSort(&head);
}




/*********************************************************************  
 ** Function: Linked_List::selectionSort
 ** Description: Recursively sorts the list in descending order
 ** Parameters: Node<T>**
 ** Pre-Conditions: linked_list exists
 ** Post-Conditions: Passed in list is sorted in descending order
 *********************************************************************/
template<class T>
void Linked_List<T>::selectionSort(Node<T>** headRef){
    Node<T> *currentHead = *headRef;
    Node<T> *maxNode = currentHead;

    if(currentHead->next == nullptr){//Last node (Base Case)
        return;
    }

    T maxValue = currentHead->value;

    while(maxNode != nullptr){ //Finding the maximum value
        if(maxNode->value > maxValue){
            maxValue = maxNode->value;
        }
        maxNode = maxNode->next;
    }



    swap(&currentHead, maxValue); //Swapping the first node with whatever the node with has the max value
    selectionSort(&(currentHead->next)); //Recursively calling function on the unsorted portion of the list

    *headRef = currentHead;
}






/*********************************************************************  
 ** Function: Linked_List::swap
 ** Description: Swaps the head of the passed in linked list with whatver node has the maxValue
 ** Parameters: Node<T>**, int 
 ** Pre-Conditions: linked_list exists
 ** Post-Conditions: The head node of the list has swapped places with the Maximum node
 *********************************************************************/
template<class T>
void Linked_List<T>::swap(Node<T>** headRef, int maxValue){
    Node<T> *currentHead = *headRef; 
    Node<T>* left = currentHead; //The node at the left index
    
    Node<T> *maxNode = currentHead; //The node with the max number
    Node<T> *prevMax = nullptr;


    if(currentHead->value == maxValue){ //If the head has the max value alread, we don't even have to swap
        return;
    }

    while(maxNode != nullptr && maxNode->value != maxValue){
        prevMax = maxNode;
        maxNode = maxNode->next;
    }

    currentHead = maxNode;
    prevMax->next = left;

    Node<T> *temp = left->next;
    left->next = maxNode->next;
    maxNode->next = temp;

    *headRef = maxNode; //Now the maximum node is at the front
}



