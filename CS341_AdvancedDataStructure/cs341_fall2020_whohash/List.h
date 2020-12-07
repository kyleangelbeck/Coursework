// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#ifndef LIST_H
#define LIST_H

// Header File for List class. 
class List
{
    // Public Constructors/Destructors/Member Methods
    public:       
        // Destructor
        virtual ~List() {}

        /**
        * Check to see if the List is empty.
        *
        * @return T/F
        */
        virtual bool isEmpty() = 0;

        /**
        * Gets the length of the List.
        *
        * @return Integer
        */
        virtual int getLength() = 0;
        
        /**
        * Assignment operation
        *
        * @param[in] element Data Element (Integer)
        */
        virtual void insert(int key, int value) = 0;

        /**
        * Deletion operation
        *
        * @param[in] key of hash to be removed
        */
        virtual void remove(int key) = 0;

        /**
         * Search the list for a given key
         * @param int
         * @return int
         */
        virtual int search(int key) = 0;

        /**
         * Prints List
         */
        virtual void printList() = 0;

    protected:
        // Because this is a Pure Virtual (Abstract) Class we want to
        // prevent someone from trying to use it directly.

        // Constructor
        List() {}
};

#endif
