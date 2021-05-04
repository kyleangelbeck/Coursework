// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

/* My PC command
    mwc-ace -type make && make clean && make && valgrind --log-file=Valgrind.txt ./A3.exe
*/
/* Thomas command
    mwc.pl -type make && make clean && make && valgrind --log-file=Valgrind.txt ./A3.exe
*/

#include "StackCommandFactory.h"
#include "Stack.h"
#include "StackCommand.h"
#include "Number.h"
#include "BinaryOperator.h"
#include "AdditionOperator.h"
#include "SubtractionOperator.h"
#include "MultiplicationOperator.h"
#include "DivisionOperator.h"
#include "ModuloOperator.h"


#include <iostream>     //std::cin, std::cout, std::endl
#include <map>          //std::map
#include <sstream>      //std::istringstream
#include <stdexcept>    //std::exception
#include <string>       //std::string, std::stoi

// Global Precedence Map
std::map<std::string, int> precedenceMap;

/**
* Fill global precedence map
*/
void fillMap();

/**
* Run calculator loop
*/
void runCalculator();

/**
* Turn an istringstream of a infix string into a postfix string
*
* @param        istringstream infix string
* @return       postfix string
*/
Stack<StackCommand *> infixToPostfix(std::istringstream input);

/**
* Push top of operatorStack onto postfixStack
* @param        Stack<string> stack of operators
* @param        Stack<StackCommand *> postfix stack of command pointers
*/
void pushOperatorToStack(Stack<std::string> &operatorStack, Stack<StackCommand *> &postfixStack);

/**
* Determine if a given string is a number
*
* @param         string      input to test
* @retval        true        input is a number
* @retval        false       input is not a number
*/
bool isNumber(std::string input);

/** Get stack precedence of a given string
* @param         string      input to find precedence of
* @return        precedence of given string
* @retval        -1          input is invalid
*/
int getPrecedence(std::string input);

/** Get stack precedence of a given string
* @param        Stack<StackCommand *> postfix stack of command pointers
*/
void deleteStack(Stack<StackCommand *> &postfixStack);

// Custom Exception Class
class InvalidInputException : public std::exception {
    public:
        InvalidInputException() : std::exception() {}
};

// Main Program
int main () {
    // Fill PrecedenceMap
    fillMap();

    std::cout << "Welcome to epic calculator program." << std::endl;
    runCalculator();
    std::cout << "Exiting epic calculator program." << std::endl;

    return 0;
}

void fillMap() {
    precedenceMap.insert(std::pair<std::string,int>("(",4));
    precedenceMap.insert(std::pair<std::string,int>("+",3));
    precedenceMap.insert(std::pair<std::string,int>("-",3));
    precedenceMap.insert(std::pair<std::string,int>("*",2));
    precedenceMap.insert(std::pair<std::string,int>("/",2));
    precedenceMap.insert(std::pair<std::string,int>("%",2));
}

void runCalculator() {
    std::string rawInput;                   // Input from the user
    Stack<StackCommand *> postfixStack;     // postfix Stack of Commands
    Stack<int> workingStack;                // Stack of integers used when evaluating postfixStack
    bool failedToExecute;                   // Boolean to track if execution of the stack fails

    while(true) {
        // Get user input
        std::cout << "Please enter epic calculation to be calculated" << std::endl;
        std::getline(std::cin, rawInput);

        // Exit program
        if(rawInput == "EXIT") { return; }

        // Convert input to postfix
        try {
            postfixStack = infixToPostfix(std::istringstream(rawInput));
        } catch(InvalidInputException e) {
            std::cout << "ERROR: Invalid Input" << std::endl;
            continue;
        }

        // Flip stack
        Stack<StackCommand *> tempStack;        // Stack temporarily used to flip the postfixStack
        while(!postfixStack.is_empty()) {
            tempStack.push(postfixStack.top());
            postfixStack.pop();
        }
        postfixStack = tempStack;

        // Evaluate Stack
        failedToExecute = false;
        // Execute each Command, then delete/pop it from stack.
        while(!postfixStack.is_empty()) {
            try{
                postfixStack.top()->execute(workingStack);
            } catch(DivisionOperator::DivByZeroException e) {
                std::cout << "ERROR: Attempted to divide by 0" << std::endl;
                deleteStack(postfixStack);
                failedToExecute = true;
                break;
            }
            catch(ModuloOperator::ModByZeroException e) {
                std::cout << "ERROR: Attempted to mod by 0" << std::endl;
                deleteStack(postfixStack);
                failedToExecute = true;
                break;
            }

            delete postfixStack.top();
            postfixStack.pop();
        }

        // Print result to console if it executed correctly
        if(failedToExecute) {
            continue;
        } else if(workingStack.size() != 1 || postfixStack.size() != 0) {
            // This should never run. If it does, something is wrong with this program.
            std::cout << "ERROR: Not all commands were ran" << std::endl;
        } else {
            std::cout << "Answer: " << workingStack.top() << std::endl;
            workingStack.pop();
        }
        
    }
}

