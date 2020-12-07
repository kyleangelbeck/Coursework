// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#ifndef HASHENTRY_H
#define HASHENTRY_H

#include "Node.h"

enum Status {
    EMPTY,
    OCCUPIED,
    REMOVED
};

class HashEntry {
    // Private attributes
    private:
        // This will hold unique key of entry
        int key_;
        // This will hold the value of entry
        int value_;
        // This will hold status enum defined above
        Status status_;

    // Public methods
    public:
        // So it can be access through derived classes
        HashEntry();
        // Constructor
        HashEntry(int key, int value);
        // Destructor
        virtual ~HashEntry();

        /**
         * Getter of HashEntry's key
         * @return int
         */
        int getKey();

        /**
         * Setter of HashEntry's key
         * @param int
         */
        void setKey(int key);

        /**
         * Getter of HashEntry's value
         * @return int
         */
        int getValue();

        /**
         * Setter of HashEntry's value
         * @param int
         */
        void setValue(int value);

        /**
         * Getter of HashEntry's status
         * @return Status
         */
        Status getStatus();

        /**
         * Setter of HashEntry's status
         * @param Status
         */
        void setStatus(Status status);
};

#endif
