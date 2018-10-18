// @author G. Hemingway, copyright 2018 - All rights reserved
//
#ifndef ARRAYLIST_CPP
#define ARRAYLIST_CPP

#include <algorithm>
#include <stdexcept>

/**
 * Default constructor
 */
template <typename T>
ArrayList<T>::ArrayList()
    : mArray(nullptr)
    , mSize(0)
    , mCapacity(0)
{
}

/**
 * Creates an ArrayList of the provided size and fills it with the provided
 * value.
 * @param size size of the ArrayList to create
 * @param value value used to fill the ArrayList
 */
template <typename T>
ArrayList<T>::ArrayList(const uint32_t& size, const T& value)
    : mArray(new T[size])
    , mSize(size)
    , mCapacity(size)
{
    // If we got here, the allocation via "new T[size]" worked.
    try {
        // Fill array with those values - could possibly throw exception
        for (uint32_t i = 0; i < size; ++i) {
            mArray[i] = value;
        }
    } catch (const std::exception& ex) {
        // This will deallocate the memory allocated during MIL
        mArray.reset();
        throw ex;
    }
}

/**
 * Creates a deep copy of the provided ArrayList
 * @param src ArrayList to copy
 */
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& src)
    : mArray(new T[src.mCapacity])
    , mSize(src.mSize)
    , mCapacity(src.mCapacity)
{
    // If we got here, the allocation via "new T[src.mCapacity]" worked.
    try {
        // Fill array with those values - could possibly throw exception
        for (uint32_t i = 0; i < mSize; ++i) {
            mArray[i] = src[i];
        }
    } catch (const std::exception& ex) {
        // This will deallocate the memory allocated during MIL
        mArray.reset();
        throw ex;
    }
}

/**
 * Makes *this a deep copy of the provided ArrayList.
 * @param src ArrayList to copy
 * @return *this for chaining
 */
template <typename T> ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& src)
{
    // To make strong exception safe, use copy-and-swap idiom.
    // Might not be as memory efficient but uses std::swap nothrow guarantee.
    ArrayList<T> temp(src);
    mArray.swap(temp.mArray);
    std::swap(temp.mSize, mSize);
    std::swap(temp.mCapacity, mCapacity);
    return *this;
}

/**
 * Adds the provided element to the end of this ArrayList.
 * @param value value to add
 */
template <typename T> const uint32_t& ArrayList<T>::add(const T& value)
{
    // Just call to add(index, value)
    return add(mSize, value);
}

/**
 * Inserts the specified value into this ArrayList at the specified index.
 * The object is inserted before any previous element at the specified
 * location. If this ArrayList needs to be enlarged, default values are used
 * to fill the gaps up to mSize.
 * @param index location at which to insert the new element
 * @param value the element to insert
 */
template <typename T> const uint32_t& ArrayList<T>::add(const uint32_t& index, const T& value)
{
    // Let's figure out the new size
    const uint32_t newSize = index <= mSize ? mSize + 1 : index + 1;

    // Determine eventual capacity
    uint32_t newCapacity = mCapacity;
    if (newSize > mCapacity) {
        newCapacity = mCapacity == 0 ? 1 : 2 * mCapacity;
        // Keep doubling until newCapacity is greater than the newSize
        while (newSize > newCapacity) {
            newCapacity *= 2;
        }
    }

    // Use a local ScopedArray to manage the new array - will automatically deallocate if throw or
    // exit
    ScopedArray<T> newArray(new T[newCapacity]);
    // Copy existing items into new array
    for (uint32_t i = 0; i < mSize; ++i) {
        newArray[i] = mArray[i];
    }

    // Is index >= mSize (i.e. beyond all existing values) - need to default fill
    if (index >= mSize) {
        for (uint32_t i = mSize; i < index; ++i) {
            newArray[i] = T();
        }
        // Otherwise, just push everything from index to size back one spot
    } else {
        for (uint32_t i = mSize; i > index; --i) {
            newArray[i] = newArray[i - 1];
        }
    }
    // Set new value
    newArray[index] = value;

    // Setup member variables - use swap for exception safety
    mArray.swap(newArray);
    mCapacity = newCapacity;
    mSize = newSize;
    return mCapacity;
}

/**
 * Clears this ArrayList, leaving it empty.
 */
template <typename T> void ArrayList<T>::clear()
{
    // Simplest way of clearing.  May also "zero" out the entire capacity
    mArray.reset();
    mCapacity = 0;
    mSize = 0;
}

