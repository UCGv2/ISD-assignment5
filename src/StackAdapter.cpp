/** Name: Christopher Glenn
 *  vunetid: glennca1
 *  email: christopher.a.glenn@vanderbilt.edu
 *  Honor code: I have neither given nor received unauthorized aid on this assignment.
 *  file: StackAdapter.cpp
 */
#include <stdexcept>

/**
 * Removes the top element from the stack. Throws std::underflow_error if this stack
 * is empty.
 */
template <typename T> void StackAdapter<T>::pop()
{
    if (this->isEmpty()) {
        throw std::underflow_error("Stack is empty");
    } else {
        mContainer.remove(size() - 1);
    }
}

/**
 * Adds value to the top of the stack.
 *
 * @param value the value to add to the stack
 */
template <typename T> void StackAdapter<T>::push(const value_type& value)
{
    mContainer.add(value);
}

/**
 * Returns the size of this stack.
 *
 * @return the number of elements in the stack
 */
template <typename T> uint32_t StackAdapter<T>::size() const noexcept
{
    return mContainer.size();
}

/**
 * Returns a reference to the top of the stack. Throws std::underflow_error if this
 * stack is empty.
 *
 * @return the top-most value in the stack
 */
template <typename T> const typename StackAdapter<T>::value_type& StackAdapter<T>::top() const
{
    if (this->isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return static_cast<const StackAdapter<T>::value_type&>(mContainer.get(size() - 1));
}