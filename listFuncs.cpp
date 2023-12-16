// Name: Qiaochu Zhang
// USC NetID: qzhang40
// CSCI 455 PA5
// Fall 2023


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

// This Struct represents a Node in a linked list
Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}
// Constructors for Node
Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}




//*************************************************************************
// put the function definitions for your list functions below
bool listRemove(ListType &list, const string &target) {
    Node * current = list;  // current pointer to traverse the list
    Node * previous = nullptr;  // pointer previous to current pointer
    while (current != nullptr) {
        if (current->key == target) {
            if (previous == nullptr) {
                list = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

bool listInsert(ListType &list, const string &key, int value) {
    Node * newNode = new Node(key,value);
    if(list == nullptr){
      list = newNode;
      return true;
    }
    if(listLookup(list,key)!= nullptr){
      delete newNode;
      return false;
    }
    newNode -> next = list;
    list = newNode;
    return true;
}

int* listLookup(ListType list, const string &key) {
    while(list != nullptr){
      if(list->key == key){
         return &(list -> value);
      }
      list = list -> next;
    }
    return nullptr;
}

void listPrintAll(ListType list) {
    while(list != nullptr){
      cout << list->key <<" "<<list->value<<endl;
      list = list -> next;
    }
}

int listSize(ListType list) {
    int count = 0;
    while(list != nullptr){
      count ++ ; 
      list = list -> next;
    }
    return count;
}
