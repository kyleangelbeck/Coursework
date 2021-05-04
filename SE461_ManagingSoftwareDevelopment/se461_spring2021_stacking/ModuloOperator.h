// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef MODULOOPERATOR_H
#define MODULOOPERATOR_H

#include "BinaryOperator.h"

#include <stdexcept>    //std::exception

class ModuloOperator : public BinaryOperator {

    public:
        // Custom Exception Class
        class ModByZeroException : public std::exception {
            public:
                ModByZeroException() : std::exception() {}
        };
        // Constructor
        ModuloOperator() {}
        // Destructor
        virtual ~ModuloOperator() {}

    protected:
        /**
         * Functionality of each binary operator.
         */
        virtual int evaluate(int a, int b);

};

#endif
