// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "Array.h"

// Dr. Ryan: We should include this in our Header file as our header guard can protected
//			 any unnecessary inclusions.
// FIXED: Moved include to header file

#define DEFAULT_SIZE 10

Array::Array (void) : cur_size_(DEFAULT_SIZE), max_size_(DEFAULT_SIZE), data_(new char[DEFAULT_SIZE]) {}

// Dr. Ryan: We need to check to make sure the user specified length is not '0'.
// FIXED: Throws error when length is 0
Array::Array (size_t length) : cur_size_(length), max_size_(length), data_(new char[length]) {
    // "Note: if a constructor finishes by throwing an exception, the memory associated with the object itself is cleaned up — there is no memory leak."
    // -https://isocpp.org/wiki/faq/exceptions#ctors-can-throw
    // Cool!

    // Do not think there would be a way to check this before the initialization list.
    if(length == 0) {
        throw std::length_error("Cannot create Array of length 0");
    }
}

// Dr. Ryan: We need to check to make sure the user specified length is not '0'.
// FIXED: Throws error when length is 0
Array::Array (size_t length, char fill) : cur_size_(length), max_size_(length), data_(new char[length]) {
    if(length == 0) {
        throw std::length_error("Cannot create Array of length 0");
    }
    this->fill(fill);
}

// We do not care about maxsize, or elements beyond the current size of the array
Array::Array (const Array & array) : cur_size_(array.size()), max_size_(array.size()), data_(new char[array.size()]) 
{
	// Dr. Ryan: What about a resize instead here?
    // Kyle: Why would we resize here? We are initializing the size to the other array's size.
    //       We are not changing the size of anything.
    //       Would you want me to initialize the size to some number then do resize(array.size()) ?
	
    // Set array values
    for(int i = 0; i < cur_size_; i++) {
        data_[i] = array[i];
    }
}

Array::~Array (void)
{
    delete [] data_;
}

// We do not care about maxsize, or elements beyond the current size of the array
const Array & Array::operator = (const Array & rhs)
{
	// Dr. Ryan: Always check for self-assignment first.
    // FIXED: Check if rhs has same address as this
    if(this == &rhs) { return *this; }
	
	// Dr. Ryan: Do we ALWAYS need to resize here?
    // Kyle: We don't always need to resize, but resize will swiftly deal with the simple cases anyways.
    //       I'd rather just let resize deal with the different cases than do that here.
	
    // Resize array to rhs size
    resize(rhs.size());

    // Set array values
    for(int i = 0; i < cur_size_; i++) {
        data_[i] = rhs[i];
    }

    return *this;
}


// There is no difference in behavior between these methods
char & Array::operator [] (size_t index)
{
    if(index >= cur_size_) {
        throw std::out_of_range("index out of bounds");
    }
    return data_[index];
}

const char & Array::operator [] (size_t index) const
{
    if(index >= cur_size_) {
        throw std::out_of_range("index out of bounds");
    }
    return data_[index];
}

char Array::get (size_t index) const
{
    if(index >= cur_size_) {
        throw std::out_of_range("index out of bounds");
    }
    return data_[index];
}

void Array::set (size_t index, char value)
{
    if(index >= cur_size_) {
        throw std::out_of_range("index out of bounds");
    }
    data_[index] = value;
}

void Array::resize (size_t new_size)
{ 
	//TODO: throw exception for data loss when resizing the array to be smaller.

	// As long as the new size is lower than max size, we only have to change the cur size
	// Else we have to make a new array.
	if(new_size <= max_size_) {
		cur_size_ = new_size;
	} else {
		// Fill temp array with old contents using new_size
		char * temp = new char[new_size];
		for(int i = 0; i < cur_size_; i++) {
			temp[i] = data_[i];
		}
		
		// Swap pointers
		std::swap(temp,data_);
		
		cur_size_ = new_size;
		max_size_ = new_size;
		
		delete [] temp;
	}
}

// Could just use a default value of 0 for start.
// Dr. Ryan: Yes, you are exactly right and you have implemented this properly - kudos!
int Array::find (char ch) const
{
    return find(ch, 0);
}

int Array::find (char ch, size_t start) const
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
bool Array::operator == (const Array & rhs) const
{
	// Dr. Ryan: Always check for self-comparison first.
    // FIXED: Check if rhs has same address as this
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

// We do not care about maxsize, or elements beyond the current size of the array
bool Array::operator != (const Array & rhs) const
{
	// Dr. Ryan: Why not just call the above method and negate the result - code reuse,
	//			 we can work smarter, not harder!
    // FIXED: Called equality operator
	return !(*this == rhs);
}

void Array::fill (char ch)
{
    for(int i = 0; i < cur_size_; i++) {
        data_[i] = ch;
    }
}
