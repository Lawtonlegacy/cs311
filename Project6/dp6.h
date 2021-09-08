// dp6.h
// Robert Lawton, Gannon Higgins, Andrew Player
// 11/1/2020
//
// For CS 311 Fall 2020
// Header for Project 6: Linked Lists Exercises

#ifndef FILE_DP6_H_INCLUDED
#define FILE_DP6_H_INCLUDED

#include "llnode2.h"	// Linked List node by Chappell
#include <memory>		// For std::unique_ptr
#include <functional>	// For std::function
#include <utility>		// For std::pair, std::make_pair


// **********************************************************************
//					EXERCISE A - Reversing a Linked List
// **********************************************************************


// reverseList
// Efficient reversing function for a Linked List of LLNode2
// Pre: Valid LLNode2 unique pointer
// No Throw Guarantee
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>> & head){
	std::unique_ptr<LLNode2<ValType>> newHead(nullptr);
	std::unique_ptr<LLNode2<ValType>> oldHead(nullptr);

	while (head != nullptr){
		oldHead = std::move(head->_next);
		head->_next = std::move(newHead);
		newHead = std::move(head);
		head = std::move(oldHead);
	}
	head = std::move(newHead);
}

// **********************************************************************
//				EXERCISE B - Associative Dataset Class Template
// **********************************************************************


// class LLMap
// Templated linked list map
// Invariants:
//	   _head is a unique_ptr to the start of a linked list or a nullptr
// Requirements on Types:
//     KeytType must have a copy constructor and a destructor.
//	   DataType must havea  copy constructor and a destructor.
template <typename KeyType, typename DataType>
class LLMap {

// ***** LLMap: Types *****
public:

	// key_type: type of key items
	using key_type = KeyType;

	// data_type: type of data items
	using data_type = DataType;

// ***** LLMap: Data Members *****
private:

	std::unique_ptr<LLNode2<std::pair<key_type, data_type>>> _head;

// ***** LLMap: Constructors, Destructors *****
public:

	// Default constructor
	// Creates an empty data set
	// Pre: None
	// Exception neutral, doesn't throw any additional exceptions
	// Strong Guarantee
	LLMap() : _head(nullptr){}

	// Copy Constructor
	LLMap(const LLMap & other) = delete;

	// Move Constructor
	LLMap(LLMap && other) = delete;


	// Destructor
	// No Throw Guarantee
	~LLMap(){}

	// Copy Assignment Operator
	LLMap & operator=(const LLMap & other) = delete;

	// Move Assignment Operator
	LLMap & operator=(const LLMap && other) = delete;


// ***** LLMap: Public Member Functions *****
public:

	// size
	// Returns an integer of appropriate type 
	// giving the number of key-value pairs in LLMap
	// No Throw Guarantee
	size_t size() const{
		auto temp = _head.get();
		std::size_t size = 0;
		while (temp){
			++size;
			temp = temp->_next.get();	
		}
		return size;
	}

	// empty
	// Returns a bool indicating if there are no key-balue pairs in LLMap
	// Pre: A LLMap object
	// No Throw Guarantee
	bool empty() const{
		if (_head == nullptr) return true;
		return false;
	}

	// find and const find
	// Returns a const pointer to value of the key given if the 
	// key is in dataset, otherwise returned pointer is a nullptr
	// Pre: nullptr terminated LLMap object
	// No Throw Guarantee
	data_type* find(const key_type & key){
		auto search = _head.get();
		while (search){
			if (search->_data.first == key) return &(search->_data.second);
			search = search->_next.get();
		}
		return nullptr;
	}

	const data_type* find(const key_type & key) const{
		auto search = _head.get();
		while (search){
			if (search->_data.first == key) return &(search->_data.second);
			search = search->_next.get();
		}
		return nullptr;
	}

	// insert
	// Inserts the key-value pair if key is not already in dataset.
	// Replaces an existing key-value pair with that given.
	// Pre: nullptr terminated LLMap object
	// Exception neutral
	// Strong Guarantee
	void insert(key_type key, data_type value){
		auto search = find(key);
		if (search){
			*search = value;
			return;
		}
		push_front(_head, std::make_pair(key, value));
	}

	// erase
	// Removes a key-value pair in the dataset if key is found
	// Pre: nullptr terminated LLMap object
	// No-Throw Guarantee
	void erase(key_type key){
		auto current = _head.get();
		auto previous = _head.get();
		while (current) {
			if (current->_data.first == key) {
				std::swap(previous->_next, current->_next);
				current->_next = nullptr;
				current = nullptr;
			} else {
				previous = current;
				current = current->_next.get();
			}
		}
	}

	// traverse
	// Calls the function to every object in LLMap
	// Pre: func takes two parameters and returns nothing.
	// Basic Guarantee
	void traverse(std::function<void(key_type, data_type)> func) const{
		auto current = _head.get();
		while (current){
			func(current->_data.first, current->_data.second);
			current = current->_next.get();
		}
	}

}; // End of class LLMap


#endif // #ifndef FILE_DP6_H_INCLUDED