Stack<StackCommand *> infixToPostfix(std::istringstream input) {
    std::string token;                  // Current Token being evaluated
    bool expectingNumber = true;        // Whether or not the next token is expected to be a number
    StackCommandFactory factory;        // Factory that creates Commands for postfixStack
    Stack<std::string> operatorStack;   // Stack of operators (as strings) not yet in postfix
    Stack<StackCommand *> postfixStack; // Expression converted to postfix
    int tokenPrecendece;                // Precedence of current operand token

    // Loop through stream adding to operatorStack/postfixStack.
    while(input >> token) {
        if(isNumber(token)) {
            // If we are not expecting a number, throw invalid input
            if(!expectingNumber) {
                deleteStack(postfixStack);
                throw InvalidInputException();
            }

            // Push new number onto the postfix stack
            postfixStack.push(factory.createNumber(std::stoi(token)));

            // We are now expecting a operator
            expectingNumber = false;

        } else if(token == "(") {
            // If we are not expecting a number, throw invalid input
            if(!expectingNumber) {
                deleteStack(postfixStack);
                throw InvalidInputException();
            }

            // Push open parenthesis onto stack
            operatorStack.push("(");

        } else if(token == ")") {
            // If we are expecting a number, throw invalid input
            if(expectingNumber) {
                deleteStack(postfixStack);
                throw InvalidInputException();
            }

            // Pop into postfixStack until matching open parenthesis are found.
            try {
                while(operatorStack.top() != "(") {
                    pushOperatorToStack(operatorStack, postfixStack);
                }
            } catch (std::out_of_range e) {
                // No matching open parenthesis found
                deleteStack(postfixStack);
                throw InvalidInputException();
            }
            // Pop matching open parenthesis
            operatorStack.pop();

        } else {
            tokenPrecendece = getPrecedence(token);

            // If we are expecting a number or the token is not in map, throw invalid input
            if(expectingNumber || tokenPrecendece == -1) {
                deleteStack(postfixStack);
                throw InvalidInputException();
            }

            // While stack is not empty and token has lower precedence, Pop into postfixStack.
            while(!operatorStack.is_empty() && tokenPrecendece >= getPrecedence(operatorStack.top())) {
                pushOperatorToStack(operatorStack, postfixStack);
            }
            // Push token onto stack
            operatorStack.push(token);
            // We are now expecting a number
            expectingNumber = true;
        }
    }

    // Pop rest of stack into postfixStack
    while(!operatorStack.is_empty()) {
        // Open parenthesis found with no matching closing parenthesis
        if(operatorStack.top() == "(") {
            deleteStack(postfixStack);
            throw InvalidInputException();
        }
        pushOperatorToStack(operatorStack, postfixStack);
    }

    // Return completed stack
    return postfixStack;
}

void pushOperatorToStack(Stack<std::string> &operatorStack, Stack<StackCommand *> &postfixStack) {
    StackCommandFactory factory;            // Factory that creates Commands for postfixStack
    std::string op = operatorStack.top();   // Operator to be pushed onto postfixStack

    if(op == "+") {
        postfixStack.push(factory.createAdditionOperator());
    } else if(op == "-") {
        postfixStack.push(factory.createSubtractionOperator());
    } else if(op == "*") {
        postfixStack.push(factory.createMultiplicationOperator());
    } else if(op == "/") {
        postfixStack.push(factory.createDivisionOperator());
    } else if(op == "%") {
        postfixStack.push(factory.createModuloOperator());
    } else {
        // This should never be reached
        deleteStack(postfixStack);
        throw std::exception();
    }
    operatorStack.pop();
}

bool isNumber(std::string input) {
    for (int i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) { return false; }
    }
 
    return true;
}

int getPrecedence(std::string input) {
    if(precedenceMap.find(input) == precedenceMap.end()) {
        return -1;
    }
    return precedenceMap.find(input)->second;
}

void deleteStack(Stack<StackCommand *> &postfixStack) {
    while(!postfixStack.is_empty()) {
        delete postfixStack.top();
        postfixStack.pop();
    }
}
