// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

#include "DoubleLinkedList.h"
#include "HashTable.h"

class HashTableChaining : public HashTable {
    // Private-facing attributes
    private:
        // This stores the entry
        DoubleLinkedList * entry_;
        // This stores array size
        int size_;
        // Inaccessible Empty Constructor
        HashTableChaining();

    // Public-facing methods
    public:
        // Constructor
        HashTableChaining(int size);
        // Destructor
        virtual ~HashTableChaining();

        /**
         * Getter of entry
         * @return DoubleLinkedList
         */
        DoubleLinkedList * getEntry();

        /**
         * Setter of entry
         * @param DoubleLinkedList
         */
        void setEntry(DoubleLinkedList * entry);

        /**
         * Getter of size
         * @return int
         */
        int getSize();

        /**
         * Setter of size
         * @param int
         */
        void setSize(int size);

        /**
         * Insert an entry into the table
         * @param int, int
         */
        void insertEntry(int key, int value);

        /**
         * Search the table for value at key
         * @param int
         * @return int
         */
        int searchEntry(int key);

        /**
         * Remove the entry with this key
         * @param int
         */
        void removeEntry(int key);

        /**
         * Print the table
         * @param int
         */
        void printTable();
};

#endif
