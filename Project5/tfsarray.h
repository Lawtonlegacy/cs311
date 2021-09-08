// tsfarray.h
// Robert Lawton
// 10/23/2020
//
// For CS 311 Fall 2020
// Header for Class TFSArray
// Assignment #5 - Templated Frightfully Smart Array Class
// Built off fsarray.h by Glenn Chappell

#ifndef FILE_TFSARRAY_H_INCLUDED
#define FILE_TFSARRAY_H_INCLUDED

#include <cstddef>	 // For std::size_t
#include <algorithm> // For std::max

// ****************************************************************************
// class TFSArray - Class Definition
// ****************************************************************************

// class TFSArray
// Templated Frightfully Smart Array Class
// Resizable, copyable/movable, and exception-safe.
// Invariants:
//		0 <= size <= _capacity.
//		_data points to an array of value_type, allocated with new [],
//		owned by *this, holding _capacity value_type values -- UNLESS
//		_capcity == 0, in which case_data may be nullptr.
// Requirements on Types: None
template <typename Val>
class TFSArray {

// ***** TFSArray: Types *****
public:

	// value_type: type of each item in the array.
	using value_type = Val;

	// size_type: type of size and an index into an array.
	using size_type = std::size_t;

	// iterator: type of a random-access iterator that
	// allows modification of item it references.
	using iterator = value_type*;

	// const_iterator: type of random access iterator that
	// doesn't allow modification of item it references.
	using const_iterator = const value_type*;

// ***** TFSArray: Internal-use constants *****
private:

	// Capacity of default-constructed object
	enum { DEFAULT_CAP = 16 };

// ***** TFSArray: Constructors, Destructors, and Assignment Operators *****
public:

	// Default constructor and constructor from size
	// Pre: size >= 0
	// Exception neutral, doesn't throw any additional exceptions
	// Strong Guarantee
	explicit TFSArray(size_type size = size_type(0))
		:_capacity(std::max(size, size_type(DEFAULT_CAP))),	
		// _capacity must be declared before _data
		_size(size),
		_data(_capacity == 0 ? nullptr : new value_type[_capacity])
	{}

	// Copy constructor
	// Pre: A valid TFSArray object
	// Exception neutral, doesn't throw any additional exceptions
	// Strong Guarantee
	TFSArray(const TFSArray & other)
		:_capacity(other._capacity),
		_size(other._size),
		_data(new value_type[_capacity])
	{
		try
		{
			std::copy(other.begin(), other.end(), begin());
		}
		catch (...)
		{
			this->~TFSArray();
			throw;
		}
	}

	// Move constructor
	// Pre: A valid TFSArray object
	// No-Throw Guarantee
	TFSArray(TFSArray && other) noexcept
		:_capacity(other._capacity),
		_size(other._size),
		_data(other._data)
	{
		other._size = 0;
		other._data = nullptr;
	}

	// Destructor
	// No-Throw Guarantee
	~TFSArray(){
		delete[] _data;
	}

	// Copy assignment operator
	// Pre: A valid TFSArray object
	// Exception neutral, doesn't throw any additional exceptions
	// Strong Guarantee
	TFSArray& operator=(const TFSArray & other){
		TFSArray copyobject(other);
		swap(copyobject);
		return *this;
	}

	// Move assignment operator
	// Pre: Valid TFSAray object
	// No-Throw Guarantee
	TFSArray& operator=(TFSArray && other) noexcept {
		swap(other);
		return *this;
	}

// ***** TFSArray: General Public Operators *****
public:

	// operator[] - non-const and const
	// Pre: 0 <= index <= _size - 1
	// No-Throw Guarantee
	value_type& operator[](size_type index) noexcept {
		return _data[index];
	}
	const value_type& operator[](size_type index) const noexcept {
		return _data[index];
	}

// ***** TFSArray: General Public Functions *****
public:

	// size
	// No-Throw Guarantee
	size_type size() const noexcept {
		return _size;
	}

	// empty
	// No-Throw Guarantee
	bool empty() const noexcept {
		return size() == size_type(0);
	}

	// resize
	// Pre:  newsize >= 0
	// Exception neutral, doesn't throw any additional exceptions
	// Strong Guarantee
	void resize(size_type newsize) {
		if (newsize > _capacity) {
			_capacity = std::max(2 * _capacity, newsize);
			value_type* temp = new value_type[_capacity];
			try
			{
				std::copy(begin(), end(), temp);
			}
			catch (...)
			{
				delete[] temp;
				throw;
			}
			delete[] _data;
			_data = temp;
		}
		_size = newsize;
	}

	// insert
	// Pre: begin() <= pos <= end()
	// Exception neutral, doesn't throw any additional exceptions
	// Strong Guarantee
	iterator insert(iterator pos, const value_type& item) {
		size_type index = pos - begin();
		resize(_size + 1);
		_data[_size - 1] = item;
		iterator newPos = begin() + index;
		try
		{
			std::rotate(newPos, begin() + _size - 1, end());
		}
		catch (...)
		{
			resize(_size - 1);
			throw;
		}
		return newPos;
	}

	// erase
	// Pre: begin() <= pos <= end()
	// Exception neutral, doesn't throw any additional exceptions
	// Strong Guarantee
	iterator erase(iterator pos) {
		std::rotate(pos, pos + 1, end());
		resize(_size - 1);
		return pos;
	}

	// begin - non-const & const
	// No-Throw Guarantee
	iterator begin() noexcept {
		return _data;
	}
	const_iterator begin() const noexcept {
		return _data;
	}

	// end - non-const & const
	// No-Throw Guarantee
	iterator end() noexcept{
		return begin() + size();
	}

	const_iterator end() const noexcept {
		return begin() + size();
	}

	// push_back
	// Adds item to end of array increasing size by 1.
	// Exception neutral, doesn't throw any additional exceptions
	// Strong Guarantee
	void push_back(const value_type& item) {
		insert(end(), item);
	}

	// pop_back
	// Removes last item from array.
	// Pre: _size > 0.
	// Exception neutral, doesn't throw any additional exceptions
	// Strong Guarantee
	void pop_back() {
		erase(end() - 1);
	}

	// swap
	// Pre: Two valid TFSArray objects
	// No-Throw Guarantee
	void swap(TFSArray & other) noexcept {
		std::swap(_capacity, other._capacity);
		std::swap(_size, other._size);
		std::swap(_data, other._data);
	}

// ***** TFSArray: Data Members *****
private:

	size_type	 _capacity; // Size of the allocated array
	size_type	 _size;		// Size of client's data
	value_type * _data;		// Pointer to the array

}; // End of class TFSArray

#endif // #ifndef FILE_TFSARRAY_H_INCLUDED
