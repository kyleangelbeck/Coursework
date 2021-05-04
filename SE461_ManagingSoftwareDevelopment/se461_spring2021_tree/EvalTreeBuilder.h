// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef EVALTREEBUILDER_H
#define EVALTREEBUILDER_H

#include "TreeBuilder.h"
#include "Node.h"
#include "NumberNode.h"
#include "AdditionNode.h"
#include "SubtractionNode.h"
#include "MultiplicationNode.h"
#include "DivisionNode.h"
#include "ModuloNode.h"

#include <iostream>     //std::cin, std::cout, std::endl
#include <map>          //std::map
#include <string>       //std::string, std::stoi
#include <sstream>      //std::istringstream

class EvalTreeBuilder : public TreeBuilder {
    public:
        // Custom Exception Class
        class InvalidInputException : public std::exception {
            public:
                InvalidInputException() : std::exception() {}
        };

        // Constructor
        EvalTreeBuilder();
        // Destructor
        ~EvalTreeBuilder() {}

        // Build the tree
        virtual Node * buildTree(std::string rawInput);

    private:
        /**
        * Turn an istringstream of a infix string into a postfix string
        *
        * @param        istringstream infix string
        * @return       postfix string
        */
        Stack<Node *> infixToPostfix(std::istringstream input);

        /**
        * Push top of operatorStack onto postfixStack
        * @param        Stack<string> stack of operators
        * @param        Stack<Node *> postfix stack of command pointers
        */
        void pushOperatorToStack(Stack<std::string> &operatorStack, Stack<Node *> &postfixStack);

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
        * @param        Stack<Node *> postfix stack of command pointers
        */
        void deleteStack(Stack<Node *> &postfixStack);

        // Precedence Map
        std::map<std::string, int> precedenceMap;
};

#endif
