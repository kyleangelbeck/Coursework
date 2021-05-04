// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

/* My PC command
    mwc-ace -type make && make clean && make && valgrind --log-file=Valgrind.txt ./A1.exe
*/
/* Thomas command
    mwc.pl -type make && make clean && make && valgrind --log-file=Valgrind.txt ./A1.exe
*/

#include "Array.h"
#include <iostream>
#include <string>

void printTestResult(bool b, std::string s) {
    if(b) {
        std::cout << s << " Test Success" << std::endl;
    } else {
        std::cout << "ERROR: " << s << " Test Failed" << std::endl;
    }
}

int main() {
    bool testSuccess;

    // Test Default Constructor
    testSuccess = true;
    Array * a1 = new Array();
    if(a1->size() != 10 || a1->max_size() != 10) {testSuccess = false;}
    for(int i = 0; i < 10; i ++) {
        if(a1->get(i) != NULL) {testSuccess = false;}
    }
    printTestResult(testSuccess, "Default Constructor");
    delete a1;

    // Test Constructor with Size
    testSuccess = true;
    Array * a2 = new Array(5);
    if(a2->size() != 5 || a2->max_size() != 5) {testSuccess = false;}
    for(int i = 0; i < 5; i ++) {
        if(a2->get(i) != NULL) {testSuccess = false;}
    }
    printTestResult(testSuccess, "Size Constructor");
    delete a2;

    // Test Fill Constructor
    testSuccess = true;
    Array * a3 = new Array(5, 'a');
    if(a3->size() != 5 || a3->max_size() != 5) {testSuccess = false;}
    for(int i = 0; i < 5; i ++) {
        if(a3->get(i) != 'a') {testSuccess = false;}
    }
    printTestResult(testSuccess, "Fill Constructor");
    delete a3;

    // Test Copy Constructor
    testSuccess = true;
    Array * a4 = new Array(5, 'b');
    Array * a5 = new Array(*a4);
    if(a5->size() != 5 || a5->max_size() != 5) {testSuccess = false;}
    for(int i = 0; i < 5; i ++) {
        if(a5->get(i) != 'b') {testSuccess = false;}
    }
    printTestResult(testSuccess, "Copy Constructor");
    delete a4;
    delete a5;

    // Test Assignment Operator
    testSuccess = true;
    Array * a6 = new Array(5, 'c');
    Array * a7 = new Array();
    *a7 = *a6;
    if(a7->size() != 5) {testSuccess = false;}
    for(int i = 0; i < 5; i ++) {
        if(a7->get(i) != 'c') {testSuccess = false;}
    }
    printTestResult(testSuccess, "Assignment Operator");
    delete a6;
    delete a7;

    // Test Bracket Operator
    testSuccess = true;
    Array * a8 = new Array(5, 'c');
    if((*a8)[0] != 'c') {testSuccess = false;}
    (*a8)[0] = 'd';
    if(a8->get(0) != 'd') {testSuccess = false;}
    printTestResult(testSuccess, "Bracket Operator");
    delete a8;

    // Test Get Method
    testSuccess = true;
    Array * a9 = new Array(5, 'd');
    for(int i = 0; i < 5; i ++) {
        if(a9->get(i) != 'd') {testSuccess = false;}
    }
    printTestResult(testSuccess, "Get Method");
    delete a9;

    // Test Set Method
    testSuccess = true;
    Array * a10 = new Array(5, 'e');
    for(int i = 0; i < 5; i ++) {
        a10->set(i, 'f');
    }
    for(int i = 0; i < 5; i ++) {
        if(a10->get(i) != 'f') {testSuccess = false;}
    }
    printTestResult(testSuccess, "Set Method");
    delete a10;

    // Test Resize Method
    testSuccess = true;
    Array * a11 = new Array(5);
    a11->resize(10);
    if(a11->size() != 10 || a11->max_size() != 10) {testSuccess = false;}
    a11->resize(5);
    if(a11->size() != 5 || a11->max_size() != 10) {testSuccess = false;}
    a11->resize(5);
    if(a11->size() != 5 || a11->max_size() != 10) {testSuccess = false;}
    printTestResult(testSuccess, "Resize Method");
    delete a11;

    // Test Find Method
    testSuccess = true;
    Array * a12 = new Array(5, 'a');
    a12->set(2, 'c');
    if(a12->find('c') != 2) {testSuccess = false;}
    if(a12->find('c', 1) != 2) {testSuccess = false;}
    if(a12->find('c', 3) != -1) {testSuccess = false;}
    if(a12->find('d') != -1) {testSuccess = false;}
    printTestResult(testSuccess, "Find Method");
    delete a12;

    // Test Equality Operator
    testSuccess = true;
    Array * a13 = new Array(5, 'a');
    Array * a14 = new Array(*a13);
    if(!(*a13 == *a14)) {testSuccess = false;}
    a13->set(0, 'b');
    if(*a13 == *a14) {testSuccess = false;}
    printTestResult(testSuccess, "Equality Operator");
    delete a13;
    delete a14;

    // Test Inequality Operator
    testSuccess = true;
    Array * a15 = new Array(5, 'a');
    Array * a16 = new Array(*a15);
    if((*a15 != *a16)) {testSuccess = false;}
    a15->set(0, 'b');
    if(!(*a15 != *a16)) {testSuccess = false;}
    printTestResult(testSuccess, "Inequality Operator");
    delete a15;
    delete a16;

    // Test Fill Method
    testSuccess = true;
    Array * a17 = new Array(5);
    a17->fill('x');
    for(int i = 0; i < 5; i++) {
        if(a17->get(i) != 'x') {testSuccess = false;}
    }
    printTestResult(testSuccess, "Fill Method");
    delete a17;

    return 0;
}
