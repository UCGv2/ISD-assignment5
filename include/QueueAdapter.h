// @author G. Hemingway, copyright 2018 - All rights reserved
//
#ifndef QUEUE_ADAPTER_H
#define QUEUE_ADAPTER_H

#include "QueueBase.h"

/**
 * Transforms a specific container type into an implementation of the QueueBase
 * interface. This class makes it possible to transform any container class with
 * a specific interface into a queue with the interface of the QueueBase
 * abstract class. This adapter assumes that the parameterizing type has the
 * following properties:
 *   - a public value_type trait corresponding to the type of its elements.
 *   - an add(value_type) method
 *   - a const value_type& get(uint32_t) const method
 *   - a value_type& get(uint32_t) method
 *   - a remove(uint32_t) method
 *   - a uint32_t size() const method
 */
template <typename Container>
class QueueAdapter : public QueueBase<typename Container::value_type> {
public:
    typedef typename Container::value_type value_type;

    /**
     * Removes the front element from this queue. Throws std::underflow_error if this queue
     * is empty.
     */
    virtual void dequeue();

    /**
     * Adds value to the end of this queue.
     *
     * @param
     */
    virtual void enqueue(const value_type& value);

    /**
     * Returns a reference to the front of this queue. Throws std::underflow_error if this
     * queue is empty.
     *
     * @return
     */
    virtual const value_type& front() const;

    /**
     * Returns the size of this queue.
     *
     * @return
     */
    virtual uint32_t size() const noexcept;

private:
    Container mContainer;
};

#include "../src/QueueAdapter.cpp"

#endif // QUEUE_ADAPTER_H
