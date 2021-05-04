// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef ADDITIONOPERATOR_H
#define ADDITIONOPERATOR_H

#include "BinaryOperator.h"

// Dr. Ryan: Might be easier to maintain the operator precedence here.
// Kyle: Since we need to deal with parentheses when creating the postfix stack, I use a stack of
//       strings to handle the working expression. So, if I wanted to maintain precedence here, 
//       I would need to change that to be a Command stack and have a parentheses command.
//       So ima just keep precedence in the driver :)
class AdditionOperator : public BinaryOperator {
    public:
        // Constructor
        AdditionOperator() {}
        // Destructor
        virtual ~AdditionOperator() {}

    protected:
        /**
         * Functionality of each binary operator.
         */
        virtual int evaluate(int a, int b);

};

#endif
