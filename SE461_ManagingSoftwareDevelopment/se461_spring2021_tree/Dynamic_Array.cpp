// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "Dynamic_Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Dynamic_Array
//
template <typename T>
// Dr. Ryan: You shouldn't need the full qualifier here - Base_Array<T>() should suffice.
// Kyle: Fixed
Dynamic_Array <T>::Dynamic_Array (void) : Base_Array<T>(), max_size_(DEFAULT_SIZE) {}

//
// Dynamic_Array (size_t)
//
template <typename T>
Dynamic_Array <T>::Dynamic_Array (size_t length) : Base_Array<T>(length), max_size_(length) {
	// Dr. Ryan: But we already have at this point in our initialization list...
    // Kyle: This is now handled in the Base_Array Constructor
}

//
// Dynamic_Array (size_t, T)
//
template <typename T>
Dynamic_Array <T>::Dynamic_Array (size_t length, T fill) : Base_Array<T>(length, fill), max_size_(length) {}

//
// Dynamic_Array (const Dynamic_Array &)
//
template <typename T>
Dynamic_Array <T>::Dynamic_Array (const Dynamic_Array & array) : Base_Array<T>(array), max_size_(array.size())
{
	// Dr. Ryan: Why do we need this - isn't this handled by the base class?
    // Kyle: Now use Base_Array's Copy Constructor
}

//
// ~Dynamic_Array
//
// this->data_ gets deleted in Base_Array destructor
template <typename T>
Dynamic_Array <T>::~Dynamic_Array (void) {}

//
// operator =
//
template <typename T>
const Dynamic_Array <T> & Dynamic_Array <T>::operator = (const Dynamic_Array & rhs)
{
    if(this == &rhs) { return *this; }

    resize(rhs.size());

    // Set array values
    for(int i = 0; i < this->cur_size_; i++) {
        this->data_[i] = rhs[i];
    }

    return *this;
}

//
// resize
//
template <typename T>
void Dynamic_Array <T>::resize (size_t new_size)
{
    // As long as the new size is lower than max size, we only have to change the cur size
	// Else we have to make a new array.
	if(new_size <= max_size_) {
		this->cur_size_ = new_size;
	} else {
		// Fill temp array with old contents using new_size
		T * temp = new T[new_size];
		for(int i = 0; i < this->cur_size_; i++) {
			temp[i] = this->data_[i];
		}
		
		// Swap pointers
		std::swap(temp,this->data_);
		
		this->cur_size_ = new_size;
		max_size_ = new_size;
		
		delete [] temp;
	}
}
