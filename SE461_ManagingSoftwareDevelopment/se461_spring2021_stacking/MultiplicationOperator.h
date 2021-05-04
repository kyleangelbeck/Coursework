// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef MULTIPLICATIONOPERATOR_H
#define MULTIPLICATIONOPERATOR_H

#include "BinaryOperator.h"

class MultiplicationOperator : public BinaryOperator {
    public:
        // Constructor
        MultiplicationOperator() {}
        // Destructor
        virtual ~MultiplicationOperator() {}

    protected:
        /**
         * Functionality of each binary operator.
         */
        virtual int evaluate(int a, int b);

};

#endif
