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
template <class T>
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
        virtual void insert(T element) = 0;

        // Prints the list
        virtual void printList() = 0;

    protected:
        // Because this is a Pure Virtual (Abstract) Class we want to
        // prevent someone from trying to use it directly.

        // Constructor
        List() {}
};

#endif
