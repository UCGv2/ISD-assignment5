// @author G. Hemingway, copyright 2018 - All rights reserved
//
#ifndef LINKEDLISTITER_CPP
#define LINKEDLISTITER_CPP

#include <algorithm>
#include <stdexcept>

template <typename T>
bool LinkedListIterator<T>::operator==(const LinkedListIterator<T>& rhs) const noexcept
{
    return mPtr == rhs.mPtr;
}

template <typename T>
bool LinkedListIterator<T>::operator!=(const LinkedListIterator<T>& rhs) const noexcept
{
    return !(*this == rhs);
}

template <typename T> T& LinkedListIterator<T>::operator*() const
{
    return mPtr->mItem;
}

template <typename T> T* LinkedListIterator<T>::operator->() const
{
    return &mPtr->mItem;
}

template <typename T> LinkedListIterator<T>& LinkedListIterator<T>::operator++()
{
    mPtr = mPtr->mNext;
    return *this;
}

template <typename T> const LinkedListIterator<T> LinkedListIterator<T>::operator++(int)
{
    LinkedListIterator<T> rValue(*this);
    ++*this;
    return rValue;
}

template <typename T> LinkedListIterator<T>& LinkedListIterator<T>::operator--()
{
    mPtr = mPtr->mPrev;
    return *this;
}

template <typename T> const LinkedListIterator<T> LinkedListIterator<T>::operator--(int)
{
    LinkedListIterator<T> rValue(*this);
    --*this;
    return rValue;
}

template <typename T>
LinkedListIterator<T>::LinkedListIterator(LinkedListNode<T>* ptr)
    : mPtr(ptr)
{
}

#endif // LINKEDLISTITER_CPP
