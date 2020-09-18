// msarray.h
// Robert Lawton
// 09 Sep 2020

// CS 311 Fall 2020
// Header for template MSArray
// A moderately smart array

#ifndef FILE_MSARRAY_INCLUDED
#define FILE_MSARRAY_INCLUDED

#include <cstdlib>
#include <algorithm>

// Invariants: _size => 0
// Requirements on Types: ValType requires operators != and <

template <typename ValType>
class MSArray {

	// ***** MSArray: Constructors & Destructor *****
public:

	// Default Constructor
	MSArray() {
		_size = 8;
		_arrayPtr = new ValType[_size];
	}

	// 1-parameter Constructor
	// Pre: size param must be non-negative
	MSArray(const std::size_t size) {
		_size = size;
		_arrayPtr = new ValType[_size];
	}

	// 2-parameter Constructor
	// Pre: size param must be non-negative
	MSArray(const std::size_t & size, const ValType & fill) {
		_size = size;
		_arrayPtr = new ValType[_size];
		std::fill(begin(), end(), fill);
	}


	// Destructor
	~MSArray() {
		delete[] _arrayPtr;
	}


	// Copy Constructor
	// Pre: Valid MSArray Object
	MSArray(const MSArray & other) {
		_size = other.size();
		_arrayPtr = new ValType[_size];
		std::copy(other.begin(), other.end(), begin());
	}

	// Move Constructor
	// Pre: Valid MSArray Object
	MSArray(MSArray && other) noexcept  {
		_size = other._size;
		_arrayPtr = other._arrayPtr;
		other._size = 0;
		other._arrayPtr = nullptr;
	}


// ***** MSArray: Member Types *****
public:

	using value_type = ValType;
	using size_type = std::size_t;


// ***** MSarray: Data Members *****
private:

	// Pointer to first item in array
	ValType *_arrayPtr;

	// Number of items the array holds
	std::size_t _size;


// ***** MSArray: Private Functions *****
private:

	// mswap
	// Pre: Two valid MSArray objects
	void mswap(MSArray & other) {
		std::swap(_size, other._size);
		std::swap(_arrayPtr, other._arrayPtr);
	}


// ***** MSArray: Public Member Functions & Operators *****
public:

	// Copy Assignment Operator
	// Pre: Valid MSArray Object
	MSArray& operator=(const MSArray& rhs) {
		MSArray copy(rhs);
		mswap(copy);
		return *this;
	}

	// Move Assignment Constructor
	// Pre: Valid MSArray Object
	MSArray& operator=(MSArray&& rhs) noexcept {
		mswap(rhs);
		return *this;
	}


	// Bracket operator []
	// Pre: Integer subscript from 0 to size -1, 
	// where size is the number of items in array
	value_type & operator[](const std::size_t & i) const {
		return _arrayPtr[i];
	}

	// size 
	size_type size() const {
		return _size;
	}
	
	// begin 
	value_type * begin() {
		return &_arrayPtr[0];
	}

	// begin const
	const value_type * begin() const {
		return &_arrayPtr[0];
	}

	// end
	value_type * end() {
		return &_arrayPtr[_size];
	}

	// end const
	const value_type* end() const {
		return &_arrayPtr[_size];
	}


}; // End of class MSArray


// ***** Class MSArray: Declaration of associated global operators *****


// Equality operator ==
// Pre: Two objects of class MSArray with the same value types
// Requirements on Types: ValType requires operator !=
template <typename ValType>
bool operator==(const MSArray<ValType> & a, const MSArray<ValType> & b) {
	return std::equal(a.begin(), a.end(), b.begin(), b.end());
}


// Inequality operator !=
// Pre: Two objects of class MSArray with the same value types
// Requirements on Types: ValType requires operator !=
template <typename ValType>
bool operator!=(const MSArray<ValType> & a, const MSArray<ValType> & b) {
	return !(a == b);
}

// Less than operator <
// Pre: Two objects of class MSArray with the same value types
// Requirements on Types: ValType requires operator <
template <typename ValType>
bool operator<(const MSArray<ValType> & a, const MSArray<ValType> & b) {
	return std::lexicographical_compare(a.begin(), a.end(),
										b.begin(), b.end());
}

// Less than or equal to operator <=
// Pre: Two objects of class MSArray with the same value types
// Requirements on Types: ValType requires operator <
template <typename ValType>
bool operator<=(const MSArray<ValType> & a, const MSArray<ValType> & b) {
	return !(a > b);
}

// Greater than operator >
// Pre: Two objects of class MSArray with the same value types
// Requirements on Types: ValType requires operator <
template <typename ValType>
bool operator>(const MSArray<ValType> & a, const MSArray<ValType> & b) {
	return b < a;
}

// Greater than or equal to operator >=
// Pre: Two objects of class MSArray with the same value types
// Requirements on Types: ValType requires operator <
template <typename ValType>
bool operator>=(const MSArray<ValType> & a, const MSArray<ValType> & b) {
	return !(a < b);
}


#endif //#ifndef FILE_MSARRAY_INCLUDED