// @author G. Hemingway, copyright 2018 - All rights reserved
//
#ifndef QUEUE_BASE_H
#define QUEUE_BASE_H

#include <cstdint>

/**
 * An abstract base class for classes implementing the Queue ADT. This class
 * defines the classical interface for queues.
 */
template <typename T> class QueueBase {
public:
    /**
     * Pure virtual destructor.
     */
    virtual ~QueueBase() = default;

    /**
     * Removes the front element from this queue. Throws std::underflow_error if this queue
     * is empty.
     */
    virtual void dequeue() = 0;

    /**
     * Adds value to the end of this queue.
     *
     * @param T the vale to add to the queue
     */
    virtual void enqueue(const T& value) = 0;

    /**
     * Returns a reference to the front of this queue. Throws std::underflow_error if this
     * queue is empty.
     *
     * @return the next value from the queue
     */
    virtual const T& front() const = 0;

    /**
     * Returns a reference to the front of this queue. Throws std::underflow_error if this
     * queue is empty.
     *
     * @return the next value from the queue
     */
    T& front();

    /**
     * Returns true if this queue is empty.
     *
     * @return boolean if the queue is empty
     */
    bool isEmpty() const noexcept;

    /**
     * Returns the size of this queue.
     *
     * @return number of elements in the queue
     */
    virtual uint32_t size() const noexcept = 0;
};

#include "../src/QueueBase.cpp"

#endif // QUEUE_BASE_H
