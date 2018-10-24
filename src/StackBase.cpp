/** Name: Christopher Glenn
 *  vunetid: glennca1
 *  email: christopher.a.glenn@vanderbilt.edu
 *  Honor code: I have neither given nor received unauthorized aid on this assignment.
 *  file: StackBase.cpp
 */
#include <stdexcept>

/**
 * Returns true if this stack is empty.
 *
 * @return
 */
template <typename T> bool StackBase<T>::isEmpty() const noexcept
{
    return size() == 0;
}

/**
 * Returns a reference to the top of the stack. Throws std::underflow_error if this
 * stack is empty.
 *
 * @return
 */
template <typename T> T& StackBase<T>::top()
{
    if (isEmpty()) {
        throw std::underflow_error("The stack is empty.");
    } else {
        return const_cast<T&>(static_cast<const StackBase<T>*>(this)->top());
    }
}