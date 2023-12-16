// Name: Qiaochu Zhang
// USC NetID: qzhang40
// CSCI 455 PA5
// Fall 2023

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
   hashSize = HASH_SIZE; // 9973 is DEFAULT_SIZE of hashtable if there is no size given
   data = new ListType[hashSize](); // use ListType array to save the data in different buckets

}


Table::Table(unsigned int hSize) {
   hashSize = hSize; // hash bucket number (hash size)
   data = new ListType[hashSize](); // use ListType array to save the data in different buckets
}


int * Table::lookup(const string &key) {
   unsigned int hashIndex = hashCode(key); // get hash code
   ListType currentNodePtr = data[hashIndex]; // pointer to the possible bucket
   return listLookup(currentNodePtr, key);   
}


bool Table::remove(const string &key) {
   unsigned int hashIndex = hashCode(key); // get hash code
   return listRemove(data[hashIndex], key);  
}


bool Table::insert(const string &key, int value) {
   unsigned int hashIndex = hashCode(key); // get hash code
   return listInsert(data[hashIndex], key, value);
}


int Table::numEntries() const {
   int numEntries = 0;
   for(int i = 0; i<hashSize; i++){
      numEntries += listSize(data[i]);
   }
   return numEntries;
}


void Table::printAll() const {
   for(int i = 0; i<hashSize; i++){
      listPrintAll(data[i]);
   }
}


void Table::hashStats(ostream &out) const {
   int numEntries = 0; // Number of entries
   int numBuckets = hashSize; // Number of buckets
   int longestChain = 0;   // Longest chain length
   int numNonEmptBkts = 0; // Number of non-empty buckets 
   for (int i =0; i< hashSize ; i++){
      ListType chain = data[i]; // Get linkedlist (hash bucket) of index i
      if(chain != nullptr){
         numNonEmptBkts++;
      }
      int chainLength = 0; // initialize length of longest chain
      while (chain != nullptr){
         chain = chain -> next;
         chainLength++;
      }
      if(chainLength > longestChain){
         longestChain = chainLength;
      }
      numEntries += chainLength;
   }
   // output stream
   out << "number of buckets: " << numBuckets << endl;
   out << "number of entries: " << numEntries << endl;
   out << "number of non-empty buckets: " << numNonEmptBkts << endl;
   out << "longest chain: " << longestChain << endl;
}


// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const {

   // Note: calls a std library hash function for string (it uses the good hash
   //   algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashSize;

}


