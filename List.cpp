/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 *                    Based on the Hashing strategy and the open addressing 
 *                    collision resolution strategy called linear probing hashing.             
 * Class Invariant: Data collection with the following characteristics:
 *                  - Each element is unique (no duplicates).
 *
 * Author: AL + SD 
 * Date: Last modified: Nov. 2022
 */

 #include "List.h"
 #include <iostream>

 using std::cout;
 using std::endl;

 // Constructor
 List::List(unsigned int (*hFcn)(string));

 // Destructor
 List::~List(){
    if(hashTable != nullptr){
        delete [] hashTable;
        hashTable = nullptr;
    }
 }

 // Description: Return the total element count currently stored in List.
 // Postconditions: List remains unchanged
 List::unsigned int getElementCount()const{
    return elementCount;
 }
 
 // Description: insert an element.
 // Preconditions: newElement must not aready be in the list
 // Postconditions: newElement inserted and elementCount has been incremented
 List::void insert(Member & newElement){
    if(elementCount == 0){
        hashTable = new Memeber[CAPACITY];
    }
    if(hashTable == nullptr){
        return;
    }
    for(int i = 0; i < CAPACITY; i++){
        hashTable[i] = "";
    }
    // resize if full;

    unsigned int hashIndex = (*hashFcn)(newElement);

    hashTable[hashIndex] = newElement;

    elementCount++;

    return;
 }
 
 // Description: Returns a pointer to the target element if found.
 // Postconditions: List remains unchanged
 List::Member* search(Member & target){
    Member* result = nullptr
    bool found = true;
    for(int i = 0; i < getElementCount() && !found; i++){
        if(hashTable[i] == target){
            result =  &hashTable[i];
            found = true;
        }
    }
    return result;
 }
 
 // Description: Print all elements stored in the List (unsorted)
 // Postconditions: List remains unchanged
 List::void printList() const{
    for(int i = 0; i < getElementCount(); i++){
        cout << hashTable[i];
    }
    return;
 }
