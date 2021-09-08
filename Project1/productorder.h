// productorder.h
// Robert Lawton
// 02 Sep 2020

// CS 311 Fall 2020
// Header for class ProductOrder

#ifndef FILE_PRODUCTORDER_H_INCLUDED
#define FILE_PRODUCTORDER_H_INCLUDED

#include <string> 

// *********************************************************************
// class ProductOrder - Class definition
// *********************************************************************'

// class ProductOrder
// Invariants: _quantityOrdered >= 0
class ProductOrder {

// ***** ProductOrder: Constructors, destructor, and assignment operators *****
public:

	// Default Constructor
	// Sets product name to UNSPECIFIED, and quantity ordered to 0
	ProductOrder(){
		_name = "UNSPECIFIED";
		_quantityOrdered = 0;
	}

	// 2-parameter Constructor
	// Sets data members to given parameters
	ProductOrder(std::string name, int inventory){
		_name = name;
		if (inventory >= 0)
			_quantityOrdered = inventory;
		else
			_quantityOrdered = 0;
	}
		
	// Big 5: use automatically generated versions
	ProductOrder(const ProductOrder & other) = default;
	ProductOrder(ProductOrder && other) = default;
	~ProductOrder() = default;
	ProductOrder & operator=(const ProductOrder& other) = default;
	ProductOrder & operator=(ProductOrder && other) = default;
	
// ***** ProductOrder: General public operators *****
public:

	// getName
	// Returns name of product
	std::string getName() const;

	// getNumber
	// Returns number of products ordered
	int getNumber() const;

	// setName
	// Modifies the _name data member
	void setName(const std::string & name);

	// setNumber
	// Modifies the _quantityOrdered data member
	void setNumber(const int& number);

	// empty
	// Returns true if the quantityOrdered is equal to 0
	// Otherwise returns false
	bool empty() const;
	
	// toString
	// Returns a string with the product's name and quantity ordered
	std::string toString() const;


// ***** ProductOrder: Increment & decrement operators *****
public:

	// operator++ (pre)
	// _quantityOrdered increased by 1
	// Return is *this
	ProductOrder & operator++();

	// operator-- (pre)
	// _quantityOrdered decreased by 1
	// Return is *this
	ProductOrder& operator--();

	// operator++ (post)
	// _quantityOrdered increased by 1
	// Return is the original value
	ProductOrder operator++(int dummy);

	// operator-- (post)
	// Return *this if _quantity ordered is 0
	// Otherwise: _quantityOrdered decreased by 1
	// Return is the original value
	ProductOrder operator--(int dummy);

// ***** ProductOrder: Data members *****
private:

	std::string _name; // Product's name
	int _quantityOrdered; // Product's number of items ordered
	
}; // End class ProductOrder



// *********************************************************************
// class ProductOrder - Declarations of associated global operators
// *********************************************************************


// equality (==)
// Checks if two ProductOrders' names and quantity ordered are the same
// Returns true if both are the same
// False otherwise
bool operator==(const ProductOrder& left, const ProductOrder& right);

// inequality (!=)
// Checks if two ProductOrders' names and quantity ordered are not the same.
// Returns true if both are not the same
// False if both names and quantity ordered are the same
bool operator!=(const ProductOrder& left, const ProductOrder& right);


// operator<< (ostream,ProductOrder)
// Prints given ProductOrder object as provided by toString
// Format = "<name> (quantityOrdered)"
// <name> = _name  and quantityOrdered = _quantityOrdered
std::ostream& operator<<(std::ostream& os, const ProductOrder& object);


#endif // !FILE_PRODUCTORDER_H_INCLUDED