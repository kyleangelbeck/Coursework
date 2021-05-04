// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef DIVISIONOPERATOR_H
#define DIVISIONOPERATOR_H

#include "BinaryOperator.h"

#include <stdexcept>    //std::exception
#include <iostream>     //std::cout, std::endl

class DivisionOperator : public BinaryOperator {

    public:
        // Custom Exception Class
        class DivByZeroException : public std::exception {
            public:
                DivByZeroException() : std::exception() {}
        };

        // Constructor
        DivisionOperator() {}
        // Destructor
        virtual ~DivisionOperator() {}

    protected:
        /**
         * Functionality of each binary operator.
         */
        virtual int evaluate(int a, int b);

};

#endif
