// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

#include <cstring>          // for size_t definition
#include "Base_Array.h"

/**
 * @class Dynamic_Array
 *
 * Basic implementation of a standard array class for chars.
 */
template <typename T>
class Dynamic_Array : public Base_Array <T>
{
public:
	// Dr. Ryan: It is just an alias - in theory we could use the word type here.
  /// Type definition of the element type.
  typedef T type;

  /// Default constructor.
  Dynamic_Array (void);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   */
  Dynamic_Array (size_t length);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   * @param[in]      fill          Initial value for each element
   */
  Dynamic_Array (size_t length, T fill);

  /**
   * Copy constructor
   *
   * @param[in]     arr         The source array.
   */
  Dynamic_Array (const Dynamic_Array & arr);

  /// Destructor.
  ~Dynamic_Array (void);

  /**
   * Assignment operation
   *
   * @param[in]       rhs      Right-hand side of equal sign
   * @return          Reference to self
   */
  const Dynamic_Array & operator = (const Dynamic_Array & rhs);

  /**
   * Retrieve the maximum size of the array.
   *
   * @return          The maximum size
   */
  size_t max_size (void) const;

  /**
   * Set a new size for the array. If \a new_size is less than the current
   * size, then the array is truncated. If \a new_size if greater then the
   * current size, then the array is made larger and the new elements are
   * not initialized to anything. If \a new_size is the same as the current
   * size, then nothing happens.
   *
   * The array's original contents are preserved regardless of whether the 
   * array's size is either increased or decreased.
   *
   * @param[in]       new_size              New size of the array
   */
  void resize (size_t new_size);


private:

  /// Maximum size of the array.
  size_t max_size_;
};

#include "Dynamic_Array.inl"
#include "Dynamic_Array.cpp"

#endif   // !defined _ARRAY_H_
