// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef STACKCOMMAND_H
#define STACKCOMMAND_H

#include "Stack.h"

//TODO: Change name of class?
class StackCommand {
    public:

        // Destructor
        virtual ~StackCommand() {}

        /**
        * Execute Derived Command's Functionality
        */
        // FIXME: If we do not use stack as a parameter here, then each one might need a different number of parameters.
        // Probably just easier to use stack.
        virtual void execute(Stack <int> & stack) = 0;

    protected:
        // Non-Public Default Constructor
        StackCommand() {}

};

#endif
