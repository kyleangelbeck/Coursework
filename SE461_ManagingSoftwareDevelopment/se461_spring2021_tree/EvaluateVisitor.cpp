// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "EvaluateVisitor.h"

EvaluateVisitor::EvaluateVisitor() : TreeVisitor() {}


void EvaluateVisitor::visitNumberNode(NumberNode & numberNode) {
    resultStack_.push(numberNode.getValue());
}

void EvaluateVisitor::visitAdditionNode(AdditionNode & additionNode) {
    additionNode.getRightChild()->Accept(*this);
    additionNode.getLeftChild()->Accept(*this);

    int a = resultStack_.top();
    resultStack_.pop();

    int b = resultStack_.top();
    resultStack_.pop();

    resultStack_.push(a + b);
}

void EvaluateVisitor::visitSubtractionNode(SubtractionNode & subtractionNode) {
    subtractionNode.getRightChild()->Accept(*this);
    subtractionNode.getLeftChild()->Accept(*this);

    int a = resultStack_.top();
    resultStack_.pop();

    int b = resultStack_.top();
    resultStack_.pop();

    resultStack_.push(a - b);
}

void EvaluateVisitor::visitMultiplicationNode(MultiplicationNode & multiplicationNode) {
    multiplicationNode.getRightChild()->Accept(*this);
    multiplicationNode.getLeftChild()->Accept(*this);

    int a = resultStack_.top();
    resultStack_.pop();

    int b = resultStack_.top();
    resultStack_.pop();

    resultStack_.push(a * b);
}

void EvaluateVisitor::visitDivisionNode(DivisionNode & divisionNode) {
    divisionNode.getRightChild()->Accept(*this);
    divisionNode.getLeftChild()->Accept(*this);

    int a = resultStack_.top();
    resultStack_.pop();

    int b = resultStack_.top();
    resultStack_.pop();

    if(b == 0) {
        resultStack_.clear();
        throw DivByZeroException();
    }

    resultStack_.push(a / b);
}

void EvaluateVisitor::visitModuloNode(ModuloNode & moduloNode) {
    moduloNode.getRightChild()->Accept(*this);
    moduloNode.getLeftChild()->Accept(*this);

    int a = resultStack_.top();
    resultStack_.pop();

    int b = resultStack_.top();
    resultStack_.pop();

    if(b == 0) {
        resultStack_.clear();
        throw ModByZeroException();
    }

    resultStack_.push(a % b);
}

int EvaluateVisitor::evaluateTree(Node * root) {
    root->Accept(*this);

    int result = resultStack_.top();
    resultStack_.pop();
    return result;
}
