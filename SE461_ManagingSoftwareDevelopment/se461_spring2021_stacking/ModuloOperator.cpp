// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "ModuloOperator.h"

// Dr. Ryan: Let's avoid passing the Stack down to this level.
// Kyle: Done
int ModuloOperator::evaluate(int a, int b) {
    if(a == 0) {
        throw ModByZeroException();
    }

    return b % a;
}
