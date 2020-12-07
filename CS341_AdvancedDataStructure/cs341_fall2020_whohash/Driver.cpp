// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#include "HashTableArray.h"
#include "HashTableChaining.h"
#include <iostream>
#include <fstream>

void probing(Probe probeType);
void chaining();

int main() {

    int userSelection;
    bool done = false;

    while (!done){
        std::cout << "Welcome to Blue IV's Can of Who Hash!" << std::endl;
        std::cout << "1) Linear Probing" << std::endl;
        std::cout << "2) Quadratic Probing" << std::endl;
        std::cout << "3) Separate Chaining" << std::endl;
        std::cout << "4) Quit Program" << std::endl << std::endl;
        std::cout << "Please enter your choice: ";
        std::cin >> userSelection;

        switch(userSelection){

            case 1 : // linear probing
                probing(LINEAR);
                break;

            case 2 : // quadratic probing
                probing(QUADRATIC);
                break;

            case 3 : // separate chaining
                chaining();
                break;

            case 4 :
                std::cout << "Thank you for using Blue IV's program - Goodbye!" << std::endl;
                done = true;
                break;

            default :
                std::cout << "Invalid selection, please try again" << std::endl;
                break;
        }
    }
    return 0;
}

void probing(Probe probeType) {
    int size;

    std::cout << "Enter the size of the hash table: ";
    std::cin >> size;
    
    HashTableArray * table = new HashTableArray(size, probeType);

    // Read in file from duplicates.txt
    std::ifstream readDataIn;
    readDataIn.open("duplicates.txt");

    // exit if file could not be read
    if (!readDataIn) {
        std::cout << "Read in of duplicates.txt failed." << std::endl;
        return;
    }

    // write read-in integers to linked nodes in doubly linked list
    int x;
    int y;
    while (readDataIn >> x) {
        readDataIn >> y;
        table->insertEntry(x, y);
    }

    readDataIn.close();
    table->printTable();

    // Run program
    int userSelection;
    bool done = false;
    while(!done) {
        std::cout << "1) Search For Entry" << std::endl;
        std::cout << "2) Remove Entry" << std::endl;
        std::cout << "3) Print Hash Table" << std::endl;
        std::cout << "4) Return to Main Menu" << std::endl << std::endl;
        std::cout << "Please enter your choice: ";
        std::cin >> userSelection;
        std::cout << std::endl;

        // Need brackets to declare variables in case
        switch(userSelection){

            case 1 : // Search
            {
                std::cout << "Search (Please enter a Key): ";
                int key;
                std::cin >> key;
                std::cout << std::endl;

                int value = table->searchEntry(key);
                if(value == -1) {
                    std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl << std::endl;
                } else {
                    std::cout << "Key: " << key << " Value: " << value << std::endl << std::endl;
                }
                break;
            }

            case 2 : // Remove
            {
                std::cout << "Remove (Please enter a Key): ";
                int key;
                std::cin >> key;
                std::cout << std::endl;

                table->removeEntry(key);
                break;
            }

            case 3 : // Print
                table->printTable();
                std::cout << std::endl;
                break;

            case 4 :
                done = true;
                break;

            default :
                std::cout << "Invalid selection, please try again" << std::endl;
                break;
        }
    }
    delete table;
}

void chaining(){
    int size;

    std::cout << "Enter the size of the hash table: ";
    std::cin >> size;

    HashTableChaining * table = new HashTableChaining(size);

    // Read in file from duplicates.txt
    std::ifstream readDataIn;
    readDataIn.open("duplicates.txt");

    // exit if file could not be read
    if (!readDataIn) {
        std::cout << "Read in of duplicates.txt failed." << std::endl;
        return;
    }

    // write read-in integers to linked nodes in doubly linked list
    int x;
    int y;
    while (readDataIn >> x) {
        readDataIn >> y;
        table->insertEntry(x, y);
    }

    readDataIn.close();
    table->printTable();

    // Run program
    int userSelection;
    bool done = false;
    while(!done) {
        std::cout << "1) Search For Entry" << std::endl;
        std::cout << "2) Remove Entry" << std::endl;
        std::cout << "3) Print Hash Table" << std::endl;
        std::cout << "4) Return to Main Menu" << std::endl << std::endl;
        std::cout << "Please enter your choice: ";
        std::cin >> userSelection;
        std::cout << std::endl;

        // Need brackets to declare variables in case
        switch(userSelection){

            case 1 : // Search
            {
                std::cout << "Search (Please enter a Key): ";
                int key;
                std::cin >> key;
                std::cout << std::endl;

                int value = table->searchEntry(key);
                if(value == -1) {
                    std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl << std::endl;
                } else {
                    std::cout << "Key: " << key << " Value: " << value << std::endl << std::endl;
                }
                break;
            }

            case 2 : // Remove
            {
                std::cout << "Remove (Please enter a Key): ";
                int key;
                std::cin >> key;
                std::cout << std::endl;

                table->removeEntry(key);
                break;
            }

            case 3 : // Print
                table->printTable();
                std::cout << std::endl;
                break;

            case 4 :
                done = true;
                break;

            default :
                std::cout << "Invalid selection, please try again" << std::endl;
                break;
        }
    }
    delete table;
}
