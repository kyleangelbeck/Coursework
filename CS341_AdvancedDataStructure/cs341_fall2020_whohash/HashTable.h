// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
    protected:
        // Because this is a Pure Virtual (Abstract) Class we want to
        // prevent someone from trying to use it directly.
        // Constructor
        HashTable() {}

    // Public-facing methods
    public:
        // Destructor
        virtual ~HashTable() {}

        /**
         * Insert an entry into the table
         * @param int, int
         */
        virtual void insertEntry(int key, int value) = 0;

        /**
         * Search the table for value at key
         * @param int
         * @return int
         */
        virtual int searchEntry(int key) = 0;

        /**
         * Remove the entry with this key
         * @param int
         */
        virtual void removeEntry(int key) = 0;

        /**
         * Print the table
         * @param int
         */
        virtual void printTable() = 0;
};

#endif
