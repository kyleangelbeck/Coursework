// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef BINARYOPERATOR_H
#define BINARYOPERATOR_H

#include "StackCommand.h"

class BinaryOperator : public StackCommand {
    public:
        // Destructor
        virtual ~BinaryOperator() {}

        /**
        * Calls evaluate which is defined in each BinaryOperator
        */
        virtual void execute(Stack <int> & stack);

    protected:
        // Non-Public Default Constructor
        BinaryOperator() {}

        /**
         * Functionality of each binary operator.
         */
        virtual int evaluate(int a, int b) = 0;

};

#endif
