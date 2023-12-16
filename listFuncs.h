// Name: Qiaochu Zhang
// USC NetID: qzhang40
// CSCI 455 PA5
// Fall 2023


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to *not* put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <string>
  
// This Struct represents a Node in a linked list
struct Node {
   std::string key; //Key of the Node
   int value;  // Value associated with the key

   Node * next; // Pointer to the next Node in the list

// Constructors for Node
   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.




// Function to remove a Node with the given target key from the list
// @param list, pointer to list head
// @param target, key of the Node
bool listRemove(ListType &list, const std::string &target);

// Function to insert a new Node with the given key and value into the list
// @param list, pointer to list head
// @param key, key of the Node
// @param value, value of the Node
bool listInsert(ListType &list, const std::string &key, int value);


// Function to look up a Node with the given key in the list and return its value
// @param list, pointer to list head
// @param key, key of the Node
int* listLookup(ListType list, const std::string &key);

// Function to print all the Nodes (key-value pairs) in the list
// @param list, pointer to list head
void listPrintAll(ListType list);

// Function to calculate the size (number of Nodes) in the list
// @param list, pointer to list head
int listSize(ListType list);



// keep the following line at the end of the file
#endif
