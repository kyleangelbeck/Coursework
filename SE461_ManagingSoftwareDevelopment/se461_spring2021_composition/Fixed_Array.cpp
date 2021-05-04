// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

//
// Fixed_Array
//
template <typename T, size_t N>
// Dr. Ryan: Shouldn't need the full qualifier here - Base_Array<T>(N) should suffice to call the base constructor.
// Kyle: Fixed
Fixed_Array <T, N>::Fixed_Array (void) : Base_Array<T>(N) {}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr) : Base_Array<T>(arr) {}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr) : Base_Array<T>(N)
{
    // Set array values
    for(int i = 0; i < std::min(N,M); i++) {
        this->data_[i] = arr[i];
    }
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)  : Base_Array<T>(N, fill) {}

//
// ~Fixed_Array
//
// this->data_ gets deleted in Base_Array destructor
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void) {}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	if(this == &rhs) { return *this; }

    // Set array values
    for(int i = 0; i < this->cur_size_; i++) {
        this->data_[i] = rhs[i];
    }

    return *this;
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
    // Do not need check for self assignment since they are templated differently

    // Set array values
    for(int i = 0; i < std::min(N,M); i++) {
        this->data_[i] = rhs[i];
    }

    return *this;
}
