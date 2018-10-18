// @author G. Hemingway, copyright 2018 - All rights reserved
//
#ifndef STACK_ADAPTER_H
#define STACK_ADAPTER_H

#include "StackBase.h"

/**
 * Transforms a specific container type into an implementation of the StackBase
 * interface. This class makes it possible to transform any container class with
 * a specific interface into a stack with the interface of the StackBase
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
class StackAdapter : public StackBase<typename Container::value_type> {
public:
    typedef typename Container::value_type value_type;

    /**
     * Removes the top element from the stack. Throws std::underflow_error if this stack
     * is empty.
     */
    virtual void pop();

    /**
     * Adds value to the top of the stack.
     *
     * @param value the value to add to the stack
     */
    virtual void push(const value_type& value);

    /**
     * Returns the size of this stack.
     *
     * @return the number of elements in the stack
     */
    virtual uint32_t size() const noexcept;

    /**
     * Returns a reference to the top of the stack. Throws std::underflow_error if this
     * stack is empty.
     *
     * @return the top-most value in the stack
     */
    virtual const value_type& top() const;

private:
    Container mContainer;
};

#include "../src/StackAdapter.cpp"

#endif // STACK_ADAPTER_H
