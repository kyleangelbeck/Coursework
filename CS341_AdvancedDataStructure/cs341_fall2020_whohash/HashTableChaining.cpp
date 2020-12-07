// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#include "HashTableChaining.h"
#include <iostream>

HashTableChaining::HashTableChaining(): size_(0), entry_(nullptr) {}
HashTableChaining::HashTableChaining(int size): size_(size), entry_(new DoubleLinkedList[size]) {}
HashTableChaining::~HashTableChaining() { delete[] entry_; }

DoubleLinkedList * HashTableChaining::getEntry() { return entry_; }
void HashTableChaining::setEntry(DoubleLinkedList * entry) {entry_ = entry;}

int HashTableChaining::getSize() {return size_;}
void HashTableChaining::setSize(int size) {size_ = size;}

void HashTableChaining::insertEntry(int key, int value) {
    int hashVal = key % size_;
    (entry_ + hashVal)->insertNode(key, value);
}

int HashTableChaining::searchEntry(int key) {
    int hashVal = key % size_;
    return (entry_ + hashVal) -> search(key);
}

void HashTableChaining::removeEntry(int key) {
    int hashVal = key % size_;
    (entry_ + hashVal) -> remove(key);
}

void HashTableChaining::printTable() {
    std::cout << "***********************************" << std::endl;
    for(int i=0; i < size_; i++) {
        std::cout << "[" << i << "]: ";
        (entry_ + i) -> printList();
        std::cout << std::endl;
    }
    std::cout << "***********************************" << std::endl;
}
