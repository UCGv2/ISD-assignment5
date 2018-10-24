/** Name: Christopher Glenn
 *  vunetid: glennca1
 *  email: christopher.a.glenn@vanderbilt.edu
 *  Honor code: I have neither given nor received unauthorized aid on this assignment.
 *  file: QueueBase.cpp
 */
#include <stdexcept>

/**
 * Returns a reference to the front of this queue. Throws std::underflow_error if this
 * queue is empty.
 *
 * @return the next value from the queue
 */
template <typename T> T& QueueBase<T>::front()
{
    if (isEmpty()) {
        throw std::underflow_error("The queue is empty.");
    } else {
        return const_cast<T&>(static_cast<const QueueBase<T>*>(this)->front());
    }
}

/**
 * Returns true if this queue is empty.
 *
 * @return boolean if the queue is empty
 */
template <typename T> bool QueueBase<T>::isEmpty() const noexcept
{
    return size() == 0;
}