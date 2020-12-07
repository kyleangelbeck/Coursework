// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "Insertion.h"

Insertion::Insertion() {}
Insertion::~Insertion() {}

void Insertion::sortArray(int intArray[], int length)
{
    for(int i = 1; i < length; i++) {
        for(int j = i; j > 0; j--) {
            if(intArray[j] > intArray[j - 1]) {
                int temp = intArray[j];
                intArray[j] = intArray[j - 1];
                intArray[j - 1] = temp;
            }
        }
    }
}
