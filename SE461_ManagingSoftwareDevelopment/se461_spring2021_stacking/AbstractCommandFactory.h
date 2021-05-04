// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef ABSTRACTCOMMANDFACTORY_H
#define ABSTRACTCOMMANDFACTORY_H

#include "Number.h"
#include "AdditionOperator.h"
#include "SubtractionOperator.h"
#include "MultiplicationOperator.h"
#include "DivisionOperator.h"
#include "ModuloOperator.h"

class AbstractCommandFactory {
    public:
        // Destructor
        virtual ~AbstractCommandFactory() {}

        // Create Number Command
        virtual Number * createNumber(int value) = 0;

        // Create Addition Command
        virtual AdditionOperator * createAdditionOperator() = 0;

        // Create Subtraction Command
        virtual SubtractionOperator * createSubtractionOperator() = 0;

        // Create Multiplication Command
        virtual MultiplicationOperator * createMultiplicationOperator() = 0;
        
        // Create Division Command
        virtual DivisionOperator * createDivisionOperator() = 0;

        // Create Modulo Command
        virtual ModuloOperator * createModuloOperator() = 0;
    
    protected:
        // Non-Public Default Constructor
        AbstractCommandFactory() {}
};

#endif
