// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "Number.h"

Number::Number(int value) : value_(value) {}

void Number::execute(Stack <int> & stack) {
    stack.push(value_);
}
