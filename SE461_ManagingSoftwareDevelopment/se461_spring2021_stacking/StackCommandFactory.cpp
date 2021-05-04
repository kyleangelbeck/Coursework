// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "StackCommandFactory.h"

Number * StackCommandFactory::createNumber(int value) {
    return new Number(value);
}

AdditionOperator * StackCommandFactory::createAdditionOperator() {
    return new AdditionOperator();
}

SubtractionOperator * StackCommandFactory::createSubtractionOperator() {
    return new SubtractionOperator();
}

MultiplicationOperator * StackCommandFactory::createMultiplicationOperator() {
    return new MultiplicationOperator();
}

DivisionOperator * StackCommandFactory::createDivisionOperator() {
    return new DivisionOperator();
}

ModuloOperator * StackCommandFactory::createModuloOperator() {
    return new ModuloOperator();
}
