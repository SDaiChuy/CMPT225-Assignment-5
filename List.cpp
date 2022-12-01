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
 #include "Member.h"
 #include <iostream>

 using std::cout;
 using std::endl;

 // Constructor
 List::List(unsigned int (*hFcn)(string)): hashFcn(hFcn){} // save the hash function address

 // Destructor
 List::~List(){
    if(hashTable != nullptr){
        delete [] hashTable;
        hashTable = nullptr;
    }
    if(collision != nullptr){
        delete [] collision;
        collision = nullptr;
    }
 }

 // Description: Return the total element count currently stored in List.
 // Postconditions: List remains unchanged
 unsigned int List::getElementCount()const{
    return elementCount;
 }
 
 // Description: insert an element.
 // Preconditions: newElement must not aready be in the list
 // Postconditions: newElement inserted and elementCount has been incremented
 void List:: insert(Member & newElement){
    if(elementCount == 0){
        hashTable = new Member[CAPACITY];
        if(hashTable == nullptr){
            return;
        }
        collision = new unsigned int[CAPACITY];
        if(collision == nullptr){
            return;
        }
        for(int i = 0; i < CAPACITY; i++){
            hashTable[i] = "";
            collision[i] = 0;
        }
    }

    // resize if full
    if(collision == CAPACITY){
        CAPACITY *= 2;
        unsigned int* temp = new unsigned int[CAPACITY];
        for(int i = 0; i < elementCount; i++ ){
            temp[i] = collision[i];
        }
        collision = temp;
    }

    if(hashTable == CAPACITY){
        CAPACITY *= 2;
        Memeber* temp = new Member[CAPACITY];
        for(int i = 0; i < elementCount; i ++){
            temp[i] = hashtable[i];
        }
        hashTable = temp;
    }

    // call the hash function using indexing key to get hash index
    unsigned int hashIndex = (*hashFcn)(newElement);

    // insert newElement into hashtable at hashindex
    hashTable[hashIndex] = newElement;

    // increment the collision counter at hash index
    collision[hashIndex]++;

    // increment the elementCount 
    elementCount++;

    return;
 }
 
 // Description: Returns a pointer to the target element if found.
 // Postconditions: List remains unchanged
 Member* List:: search(Member & target){
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
 void List:: printList() const{
    for(int i = 0; i < getElementCount(); i++){
        cout << hashTable[i];
    }
    return;
 }
