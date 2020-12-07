// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef BUBBLE_H
#define BUBBLE_H

#include "Sort.h"

// Header File for Player class. 
class Bubble : public Sort
{
    // Public Constructors/Destructors/Member Methods
    public:
		Bubble();
	    ~Bubble();
        virtual void sortArray(int intArray[], int length);
};

#endif