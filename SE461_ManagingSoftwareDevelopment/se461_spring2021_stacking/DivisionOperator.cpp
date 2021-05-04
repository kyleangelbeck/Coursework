// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "DivisionOperator.h"

// Dr. Ryan: Let's avoid passing the Stack down to this level.
// Kyle: Done
int DivisionOperator::evaluate(int a, int b) {
    if(a == 0) {
        throw DivByZeroException();
    }
    // Let user know when division is truncating
    if((double)(b/a) != (double)b / (double)a) {
        std::cout << "A division operator resulted in a decimal, which in turn resulted in truncation." << std::endl;
    }
    return b / a;
}