/**
 * Returns a const T & to the element stored at the specified index.
 * If the index is out of bounds, std::out_of_range is thrown with the index
 * as its message.
 * @param index the desired location
 * @return a const T & to the desired element.
 */
template <typename T> const T& ArrayList<T>::get(const uint32_t& index) const
{
    if (index >= mSize) {
        throw std::out_of_range(std::to_string(index));
    }
    return mArray[index];
}

/**
 * Returns a T & to the element stored at the specified index.
 * If the index is out of bounds, std::out_of_range is thrown with the index
 * as its message.
 * @param index the desired location
 * @return a T & to the desired element.
 */
template <typename T> T& ArrayList<T>::get(const uint32_t& index)
{
    if (index >= mSize) {
        throw std::out_of_range(std::to_string(index));
    }
    return mArray[index];
}

/**
 * Returns a T & to the element stored at the specified index.
 * No range checking is performed.
 * @param index the desired location
 * @return a T & to the desired element.
 */
template <typename T> T& ArrayList<T>::operator[](const uint32_t& index)
{
    return const_cast<T&>(static_cast<const ArrayList<T>*>(this)->operator[](index));
}

/**
 * Returns a const T & to the element stored at the specified index.
 * No range checking is performed.
 * @param index the desired location
 * @return a const T & to the desired element.
 */
template <typename T> const T& ArrayList<T>::operator[](const uint32_t& index) const
{
    return mArray[index];
}

/**
 * Empty check.
 * @return True if this ArrayList is empty and false otherwise.
 */
template <typename T> bool ArrayList<T>::isEmpty() const
{
    return mSize == 0;
}

/**
 * Returns iterator to the beginning; in this case, a random access iterator
 * @return an iterator to the beginning of this ArrayList.
 */
template <typename T> ArrayListIterator<T> ArrayList<T>::begin()
{
    return ArrayListIterator<T>(mArray.get());
}

/**
 * Returns the past-the-end iterator of this ArrayList.
 * @return a past-the-end iterator of this ArrayList.
 */
template <typename T> ArrayListIterator<T> ArrayList<T>::end()
{
    return ArrayListIterator<T>(mArray.get() + mSize);
}

/**
 * Returns const iterator to the beginning; in this case, a random access
 * iterator
 * @return an const iterator to the beginning of this ArrayList.
 */
template <typename T> typename ArrayList<T>::const_iterator ArrayList<T>::begin() const
{
    return ArrayListConstIterator<T>(mArray.get());
}

/**
 * Returns the past-the-end const iterator of this ArrayList.
 * @return a past-the-end const iterator of this ArrayList.
 */
template <typename T> typename ArrayList<T>::const_iterator ArrayList<T>::end() const
{
    return ArrayListConstIterator<T>(mArray.get() + mSize);
}

/**
 * Removes an element at the specified location from this ArrayList and
 * returns it. Elements following index are shifted down. If index is out of
 * range, std::out_of_range is thrown with index as its message.
 * @param index the desired location
 * @return a copy of the removed element.
 */
template <typename T> T ArrayList<T>::remove(const uint32_t& index)
{
    if (index >= mSize) {
        throw std::out_of_range(std::to_string(index));
    }

    // Use a local ScopedArray to manage the mutated array - will automatically deallocate if throw
    // or exit
    ScopedArray<T> newArray(new T[mCapacity]);
    // Copy existing items into new array - up to index
    for (uint32_t i = 0; i < index; ++i) {
        newArray[i] = mArray[i];
    }
    // Shift all values above index down one slot
    for (uint32_t i = index; i < mSize - 1; ++i) {
        newArray[i] = mArray[i + 1];
    }

    // Grab the value to be removed and returned
    T value = mArray[index];
    // Swap in the mutated array - for exception safety
    mArray.swap(newArray);
    --mSize;
    return value;
}

/**
 * Sets the element at the desired location to the specified value. If index
 * is out of range, std::out_of_range is thrown with index as its message.
 * @param index the location to change
 * @param value the new value of the specified element.
 */
template <typename T> void ArrayList<T>::set(const uint32_t& index, const T& value)
{
    if (index >= mSize) {
        throw std::out_of_range(std::to_string(index));
    }
    mArray[index] = value;
}

/**
 * Returns the size of this ArrayList.
 * @return the size of this ArrayList.
 */
template <typename T> uint32_t ArrayList<T>::size() const
{
    return mSize;
}

#endif // ARRAYLIST_CPP
