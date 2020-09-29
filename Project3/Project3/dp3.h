// dp3.h
// Robert Lawton
// 2020-09-17
//
// For CS 311 Fall 2020
// Header for Project 3 functions

#ifndef FILE_DP3_H_INCLUDED
#define FILE_DP3_H_INCLUDED

#include "llnode.h"    // For LLNode
#include <stdexcept>   // For std::out_of_range
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function



// lookup
// Searches through linked list returning _data from
// the node that corresponds to index
// Pre: Nonnegative index & list 
// Requirements on Type: None
template <typename ValueType>
ValueType lookup(const LLNode<ValueType>* head,
    std::size_t index)
{
    while (true) {
        if (head == nullptr)
            throw std::out_of_range("Index out of range," 
                "cannot be negative or bigger than size.");

        if (index == 0)
            return head->_data;

        head = head->_next;
        --index;
    }

}


// Implementation in source file
// didItThrow
// Function that throws the same exception as the function passed.
// If the function passed throws an exception, threw is set to true.
void didItThrow(const std::function<void()>& ff,
    bool& threw);

// checkSorted
// Takes FDIter iterators as params and processes a range of data.
// Returns true if range is in ascending order by <. False othewise.
// Pre: first and last iterator params must specify a range.
//      FDIter first < FDIter last
// Requirements on Type: FDIter must be comparable by <
template <typename FDIter>
bool checkSorted(FDIter first,
    FDIter last)
{
    if (first == last)
        return true;

    FDIter location = first;
    FDIter next = location;
    ++next;

    while (next != last) {
        if (*next < *location)
            return false;
        ++location;
        ++next;
    }

    return true;

}


// Implementation in source file
// Recursive function that finds the greatest common denominator (GCD)
// between two integers.
// Pre: Two nonnegative integers. ONLY one integer can be zero at anytime.
int gcd(int a,
    int b);


#endif  //#ifndef FILE_DP3_H_INCLUDED