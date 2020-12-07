// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Node.h"

class Dictionary {
    // Private attributes
    private:
        // This will hold number entry
        Node id_;
        // This will hold the frequency value
        Node data_;

        // Unaccessible empty constructor
        Dictionary();

    // Public methods
    public:
        // Constructor
        Dictionary(int id, int data);
        // Destructor
        ~Dictionary();

        /**
         * Getter of Dictionary's id
         * @return int
         */
        int getId();

        /**
         * Setter of Dictionary's id
         * @param int
         */
        void setId(int id);

        /**
         * Getter of Dictionary's data
         * @return int
         */
        int getData();

        /**
         * Setter of Dictionary's data
         * @param int
         */
        void setData(int data);

};

#endif
