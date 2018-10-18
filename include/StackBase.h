// @author G. Hemingway, copyright 2018 - All rights reserved
//
#ifndef STACK_BASE_H
#define STACK_BASE_H

#include <cstdint>

/**
 * An abstract base class for classes implementing the Stack ADT. This class
 * defines the classical interface for stacks.
 */
template <typename T> class StackBase {
public:
    /**
     * Pure virtual destructor.
     */
    virtual ~StackBase() = default;

    /**
     * Returns true if this stack is empty.
     *
     * @return
     */
    bool isEmpty() const noexcept;

    /**
     * Removes the top element from the stack. Throws std::underflow_error if this stack
     * is empty.
     */
    virtual void pop() = 0;

    /**
     * Adds value to the top of the stack.
     *
     * @param
     */
    virtual void push(const T& value) = 0;

    /**
     * Returns the size of this stack.
     *
     * @return
     */
    virtual uint32_t size() const noexcept = 0;

    /**
     * Returns a reference to the top of the stack. Throws std::underflow_error if this
     * stack is empty.
     *
     * @return
     */
    virtual const T& top() const = 0;

    /**
     * Returns a reference to the top of the stack. Throws std::underflow_error if this
     * stack is empty.
     *
     * @return
     */
    T& top();
};

#include "../src/StackBase.cpp"

#endif // STACK_BASE_H
