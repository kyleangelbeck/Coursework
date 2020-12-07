// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#include <cstddef>      // NULL
#include "Node.h"

template <class T>
Node<T>::Node(T data) : data_(data) {}

template <class T>
Node<T>::Node() : data_(NULL) {}

template <class T>
Node<T>::~Node() {}

template <class T>
T Node<T>::getData() { return data_; }

template <class T>
void Node<T>::setData(T data) { data_ = data; }
