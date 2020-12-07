// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "Bubble.h"

Bubble::Bubble() {}
Bubble::~Bubble() {}

void Bubble::sortArray(int intArray[], int length)
{
    for(int i = 0; i < length - 1; i++) {
        for(int j = 0; j < length - 1 - i; j++) {
            if(intArray[j] < intArray[j + 1]) {
                int temp = intArray[j];
                intArray[j] = intArray[j + 1];
                intArray[j + 1] = temp;
            }
        }
    }
}
