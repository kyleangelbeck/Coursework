// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#include "HashTableArray.h"
#include <iostream>

HashTableArray::HashTableArray() : size_(0), entry_(nullptr) {}
HashTableArray::HashTableArray(int size, Probe probe): size_(size), entry_(new HashEntry[size]), probe_(probe) {}
HashTableArray::~HashTableArray() { delete[] entry_; }

HashEntry * HashTableArray::getEntry() { return entry_; }
void HashTableArray::setEntry(HashEntry *  entry) {entry_ = entry;}

int HashTableArray::getSize() {return size_;}
void HashTableArray::setSize(int size) {size_ = size;}

void HashTableArray::insertEntry(int key, int value) {
    int initHashVal = key % size_;
    int currentHashVal = initHashVal;
    int i = 0;

    // Keep searching while entry_ is occupied
    while((entry_ + (currentHashVal % size_))->getStatus() == OCCUPIED) {
        if(probe_ == LINEAR) {
            currentHashVal += 1;
        } else {
            currentHashVal = initHashVal + (++i*i);
        }

        // If we have completely looped and not found a free space
        if(currentHashVal == initHashVal) {
            std::cout << "Could not insert " << key << ":" << value << std::endl;
            std::cout << "There are no empty spaces in the hash table." << std::endl;;
            return;
        }
    }

    // Insert key and value at empty space
    (entry_ + (currentHashVal % size_))->setKey(key);
    (entry_ + (currentHashVal % size_))->setValue(value);
    (entry_ + (currentHashVal % size_))->setStatus(OCCUPIED);
}

int HashTableArray::searchEntry(int key) {
    int initHashVal = key % size_;
    int currentHashVal = initHashVal;
    int i = 0;

    // Keep searching until an empty space is found
    while((entry_ + (currentHashVal % size_))->getStatus() != EMPTY) {
        // key has been found
        if((entry_ + (currentHashVal % size_))->getKey() == key) {
            return (entry_ + (currentHashVal % size_))->getValue();
        }

        // Key not found, keep searching
        if(probe_ == LINEAR) {
            currentHashVal += 1;
        } else {
            currentHashVal = initHashVal + (++i*i);
        }

        // We have completely looped and have not found the key
        if(currentHashVal == initHashVal) {
            break;
        }
    }

    // Return -1 indicating that key was not found
    return -1;
}

void HashTableArray::removeEntry(int key) {
    int initHashVal = key % size_;
    int currentHashVal = initHashVal;
    int i = 0;

    // Keep searching until an empty space is found
    while((entry_ + (currentHashVal % size_))->getStatus() != EMPTY) {
        // key has been found
        if((entry_ + (currentHashVal % size_))->getKey() == key) {
            (entry_ + (currentHashVal % size_))->setStatus(REMOVED);
            (entry_ + (currentHashVal % size_))->setKey(-1);
            (entry_ + (currentHashVal % size_))->setValue(-1);
            std::cout << "Key " << key << " removed." << std::endl  << std::endl;
            return;
        }

        // Key not found, keep searching
        if(probe_ == LINEAR) {
            currentHashVal += 1;
        } else {
            currentHashVal = initHashVal + (++i*i);
        }

        // We have completely looped and have not found the key
        if(currentHashVal == initHashVal) {
            break;
        }
    }

    std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl << std::endl;
    return;
}

void HashTableArray::printTable() {
    std::cout << "***********************************" << std::endl;
    for(int i=0; i < size_; i++) {
        std::cout << "[" << i << "]: ";
        if((entry_ + i)->getStatus() == OCCUPIED) {
            std::cout << (entry_ + i)->getKey() << std::endl;
        } else {
            std::cout << std::endl;
        }
    }
    std::cout << "***********************************" << std::endl;
}
