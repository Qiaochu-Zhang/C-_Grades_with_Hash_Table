// Name: Qiaochu Zhang
// USC NetID: qzhang40
// CSCI 455 PA5
// Fall 2023

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

using namespace std;

void processCommands(Table * grades); // Process differnet commands using while loop for different cases
void printHelp(); // Print helper command to indicate what command can be used


int main(int argc, char * argv[]) {


   Table * grades;  // Table is dynamically allocated below, so we can call
                     // different constructors depending on input from the user.
   
   // optionally gets the hash table size from the command line
   if (argc > 1) {
      int hashSize = atoi(argv[1]);  // atoi converts c-string to int
      
      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }

      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }


   grades->hashStats(cout); // print hashStats

// process different commands below
   processCommands(grades);
   delete grades;
   return 0;
}

/* 
@param grades is the head of table
This function process different commands
*/
void processCommands(Table * grades){
   string command;
   string name;   
   int score;
   cout << "cmd> ";
   int * ptr; // pointer to the score
   while(cin >> command){
      if(command == "insert"){
         cin >> name >> score;
         if((grades -> lookup(name))== nullptr){
            grades -> insert(name, score);
         }
         else{
            cout << name << " has already existed, so cannot insert.\n";
         }
         cout << "cmd> ";
      }
      else if (command == "change"){
         cin >> name >> score;
         if((grades -> lookup(name))!= nullptr){
            grades -> remove(name);
            grades -> insert(name, score);
         }
         else{
            cout << name << " does not exist so the score cannot change.\n";
         }
         cout << "cmd> ";
      }
      else if (command == "lookup"){
         cin >> name;
         ptr = grades -> lookup(name);
         if(ptr != nullptr){
            cout << name << ": " << *ptr << endl;
         }
         else{
            cout << name << " is not in the table so he/she cannnot be found.\n";
         }
         cout << "cmd> ";
      }
      else if (command == "remove"){
         cin >> name;
         ptr = grades -> lookup(name);
         if(ptr != nullptr){
            grades -> remove(name);
         }
         else{
            cout << name << " is not in the table so he/she cannot be removed.\n";
         }
         cout << "cmd> ";
      }
      else if (command == "print"){
         grades -> printAll();
         cout << "cmd> ";
      }
      else if (command == "size"){
         cout << grades -> numEntries() <<endl;
         cout << "cmd> ";
      }
      else if (command == "stats"){
         grades->hashStats(cout);
         cout << "cmd> ";
      }
      else if (command == "help") {
         printHelp();
         cout << "cmd> ";
      }
      else if (command == "quit") {
      break; 
      }
      else{
         cout << "ERROR: invalid command." << endl;
         printHelp();
         cout << "cmd> ";
      }
   }
}

// This function print all commands and their use
void printHelp(){
   cout << "Command list:" << endl;
   cout << "insert name score - insert a student's name and score." << endl;
   cout << "change name newscore - change a student's score." << endl;
   cout << "lookup name - lookup a student's score." << endl;
   cout << "remove name - remove a student's record." << endl;
   cout << "print - print out all names and scores in the table." << endl;
   cout << "size - print out the number of entries in the table." << endl;
   cout << "stats - print out statistics about the hash table." << endl;
   cout << "help - print out a brief command summary (this message)." << endl;
   cout << "quit - exit the program." << endl;
}
