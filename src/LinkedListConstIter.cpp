// @author G. Hemingway, copyright 2018 - All rights reserved
//
#ifndef LINKEDLISTCONSTITER_CPP
#define LINKEDLISTCONSTITER_CPP

#include <algorithm>
#include <stdexcept>

template <typename T>
bool LinkedListConstIterator<T>::operator==(const LinkedListConstIterator<T>& rhs) const noexcept
{
    return mPtr == rhs.mPtr;
}

template <typename T>
bool LinkedListConstIterator<T>::operator!=(const LinkedListConstIterator<T>& rhs) const noexcept
{
    return !(*this == rhs);
}

template <typename T> const T& LinkedListConstIterator<T>::operator*() const
{
    return mPtr->mItem;
}

template <typename T> const T* LinkedListConstIterator<T>::operator->() const
{
    return &mPtr->mItem;
}

template <typename T> LinkedListConstIterator<T>& LinkedListConstIterator<T>::operator++()
{
    mPtr = mPtr->mNext;
    return *this;
}

template <typename T> const LinkedListConstIterator<T> LinkedListConstIterator<T>::operator++(int)
{
    LinkedListConstIterator<T> rValue(*this);
    ++*this;
    return rValue;
}

template <typename T> LinkedListConstIterator<T>& LinkedListConstIterator<T>::operator--()
{
    mPtr = mPtr->mPrev;
    return *this;
}

template <typename T> const LinkedListConstIterator<T> LinkedListConstIterator<T>::operator--(int)
{
    LinkedListConstIterator<T> rValue(*this);
    --*this;
    return rValue;
}

template <typename T>
LinkedListConstIterator<T>::LinkedListConstIterator(LinkedListNode<T>* ptr)
    : mPtr(ptr)
{
}

#endif // LINKEDLISTCONSTITER_CPP
