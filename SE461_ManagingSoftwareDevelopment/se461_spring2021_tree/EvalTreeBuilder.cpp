// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "EvalTreeBuilder.h"

EvalTreeBuilder::EvalTreeBuilder() {
	// Dr. Ryan: Nice use of a Map here!
    precedenceMap.insert(std::pair<std::string,int>("(",4));
    precedenceMap.insert(std::pair<std::string,int>("+",3));
    precedenceMap.insert(std::pair<std::string,int>("-",3));
    precedenceMap.insert(std::pair<std::string,int>("*",2));
    precedenceMap.insert(std::pair<std::string,int>("/",2));
    precedenceMap.insert(std::pair<std::string,int>("%",2));
}


Node * EvalTreeBuilder::buildTree(std::string rawInput) {
    Stack<Node *> postfixStack;     // postfix Stack of Commands

    // Convert input to postfix
    try {
        postfixStack = infixToPostfix(std::istringstream(rawInput));
    } catch(InvalidInputException e) {
        throw e;
    }

    // Flip stack
    Stack<Node *> tempStack;        // Stack temporarily used to flip the postfixStack
    while(!postfixStack.is_empty()) {
        tempStack.push(postfixStack.top());
        postfixStack.pop();
    }
    postfixStack = tempStack;

    // Build tree
    Stack<Node *> treeStack; // Stack of tree parts
    while(!postfixStack.is_empty()) {
        if(postfixStack.top()->getNodeType() == NUMBER) {
            treeStack.push(postfixStack.top());
            postfixStack.pop();
        } else if(postfixStack.top()->getNodeType() == BINARYOPERATOR) {
            // PopConnectPush
            // Pop top two from treeStack and connect them to top of postfixStack
            // Then push it postfixStack back onto treeStack

            // Connect first treeStack
            postfixStack.top()->setRightChild(treeStack.top());
            postfixStack.top()->getRightChild()->setParent(postfixStack.top());
            treeStack.pop();

            // Connect second treeStack
            postfixStack.top()->setLeftChild(treeStack.top());
            postfixStack.top()->getLeftChild()->setParent(postfixStack.top());
            treeStack.pop();

            // Push onto treeStack
            treeStack.push(postfixStack.top());
            postfixStack.pop();
        } else {
            // This should never be reached.
            throw std::exception();
        }
    }

    // Return root
    if(postfixStack.size() != 0 || treeStack.size() != 1) {
        // This should never run. If it does, something is wrong with this program.
        throw std::exception();
    } else {
        return treeStack.top();
    }
}

Stack<Node *> EvalTreeBuilder::infixToPostfix(std::istringstream input) {
    std::string token;                  // Current Token being evaluated
    bool expectingNumber = true;        // Whether or not the next token is expected to be a number
    Stack<std::string> operatorStack;   // Stack of operators (as strings) not yet in postfix
    Stack<Node *> postfixStack; // Expression converted to postfix
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
            postfixStack.push(new NumberNode(std::stoi(token)));

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

void EvalTreeBuilder::pushOperatorToStack(Stack<std::string> &operatorStack, Stack<Node *> &postfixStack) {
    std::string op = operatorStack.top();   // Operator to be pushed onto postfixStack

    if(op == "+") {
        postfixStack.push(new AdditionNode());
    } else if(op == "-") {
        postfixStack.push(new SubtractionNode());
    } else if(op == "*") {
        postfixStack.push(new MultiplicationNode());
    } else if(op == "/") {
        postfixStack.push(new DivisionNode());
    } else if(op == "%") {
        postfixStack.push(new ModuloNode());
    } else {
        // This should never be reached
        deleteStack(postfixStack);
        throw std::exception();
    }
    operatorStack.pop();
}

bool EvalTreeBuilder::isNumber(std::string input) {
    for (int i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) { return false; }
    }
 
    return true;
}

int EvalTreeBuilder::getPrecedence(std::string input) {
    if(precedenceMap.find(input) == precedenceMap.end()) {
        return -1;
    }
    return precedenceMap.find(input)->second;
}

void EvalTreeBuilder::deleteStack(Stack<Node *> &postfixStack) {
    while(!postfixStack.is_empty()) {
        delete postfixStack.top();
        postfixStack.pop();
    }
}
