// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "Base_Array.h"

template <typename T>
Base_Array<T>::Base_Array (void) : cur_size_(DEFAULT_SIZE), data_(new T[DEFAULT_SIZE]) {}

template <typename T>
Base_Array<T>::Base_Array (size_t length) : cur_size_(length) {
	// Dr. Ryan: But we already have at this point in our initialization list...
    // Kyle: Moved creation of array to after exception handling
    if(length == 0) {
        throw std::length_error("Cannot create Base_Array of length 0");
    }

    // Need to set data_ on the heap after exception handling so that we don't leak it.
    // Destructor is not called when a constructor throws an error.
    data_ = new T[length];
}

template <typename T>
Base_Array<T>::Base_Array (size_t length, T fill) : cur_size_(length) {
    if(length == 0) {
        throw std::length_error("Cannot create Base_Array of length 0");
    }
    data_ = new T[length];
    this->fill(fill);
}

// We do not care about maxsize, or elements beyond the current size of the array
template <typename T>
Base_Array<T>::Base_Array (const Base_Array & array) : cur_size_(array.size()) {
    if(array.size() == 0) {
        throw std::length_error("Cannot create Base_Array of length 0");
    }
    data_ = new T[array.size()];

    // Set array values
    for(int i = 0; i < cur_size_; i++) {
        data_[i] = array[i];
    }
}

template <typename T>
Base_Array<T>::~Base_Array (void)
{
    delete [] data_;
}

// We do not care about maxsize, or elements beyond the current size of the array
template <typename T>
const Base_Array<T> & Base_Array<T>::operator = (const Base_Array & rhs)
{
    if(this == &rhs) { return *this; }
    //TODO: Change this error type
    if(cur_size_ != rhs.size()) {
        throw std::out_of_range("index out of bounds");
    }

    // Set array values
    for(int i = 0; i < cur_size_; i++) {
        data_[i] = rhs[i];
    }

    return *this;
}


// There is no difference in behavior between these methods
template <typename T>
T & Base_Array<T>::operator [] (size_t index)
{
    if(index >= cur_size_) {
        throw std::out_of_range("index out of bounds");
    }
    return data_[index];
}

template <typename T>
const T & Base_Array<T>::operator [] (size_t index) const
{
    if(index >= cur_size_) {
        throw std::out_of_range("index out of bounds");
    }
    return data_[index];
}

template <typename T>
T Base_Array<T>::get (size_t index) const
{
    if(index >= cur_size_) {
        throw std::out_of_range("index out of bounds");
    }
    return data_[index];
}

template <typename T>
void Base_Array<T>::set (size_t index, T value)
{
    if(index >= cur_size_) {
        throw std::out_of_range("index out of bounds");
    }
    data_[index] = value;
}

// Could just use a default value of 0 for start.
template <typename T>
int Base_Array<T>::find (T ch) const
{
    return find(ch, 0);
}

template <typename T>
int Base_Array<T>::find (T ch, size_t start) const
{
    if(start >= cur_size_) {
        throw std::out_of_range("index out of bounds");
    }

    for(int i = start; i < cur_size_; i++) {
        if(get(i) == ch) {
            return i;
        }
    }

    return -1;
}

// We do not care about maxsize, or elements beyond the current size of the array
template <typename T>
bool Base_Array<T>::operator == (const Base_Array & rhs) const
{
	if(this == &rhs) { return true; }
	
    // If size is different, then arrays are not the equal
    if(cur_size_ != rhs.size()) { return false; }

    // If any elements are not equal, then arrays are not the equal
    for(int i = 0; i < cur_size_; i++) {
        if(data_[i] != rhs.get(i) ) {
            return false;
        }
    }

    return true;
}

template <typename T>
bool Base_Array<T>::operator != (const Base_Array & rhs) const
{
	return !(*this == rhs);
}

template <typename T>
void Base_Array<T>::fill (T ch)
{
    for(int i = 0; i < cur_size_; i++) {
        data_[i] = ch;
    }
}
