/*
#---------------------------------------------------------------
# Assignment:           01
# Exercise:             3
# Due Date:             September 30, 2015
# Lab Section:          D01
# Name:                 Brad Harrison
# Instructor:           Nicolas Barriga
# Course:               CMPUT 350
#---------------------------------------------------------------

#---------------------------------------------------------------
# Set.h is the interface of a memory efficient set that uses bitwise
# operations to perform standard functions of a set.
#
#---------------------------------------------------------------
*/
#ifndef Set_h
#define Set_h

#include <iostream>
#include <cstdlib>

// represents a set of integers 0..n-1

class Set
{
public:

  Set(size_t n);                // create empty subset of {0..n-1}
  ~Set();                       // destructor
  Set(const Set &s);            // copy constructor
  Set& operator=(const Set &s); // assignment operator

  void clear();              // empty set
  void complement();         // negate set (x was in set before <=> x is not in set after)
  bool has(size_t x) const;   // return true iff x is element of set (0 <= x < n)
  void add(size_t x);        // add element x to set (0 <= x < n)
  void remove(size_t x);     // remove element x from set (0 <= x < n)

  // add all elements of s to set; pre-cond: s.n == n
  void add(const Set &s);

  // remove all elements of s from set; pre-cond: s.n == n
  void remove(const Set &s);
  
  // return maximum number of elements
  size_t get_n() const { return n; }
  
  // print elements to output stream os (default std::cout) like so: 
  // [ 1 2 4 5 ]
  // for set {1,2,4,5} (no extra spaces, no newline characters)
  void print(std::ostream &os = std::cout) const;
  
  
private:
  /* Operation that helps understanding which value to put in
   new bits[X] where X is the value we get from this method. */
  int getNumberToAllocate(size_t n);
  /* This operation updates the array index and remainder bit, which
   is useful for knowing which array index we should be interested
   for value x, and how many places we should shift 1 to the left
   (remainder bit) to the target the correct bit in the correct location */
  void calculateArrayIndexAndRemainder(int &arrayIndex, int &remainderBit, size_t x);
  int *bits;  // array of integers storing bits (x in set <=> bit x = 1)

  size_t n;   // max. number of elements (elements are 0,1,...n-1)
  size_t a;   // number of allocated ints
};
  
#endif
