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
size_t Queue <T>::size (void) const
{
    return size_;
}

//
// is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
    return size() == 0;
}
