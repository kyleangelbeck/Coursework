// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#ifndef HASHTABLEARRAY_H
#define HASHTABLEARRAY_H

#include "HashTable.h"
#include "HashEntry.h"

enum Probe {
    LINEAR,
    QUADRATIC
};

class HashTableArray : public HashTable {
    // Private-facing attributes
    private:
        // This stores the entry
        HashEntry * entry_;
        // This stores array size
        int size_;
        // This stores probing type
        Probe probe_;

        // Inaccessible Empty Constructor
        HashTableArray();

    // Public-facing methods
    public:
        // Constructor
        HashTableArray(int size, Probe probe);
        // Destructor
        virtual ~HashTableArray();

        /**
         * Getter of entry
         * @return HashEntry
         */
        HashEntry * getEntry();

        /**
         * Setter of entry
         * @param HashEntry
         */
        void setEntry(HashEntry *  entry);

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
