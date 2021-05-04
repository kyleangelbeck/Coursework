// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return size_;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
    // If Stack is empty, throw error
    if(size() == 0) {
        //TODO: Implement custom exception
        throw std::out_of_range("The stack is empty");
    }
    
    return data_[size()-1];
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    return size() == 0;
}
