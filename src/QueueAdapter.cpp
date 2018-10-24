/** Name: Christopher Glenn
 *  vunetid: glennca1
 *  email: christopher.a.glenn@vanderbilt.edu
 *  Honor code: I have neither given nor received unauthorized aid on this assignment.
 *  file: QueueAdapter.cpp
 */

/**
 * Removes the front element from this queue. Throws std::underflow_error if this queue
 * is empty.
 */
template <typename T> void QueueAdapter<T>::dequeue()
{
    if (this->isEmpty()) {
        throw std::underflow_error("The queue is empty");
    } else {
        mContainer.remove(0);
    }
}

/**
 * Adds value to the end of this queue.
 *
 * @param
 */
template <typename T> void QueueAdapter<T>::enqueue(const value_type& value)
{
    mContainer.add(value);
}

/**
 * Returns a reference to the front of this queue. Throws std::underflow_error if this
 * queue is empty.
 *
 * @return
 */
template <typename T> const typename QueueAdapter<T>::value_type& QueueAdapter<T>::front() const
{
    if (this->isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return static_cast<const QueueAdapter<T>::value_type&>(mContainer.get(0));
}

/**
 * Returns the size of this queue.
 *
 * @return
 */
template <typename T> uint32_t QueueAdapter<T>::size() const noexcept
{
    return mContainer.size();
}