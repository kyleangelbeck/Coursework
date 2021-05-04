// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

/* My PC command
    mwc-ace -type make && make clean && make && valgrind --log-file=Valgrind.txt ./A4.exe
*/
/* Thomas command
    mwc.pl -type make && make clean && make && valgrind --log-file=Valgrind.txt ./A4.exe
*/

#include "EvalTreeBuilder.h"
#include "EvaluateVisitor.h"
#include "Node.h"
#include "AdditionNode.h"
#include "SubtractionNode.h"
#include "MultiplicationNode.h"
#include "DivisionNode.h"
#include "ModuloNode.h"

#include <iostream>     //std::cin, std::cout, std::endl

/**
* Run calculator loop
*/
void runCalculator();

int main() {
    // Running of Calculator
    std::cout << "Welcome to epic calculator program." << std::endl;
    runCalculator();
    std::cout << "Exiting epic calculator program." << std::endl;

    return 0;
}

void runCalculator() {
    std::string rawInput;                           // Input from the user
    bool failedToExecute;                           // Boolean to track if execution of the stack fails
    TreeBuilder * builder = new EvalTreeBuilder();          // Tree Builder
    TreeVisitor * visitor = new EvaluateVisitor();  // Tree Evaluator

    while(true) {
        // Get user input
        std::cout << "Please enter epic calculation to be calculated" << std::endl;
        std::getline(std::cin, rawInput);

        // Exit program
        if(rawInput == "EXIT") { 
            // Dr. Ryan: If you just "return" from here you will have a memory leak as you have two 
            //			 things placed on the Heap (Lines #44 and #46) that aren't deleted yet potentially.
            // Kyle: Oopsies. Returned instead of breaked. Fixed.
            break;
		} else if (rawInput == "") {
            // Empty input was giving an error, so I just threw the case here.
            std::cout << "ERROR: Invalid Input" << std::endl;
            continue;
        }

        // Build Tree
        Node * root = nullptr;
        try {
            root = builder->buildTree(rawInput);
        } catch(EvalTreeBuilder::InvalidInputException e) {
            // The tree will be deleted before the exception is thrown,
            // so we don't have to worry about that here.
            std::cout << "ERROR: Invalid Input" << std::endl;
            continue;
        }

        // Evaluate Tree
        try {
            std::cout << visitor->evaluateTree(root) << std::endl;
        } catch(EvaluateVisitor::DivByZeroException e) {
            std::cout << "ERROR: Attempted to divide by 0" << std::endl;
        } catch(EvaluateVisitor::ModByZeroException e) {
            std::cout << "ERROR: Attempted to divide by 0" << std::endl;
        }

        // Delete Tree
        delete root;
    }

    delete builder;
    delete visitor;
}
