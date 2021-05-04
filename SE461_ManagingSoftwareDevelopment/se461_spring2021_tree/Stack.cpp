// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "Stack.h"

//
// Stack
//
template <typename T>
// Dynamic array has a size of 10, Stack has a size of 0
// Dr. Ryan: Don't we need to call the constructor for Dynamic_Array?
// Kyle: This calls the default constructor of data_
Stack <T>::Stack (void) : data_(), size_(0) {}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack) : data_(stack.size()), size_(stack.size())
{
    data_ = stack.data_;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void) {}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    // When Dynamic Array is full, increase size.
    if(size() >= data_.size()) {
        data_.resize(size()+1);
    }

    data_.set(size_++, element);
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    // If Stack is empty, throw error
    if(size() == 0) {
        //TODO: Implement custom exception
        throw std::out_of_range("The stack is empty");
    }

    // We do not have to set data_(size_) to null. This is because we can never have an empty element
    // of a stack, so if the size increases, it is because we are pushing onto it, so the old
    // data will be overridden.
    size_--;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    data_ = rhs.data_;
    size_ = rhs.size();
    return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    while(!is_empty()) {
        pop();
    }
}
