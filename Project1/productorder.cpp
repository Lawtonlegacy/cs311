// productorder.h
// Robert Lawton
// 02 Sep 2020

// CS 311 Fall 2020
// Source for class ProductOrder

#include "productorder.h"
#include <iostream>
#include <string>

// *********************************************************************
// class TimeOfDay - Definitions of member functions
// *********************************************************************

// getName
// (See header for documentation.)
std::string ProductOrder::getName() const {
	std::string name = _name;
	return name;
}

// getNumber
// (See header for documentation.)
int ProductOrder::getNumber() const {
	int number = _quantityOrdered;
	return number;
}

// setName
// (See header for documentation.)
void ProductOrder::setName(const std::string & name) {
	_name = name;
}

// setNumber
// (See header for documentation.)
void ProductOrder::setNumber(const int& number) {
		_quantityOrdered = number;
}

// empty
// (See header for documentation.)
bool ProductOrder::empty() const {
	if (_quantityOrdered == 0)
		return true;
	else
		return false;
}

// toString()
// (See header for documentation.)
std::string ProductOrder::toString() const {
	std::string output = _name + " (" + std::to_string(_quantityOrdered) + ")";
	return output;
}

// *********************************************************************
// class TimeOfDay - Definitions of increment & decrement operators
// *********************************************************************

// Pre-Increment Operator
// (See header for documentation.)
ProductOrder& ProductOrder::operator++() {
	++_quantityOrdered;
	return *this;
}

// Pre-Decrement Operator
// (See header for documentation.)
ProductOrder& ProductOrder::operator--() {
	if (_quantityOrdered > 0)
		--_quantityOrdered;
	return *this;
}

// Post-Increment Operator
// (See header for documentation.)
ProductOrder ProductOrder::operator++(int dummy) {
	auto originalValue = *this;
	_quantityOrdered++;
	return originalValue;

}

// Post-Decrement Operator
// (See header for documentation.)
ProductOrder ProductOrder::operator--(int dummy) {
	if (_quantityOrdered < 1)
		return *this;
	auto originalValue = *this;
	_quantityOrdered--;
	return originalValue;
}

// *********************************************************************
// class ProductOrder - Definitions of associated global operators
// *********************************************************************

// Equality operator
// (See header for documentation.)
bool operator==(const ProductOrder& left, const ProductOrder& right) {
	return (left.getName() == right.getName() &&
		left.getNumber() == right.getNumber());
}

// Inequality operator
// (See header for documentation.)
bool operator!=(const ProductOrder& left, const ProductOrder& right) {
	return !(left == right);
}

// Stream Insertion Operator
// (See header for documentation.)
std::ostream & operator<<(std::ostream& os, const ProductOrder & object) {
	os << object.toString();
	return os;
}