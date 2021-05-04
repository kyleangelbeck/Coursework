// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "Queue.h"

//
// Queue
//
template <typename T>
// Dynamic array has a size of 10, Queue has a size of 0
// TODO:Dr. Ryan: Don't we need to call the constructor for Dynamic Array here?
// Kyle: Is this not calling the default constructor of data_?
Queue <T>::Queue (void) : data_(), size_(0) {}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue & queue) : data_(queue.size()), size_(queue.size())
{
    data_ = queue.data_;
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void) {}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element) {
    // When Dynamic Array is full, increase size.
    if(size() >= data_.size()) {
        data_.resize(size()+1);
    }

    data_.set(size_++, element);
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
    // If Queue is empty, throw error
    if(size() == 0) {
        //TODO: Implement custom exception
        throw std::out_of_range("The queue is empty");
    }
    
    // Save first element, shift entire queue over, then return first element
    T element = data_.get(0);
    for(int i = 0; i < size()-1; i++) {
        data_[i] = data_[i+1];
    }
    data_.set(--size_, NULL);

    return element;
}

//
// head
//
template <typename T>
T Queue <T>::head (void)
{
    // If Queue is empty, throw error
    if(size() == 0) {
        //TODO: Implement custom exception
        throw std::out_of_range("The queue is empty");
    }
    return data_.get(0);
}

//
// tail
//
template <typename T>
T Queue <T>::tail (void)
{
    // If Queue is empty, throw error
    if(size() == 0) {
        //TODO: Implement custom exception
        throw std::out_of_range("The queue is empty");
    }
    return data_.get(size_);
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    data_ = rhs.data_;
    size_ = rhs.size();
    return *this;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
    for(int i = 0; i < size(); i++) {
        data_.set(i, NULL);
    }
    size_ = 0;
}
