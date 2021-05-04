// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef TREEVISITOR_H
#define TREEVISITOR_H

#include "Stack.h"

class Node;
class NumberNode;
class AdditionNode;
class SubtractionNode;
class MultiplicationNode;
class DivisionNode;
class ModuloNode;

class TreeVisitor {
    public:
        // Destructor
        virtual ~TreeVisitor() {}

        // Visit Number Node
        virtual void visitNumberNode(NumberNode & numberNode) = 0;

        // Visit Addition Node
        virtual void visitAdditionNode(AdditionNode & additionNode) = 0;

        // Visit Subtraction Node
        virtual void visitSubtractionNode(SubtractionNode & subtractionNode) = 0;

        // Visit Multiplication Node
        virtual void visitMultiplicationNode(MultiplicationNode & multiplicationNode) = 0;

        // Visit Division Node
        virtual void visitDivisionNode(DivisionNode & divisionNode) = 0;

        // Visit Modulo Node
        virtual void visitModuloNode(ModuloNode & moduloNode) = 0;

        // Evaluate tree
        virtual int evaluateTree(Node * root) = 0;

    protected:
        // Non-Public Default Constructor
        TreeVisitor() {}
};

#include "Node.h"
#include "NumberNode.h"
#include "AdditionNode.h"
#include "SubtractionNode.h"
#include "MultiplicationNode.h"
#include "DivisionNode.h"
#include "ModuloNode.h"

#endif
