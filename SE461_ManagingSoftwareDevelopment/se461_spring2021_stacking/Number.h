// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef NUMBER_H
#define NUMBER_H

#include "StackCommand.h"

class Number : public StackCommand {
    public:
        // Constructor
        Number(int value);
        // Destructor
        virtual ~Number() {}

        /**
        * Calls evaluate which will is defined in derived classes
        */
        // I don't think it really matters. As long as the user can call this function using execute.
        virtual void execute(Stack <int> & stack);
    
    private:
        // Non-Public Default Constructor
        Number() {}
        // Value of this number
        int value_;
};

#endif
