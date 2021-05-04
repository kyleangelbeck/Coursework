// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef STACKCOMMANDFACTORY_H
#define STACKCOMMANDFACTORY_H

#include "AbstractCommandFactory.h"

class StackCommandFactory : public AbstractCommandFactory {
    public:
        // Default Constructor
        StackCommandFactory() {}

        // Destructor
        virtual ~StackCommandFactory() {}

        // Create Number Command
        virtual Number * createNumber(int value);

        // Create Addition Command
        virtual AdditionOperator * createAdditionOperator();

        // Create Subtraction Command
        virtual SubtractionOperator * createSubtractionOperator();

        // Create Multiplication Command
        virtual MultiplicationOperator * createMultiplicationOperator();
        
        // Create Division Command
        virtual DivisionOperator * createDivisionOperator();

        // Create Modulo Command
        virtual ModuloOperator * createModuloOperator();
};

#endif
