// Name: Qiaochu Zhang
// USC NetID: qzhang40
// CSCI 455 PA5
// Fall 2023

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"

int main() {
    ListType list = nullptr;

    // Test listInsert
    listInsert(list, "Alice", 90);
    listInsert(list, "Bob", 85);
    listInsert(list, "Charlie", 75);

    // Test listPrintAll
    listPrintAll(list);

    // Test listLookup
    int* scorePtr = listLookup(list, "Bob");
    if (scorePtr != nullptr) {
        cout << "Bob's score: " << *scorePtr << endl;
    } else {
        cout << "Bob not found in the list." << endl;
    }

    // Test listRemove
    bool removed = listRemove(list, "Alice");
    if (removed) {
        cout << "Alice removed successfully." << endl;
    } else {
        cout << "Alice not found in the list." << endl;
    }

    // Test listSize
    int size = listSize(list);
    cout << "Size of the list: " << size << endl;

    // Test listPrintAll after removal
    listPrintAll(list);

    return 0;
}
