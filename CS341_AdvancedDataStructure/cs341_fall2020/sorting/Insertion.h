// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef INSERTION_H
#define INSERTION_H

#include "Sort.h"

// Header File for Insertion class. 
class Insertion : public Sort
{
    // Public Constructors/Destructors/Member Methods
    public:
		Insertion();
		~Insertion();
        virtual void sortArray(int intArray[], int length);
};

#endif