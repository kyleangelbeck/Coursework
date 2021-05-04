// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "BinaryOperator.h"

void BinaryOperator::execute(Stack <int> & stack) {
    // Dr. Ryan: Why not avoid passing the Stack another layer lower and do the work here?
    // Kyle: Done
    int a = stack.top();
    stack.pop();

    int b = stack.top();
    stack.pop();

    stack.push(evaluate(a,b));
}
