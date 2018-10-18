// @author G. Hemingway, copyright 2018 - All rights reserved
//
#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include <algorithm>
#include <sstream>
#include <stdexcept>

template <typename T>
LinkedList<T>::LinkedList()
    : mSize(0)
    , mTail(new LinkedListNode<T>())
{
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& src)
    : LinkedList()
{
    LinkedList<T> temp;
    for (const T& item : src)
        temp.add(item);
    swap(temp);
}

template <typename T> LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
    if (this != &rhs) {
        LinkedList<T> temp(rhs);
        swap(temp);
    }
    return *this;
}

template <typename T> LinkedList<T>::~LinkedList() noexcept
{
    while (!isEmpty())
        removeNode(begin());
}

template <typename T> void LinkedList<T>::add(const T& value)
{
    new LinkedListNode<T>(value, mTail->mPrev, mTail.get());
    ++mSize;
}

template <typename T> void LinkedList<T>::add(uint32_t index, const T& value)
{
    if (index < mSize) {
        iterator iter(begin());
        std::advance(iter, index);
        new LinkedListNode<T>(value, iter.mPtr->mPrev, iter.mPtr);
        ++mSize;
    } else {
        LinkedList<T> temp;
        for (uint32_t i(mSize); i < index; ++i) {
            temp.add(T());
        }
        temp.add(value);
        LinkedListNode<T>::link(mTail->mPrev, temp.mTail->mNext);
        LinkedListNode<T>::link(temp.mTail->mPrev, mTail.get());
        LinkedListNode<T>::link(temp.mTail.get(), temp.mTail.get());
        mSize = index + 1;
        temp.mSize = 0;
    }
}

template <typename T> void LinkedList<T>::clear() noexcept
{
    LinkedList<T> temp;
    swap(temp);
}

template <typename T> const T& LinkedList<T>::get(uint32_t index) const
{
    rangeCheck(index);
    const_iterator iter(begin());
    std::advance(iter, index);
    return *iter;
}

template <typename T> T& LinkedList<T>::get(uint32_t index)
{
    return const_cast<T&>(((const LinkedList<T>*)this)->get(index));
}

template <typename T> bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const
{
    return mSize == rhs.mSize && std::equal(begin(), end(), rhs.begin());
}

template <typename T> bool LinkedList<T>::operator!=(const LinkedList<T>& rhs) const
{
    return !(*this == rhs);
}

template <typename T> typename LinkedList<T>::const_iterator LinkedList<T>::begin() const noexcept
{
    return const_iterator(mTail->mNext);
}

template <typename T> typename LinkedList<T>::iterator LinkedList<T>::begin() noexcept
{
    return iterator(mTail->mNext);
}

template <typename T> typename LinkedList<T>::const_iterator LinkedList<T>::end() const noexcept
{
    return const_iterator(mTail.get());
}

template <typename T> typename LinkedList<T>::iterator LinkedList<T>::end() noexcept
{
    return iterator(mTail.get());
}

template <typename T> bool LinkedList<T>::isEmpty() const noexcept
{
    return mSize == 0;
}

template <typename T> void LinkedList<T>::remove(uint32_t index)
{
    rangeCheck(index);
    iterator iter = begin();
    if (index == mSize - 1) {
        iter = iterator(mTail->mPrev);
    } else {
        iter = begin();
        std::advance(iter, index);
    }
    removeNode(iter);
}

template <typename T> void LinkedList<T>::set(uint32_t index, const T& value)
{
    rangeCheck(index);
    iterator iter(begin());
    std::advance(iter, index);
    new LinkedListNode<T>(value, iter.mPtr->mPrev, iter.mPtr->mNext);
    LinkedListNode<T>::link(iter.mPtr, iter.mPtr);
    delete iter.mPtr;
}

template <typename T> uint32_t LinkedList<T>::size() const noexcept
{
    return mSize;
}

template <typename T> void LinkedList<T>::rangeCheck(uint32_t index) const
{
    if (index >= mSize) {
        std::stringstream ss;
        ss << index;
        throw std::out_of_range(ss.str());
    }
}

template <typename T> void LinkedList<T>::removeNode(iterator iter) noexcept
{
    delete iter.mPtr;
    --mSize;
}

template <typename T> void LinkedList<T>::swap(LinkedList<T>& rhs) noexcept
{
    std::swap(mSize, rhs.mSize);
    rhs.mTail.swap(mTail);

    //    LinkedListNode<T>* temp(rhs.mTail.release());
    //    rhs.mTail.reset(mTail.release());
    //    mTail.reset(temp);
}

#endif // LINKED_LIST_CPP
