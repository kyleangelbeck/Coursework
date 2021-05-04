// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef EVALUATEVISITOR_H
#define EVALUATEVISITOR_H

#include "TreeVisitor.h"
#include <exception>        // std::exception

class EvaluateVisitor : public TreeVisitor {
    public:
        class DivByZeroException : public std::exception {
            public:
                DivByZeroException() : std::exception() {}
        };

        class ModByZeroException : public std::exception {
            public:
                ModByZeroException() : std::exception() {}
        };

        // Constructor
        EvaluateVisitor();

        // Destructor
        virtual ~EvaluateVisitor() {}

        // Visit Number Node
        virtual void visitNumberNode(NumberNode & numberNode);

        // Visit Addition Node
        virtual void visitAdditionNode(AdditionNode & additionNode);

        // Visit Subtraction Node
        virtual void visitSubtractionNode(SubtractionNode & subtractionNode);

        // Visit Multiplication Node
        virtual void visitMultiplicationNode(MultiplicationNode & multiplicationNode);

        // Visit Division Node
        virtual void visitDivisionNode(DivisionNode & divisionNode);

        // Visit Modulo Node
        virtual void visitModuloNode(ModuloNode & moduloNode);

        // Evaluate calculator tree and return result
        virtual int evaluateTree(Node * root);

    private:
        // Result Stack
        Stack<int> resultStack_;
};

#endif
