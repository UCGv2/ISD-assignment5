// @author G. Hemingway, copyright 2018 - All rights reserved
//
#ifndef LINKED_LIST_NODE_CPP
#define LINKED_LIST_NODE_CPP

template <typename T>
LinkedListNode<T>::LinkedListNode(const T& item)
    : mItem(item)
    , mPrev(this)
    , mNext(this)
{
}

template <typename T> LinkedListNode<T>::~LinkedListNode() noexcept
{
    link(mPrev, mNext);
}

template <typename T>
LinkedListNode<T>::LinkedListNode(const T& item, LinkedListNode<T>* prev, LinkedListNode<T>* next)
    : mItem(item)
    , mPrev(prev)
    , mNext(next)
{
    link(mPrev, this);
    link(this, mNext);
}

template <typename T>
void LinkedListNode<T>::link(LinkedListNode<T>* first, LinkedListNode<T>* second) noexcept
{
    first->mNext = second;
    second->mPrev = first;
}

#endif // LINKED_LIST_NODE_CPP
