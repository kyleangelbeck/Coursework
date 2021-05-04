// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

/* My PC command
    mwc-ace -type make && make clean && make && valgrind --log-file=Valgrind.txt ./Composition.exe
*/
/* Thomas command
    mwc.pl -type make && make clean && make && valgrind --log-file=Valgrind.txt ./Composition.exe
*/

#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "Dynamic_Array.h"
#include "Fixed_Array.h"
#include "Stack.h"
#include "Queue.h"

void printTestResult(bool b, std::string s) {
    if(b) {
        std::cout << s << " Test Success" << std::endl;
    } else {
        std::cout << "ERROR: " << s << " Test Failed" << std::endl;
    }
}

//
// main
//
int main (int argc, char * argv []) {
    bool testSuccess;

    // Test Base Array Size=0 Constructor
    testSuccess = true;
    // b1 Should never be bade and thus should not need to be deleted
    try {
        Base_Array<char> * b1 = new Base_Array<char>(0);
        testSuccess = false;
    } catch(std::exception e) {}
    printTestResult(testSuccess, "Base Array Size=0 Constructor");

    // Test Dynamic Array Default Constructor
    testSuccess = true;
    Dynamic_Array<char> * d1 = new Dynamic_Array<char>();
    if(d1->size() != 10 || d1->max_size() != 10) {testSuccess = false;}
    for(char i = 0; i < 10; i ++) {
        if(d1->get(i) != NULL) {testSuccess = false;}
    }
    printTestResult(testSuccess, "Dynamic Default Constructor");
    delete d1;

    // Test Dynamic Array Copy Constructor
    testSuccess = true;
    Dynamic_Array<char> * d2 = new Dynamic_Array<char>(5, 'b');
    Dynamic_Array<char> * d3 = new Dynamic_Array<char>(*d2);
    if(d3->size() != 5 || d3->max_size() != 5) {testSuccess = false;}
    for(char i = 0; i < 5; i ++) {
        if(d3->get(i) != 'b') {testSuccess = false;}
    }
    printTestResult(testSuccess, "Dynamic Copy Constructor");
    delete d2;
    delete d3;

    // Test Dynamic Array Assignment Operator
    testSuccess = true;
    Dynamic_Array<char> * d4 = new Dynamic_Array<char>(5, 'c');
    Dynamic_Array<char> * d5 = new Dynamic_Array<char>();
    *d5 = *d4;
    if(d5->size() != 5) {testSuccess = false;}
    for(int i = 0; i < 5; i ++) {
        if(d5->get(i) != 'c') {testSuccess = false;}
    }
    printTestResult(testSuccess, "Dynamic Assignment Operator");
    delete d4;
    delete d5;

    // Test Dynamic Array Resize Method
    testSuccess = true;
    Dynamic_Array<char> * d6 = new Dynamic_Array<char>(5);
    d6->resize(10);
    if(d6->size() != 10 || d6->max_size() != 10) {testSuccess = false;}
    d6->resize(5);
    if(d6->size() != 5 || d6->max_size() != 10) {testSuccess = false;}
    d6->resize(5);
    if(d6->size() != 5 || d6->max_size() != 10) {testSuccess = false;}
    printTestResult(testSuccess, "Dynamic Resize Method");
    delete d6;



    // Test Fixed Array Default Constructor
    testSuccess = true;
    Fixed_Array<char, 10> * f1 = new Fixed_Array<char, 10>();
    if(f1->size() != 10) {testSuccess = false;}
    for(char i = 0; i < 10; i ++) {
        if(f1->get(i) != NULL) {testSuccess = false;}
    }
    printTestResult(testSuccess, "Fixed Default Constructor");
    delete f1;

    // Test Fixed Array Same Size Copy Constructor
    testSuccess = true;
    Fixed_Array<char, 10> * f2 = new Fixed_Array<char, 10>('b');
    Fixed_Array<char, 10> * f3 = new Fixed_Array<char, 10>(*f2);
    if(f3->size() != 10) {testSuccess = false;}
    for(int i = 0; i < 10; i ++) {
        if(f3->get(i) != 'b') {testSuccess = false;}
    }
    printTestResult(testSuccess, "Fixed Same Size Copy Constructor");
    delete f2;
    delete f3;

    // Test Fixed Array Larger Size Copy Constructor
    // Copy Array is larger than new Array
    testSuccess = true;
    Fixed_Array<char, 20> * f4 = new Fixed_Array<char, 20>('b');
    Fixed_Array<char, 10> * f5 = new Fixed_Array<char, 10>(*f4);
    if(f5->size() != 10) {testSuccess = false;}
    for(int i = 0; i < 10; i ++) {
        if(f5->get(i) != 'b') {testSuccess = false;}
    }
    printTestResult(testSuccess, "Fixed Larger Size Copy Constructor");
    delete f4;
    delete f5;

    // Test Fixed Array Smaller Size Copy Constructor
    // Copy Array is smaller than new Array
    testSuccess = true;
    Fixed_Array<char, 10> * f6 = new Fixed_Array<char, 10>('b');
    Fixed_Array<char, 20> * f7 = new Fixed_Array<char, 20>(*f6);
    if(f7->size() != 20) {testSuccess = false;}
    for(int i = 0; i < 10; i ++) {
        if(f7->get(i) != 'b') {testSuccess = false;}
    }
    for(int i = 10; i < 20; i ++) {
        if(f7->get(i) != NULL) {testSuccess = false;}
    }
    printTestResult(testSuccess, "Fixed Smaller Size Copy Constructor");
    delete f6;
    delete f7;

    // Test Fixed Array Larger Assignment Operator
    // Copy Array is larger than new Array
    testSuccess = true;
    Fixed_Array<char, 20> * f8 = new Fixed_Array<char, 20>('c');
    Fixed_Array<char, 10> * f9 = new Fixed_Array<char, 10>();
    *f9 = *f8;
    if(f9->size() != 10) {testSuccess = false;}
    for(int i = 0; i < 10; i ++) {
        if(f9->get(i) != 'c') {testSuccess = false;}
    }
    printTestResult(testSuccess, "Fixed Larger Size Assignment Operator");
    delete f8;
    delete f9;

    // Test Fixed Array Smaller Assignment Operator
    // Copy Array is smaller than new Array
    testSuccess = true;
    Fixed_Array<char, 10> * f10 = new Fixed_Array<char, 10>('b');
    Fixed_Array<char, 20> * f11 = new Fixed_Array<char, 20>();
    *f11 = *f10;
    if(f11->size() != 20) {testSuccess = false;}
    for(int i = 0; i < 10; i ++) {
        if(f11->get(i) != 'b') {testSuccess = false;}
    }
    for(int i = 10; i < 20; i ++) {
        if(f11->get(i) != NULL) {testSuccess = false;}
    }
    printTestResult(testSuccess, "Fixed Smaller Size Assignment Operator");
    delete f10;
    delete f11;
    
    // Test Stack Default Constructor
    testSuccess = true;
    Stack<char> * s1 = new Stack<char>();
    if(s1->size() != 0) {testSuccess = false;}
    // If no error is thrown, test is unsuccessful
    try {
        s1->pop();
        testSuccess = false;
    } catch(std::exception e) {}
    printTestResult(testSuccess, "Stack Default Constructor");
    delete s1;

    // Test Stack Copy Constructor
    testSuccess = true;
    Stack<char> * s2 = new Stack<char>();
    s2->push('s');
    Stack<char> * s3 = new Stack<char>(*(s2));
    if(s3->size() != 1) {testSuccess = false;}
    if(s3->top() != 's') {testSuccess = false;}
    s3->pop();
    // If no error is thrown, test is unsuccessful
    try {
        s3->pop();
        testSuccess = false;
    } catch(std::exception e) {}
    printTestResult(testSuccess, "Stack Copy Constructor");
    delete s2;
    delete s3;

    // Test Stack Assignment Operator
    testSuccess = true;
    Stack<char> * s4 = new Stack<char>();
    s4->push('s');
    Stack<char> * s5 = new Stack<char>();
    *s5=*s4;
    if(s5->size() != 1) {testSuccess = false;}
    if(s5->top() != 's') {testSuccess = false;}
    s5->pop();
    // If no error is thrown, test is unsuccessful
    try {
        s5->pop();
        testSuccess = false;
    } catch(std::exception e) {}
    printTestResult(testSuccess, "Stack Assignment Operator");
    delete s4;
    delete s5;

    // Test Stack Clear Method
    testSuccess = true;
    Stack<char> * s6 = new Stack<char>();
    for(int i = 0; i < 5; i++) {
        s6->push('s');
    }
    s6->clear();
    if(s6->size() != 0) {testSuccess = false;}
    // If no error is thrown, test is unsuccessful
    try {
        s6->top();
        testSuccess = false;
    } catch(std::exception e) {}
    printTestResult(testSuccess, "Stack Clear Method");
    delete s6;

    // Test Enqueue/Dequeue Functionality
    Stack<int> * s7 = new Stack<int>();
    for(int i = -3; i < 17; i++) { s7->push(i); }
    if(s7->top() != 16) {testSuccess = false;}
    for(int i = 0; i < 5; i++) { s7->pop(); }
    if(s7->top() != 11) {testSuccess = false;}
    for(int i = 0; i < 10; i++) { s7->pop(); }
    if(s7->top() != 1) {testSuccess = false;}
    printTestResult(testSuccess, "Push/Pop Functionality");
    delete s7;

    // Test Queue Default Constructor
    testSuccess = true;
    Queue<char> * q1 = new Queue<char>();
    if(s1->size() != 0) {testSuccess = false;}
    // If no error is thrown, test is unsuccessful
    try {
        q1->dequeue();
        testSuccess = false;
    } catch(std::exception e) {}
    printTestResult(testSuccess, "Queue Default Constructor");
    delete q1;

    // Test Queue Copy Constructor
    testSuccess = true;
    Queue<char> * q2 = new Queue<char>();
    q2->enqueue('s');
    Queue<char> * q3 = new Queue<char>(*(q2));
    if(q3->size() != 1) {testSuccess = false;}
    if(q3->dequeue() != 's') {testSuccess = false;}
    // If no error is thrown, test is unsuccessful
    try {
        q3->dequeue();
        testSuccess = false;
    } catch(std::exception e) {}
    printTestResult(testSuccess, "Queue Copy Constructor");
    delete q2;
    delete q3;

    // Test Queue Assignment Operator
    testSuccess = true;
    Queue<char> * q4 = new Queue<char>();
    q4->enqueue('s');
    Queue<char> * q5 = new Queue<char>();
    *q5=*q4;
    if(q5->size() != 1) {testSuccess = false;}
    if(q5->dequeue() != 's') {testSuccess = false;}
    // If no error is thrown, test is unsuccessful
    try {
        q5->dequeue();
        testSuccess = false;
    } catch(std::exception e) {}
    printTestResult(testSuccess, "Queue Assignment Operator");
    delete q4;
    delete q5;

    // Test Queue Clear Method
    testSuccess = true;
    Queue<char> * q6 = new Queue<char>();
    for(int i = 0; i < 5; i++) {
        q6->enqueue('s');
    }
    q6->clear();
    if(q6->size() != 0) {testSuccess = false;}
    // If no error is thrown, test is unsuccessful
    try {
        q6->dequeue();
        testSuccess = false;
    } catch(std::exception e) {}
    printTestResult(testSuccess, "Queue Clear Method");
    delete q6;

    // Test Enqueue/Dequeue Functionality
    Queue<int> * q7 = new Queue<int>();
    for(int i = -3; i < 17; i++) { q7->enqueue(i); }
    if(q7->dequeue() != -3) {testSuccess = false;}
    for(int i = 0; i < 5; i++) { q7->dequeue(); }
    if(q7->dequeue() != 3) {testSuccess = false;}
    for(int i = 0; i < 10; i++) { q7->dequeue(); }
    if(q7->dequeue() != 14) {testSuccess = false;}
    printTestResult(testSuccess, "Enqueue/Dequeue Functionality");
    delete q7;

    return 0;
}
