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
# Set.cpp is the implementation of a memory efficient set
# that uses a bit array and bitwise operations to perform
# the functions of a standard set.
#---------------------------------------------------------------
*/

#include "Set.h"
#include <iostream>
#include <cassert>
#include <string.h>

using namespace std;

/* This is used to determine the number of bits per machine architecture
   of one int */
static const int INT_BITS = sizeof(int)*8;
    
/* Constructor that essentially allocates int elements as necessary
   to contain n bits */
Set::Set(size_t n)
{
  a = getNumberToAllocate(n);
 
  /* Allocate the correct number of integers to hold the bits in the Bit Array */
  bits = new int[a]();

  this->n = n;
}

/* Destructor that simply frees the bits array that holds the set */
Set::~Set()
{
  delete [] bits;
  bits = nullptr;
}

/* CC that allocates the number of integers as necessary to hold the number
   of bits needed(n) in the bits array */
Set::Set(const Set &s)
{
  a = s.a;//getNumberToAllocate(s.n);

  /* Allocate the correct number of integers to hold the bits in the Bit Array */
  bits = new int[a]();
  n = s.n;
  /* Once the memory has been allocated, copy the RHS set(s.bits) to the LHS set
     (bits) */
  memcpy(bits,s.bits,a*sizeof(int));
}

/* AO that doesn't delete the LHS -- it simply copies over the RHS set
   over to the LHS set. The reason it doesn't delete is because both
   sets are guaranteed to hold the same number of bytes given that
   the assertion is s.n == n */
Set &Set::operator=(const Set &s)
{
  assert(s.n == n);
  /* Safe guard against LHS object = RHS object */
  if (this == &s)
  {
    return *this;
  }

  n = s.n;
  a = s.a;

  /* Erase the LHS set pointer if the RHS set pointer points to nothing */
  if (s.bits == nullptr)
  {
    delete bits;
    bits = nullptr;
  }

  else
  {
    /* Copy the RHS set to the LHS set */
    memcpy(bits,s.bits,a*sizeof(int));
  }
  
  return *this;
}

/* Clear out the set by setting everything in bits to 0 using memset */
void Set::clear()
{
  memset((int *)bits, 0, a*sizeof(int));
}

/* Take the logical complement of every relevant element in the bit array */
void Set::complement()
{
  if (a == 0) return;
  
  for (int i=0; i < (int) a; i++)
  {
    bits[i] = ~bits[i];
  }
}

/* Determine if the bit array contains a certain element */
bool Set::has(size_t x) const
{
  if (a == 0)
  {
    return 0;
  }
  
  int arrayIndex;
  int remainderBit;
  
  arrayIndex = x/INT_BITS;
  remainderBit = x-arrayIndex*INT_BITS;

  return ((bits[arrayIndex] >> remainderBit) & 1);
 
}

/* Add one element(a number) to the bit array by turning it on if
   the set doesn't currently contain it. */
void Set::add(size_t x)
{
  if (a == 0) return;
  
  int arrayIndex;
  int remainderBit;

  calculateArrayIndexAndRemainder(arrayIndex, remainderBit, x);

  if (has(x))
  {
    return;
  }
  else
  {
    bits[arrayIndex] = bits[arrayIndex] | (1 << (int) remainderBit);
  }
}

/* Remove an element from the set if the set already contains that
   element */
void Set::remove(size_t x)
{
  if (a==0) return;
  
  int arrayIndex;
  int remainderBit;
  
  calculateArrayIndexAndRemainder(arrayIndex, remainderBit, x);
  if (!has(x))
  {
    return;
  }
  else
  {
    bits[arrayIndex] = bits[arrayIndex] & ~(1 << remainderBit);
  }
}

/* Add one entire set of elements to another set by performing
   a logical OR operation on LHS set and RHS set */
void Set::add(const Set &s)
{
  assert(s.n == n);
  if (a == 0) return;
  
  for ( int i = 0; i < (int) a ; i++ )
  {
    bits[i] = bits[i] | s.bits[i];
  }
}

/* Remove an entire set of values from another set by performing
   AND logical complement */
void Set::remove(const Set &s)
{
  assert(s.n == n);
  if (a == 0) return;
  
  for (int i=0; i < getNumberToAllocate(n); i++)
  {
    bits[i] = bits[i] & ~(s.bits[i]);
  }
}

/* Print out the set with one caveat : The set should only contain
   integers from [0..n-1], so we simply do not print out any value
   higher than that(even if the set might technically have that bit
   toggled; the user will only see that it is not in the set.
   Note that if Set(0) is allocated then this implementation assumes
   that nothing can be in the set(including 0).                   */
void Set::print(std::ostream &os) const
{
  os << "[";
  for (int i=0; i < (int) n; i++)
  {
    if ( has(i))
      os << " "<< i;
  }
  os << " ]";
}

/* Run through the entire bits array checking int values from 0..n-1
   and determine if any of these values are in the set. If they are,
   then increment number of elements in the set
   I removed this functionality because it's not required according to prof.
void Set::updateA()
{
  int tempA;
  tempA = 0;
  for (int i=0; i < (int) n; i++)
  {
    if (has(i))
    {
      tempA++;
    }
  }
  a = tempA;
}
*/

/* Operation that helps understanding which value to put in
   new bits[X] where X is the value we get from this method. */
int Set::getNumberToAllocate(size_t n)
{
  int numberToAllocate = (n-1)/INT_BITS;
  return (numberToAllocate +1);
}

/* This operation updates the array index and remainder bit, which
   is useful for knowing which array index we should be interested
   for value x, and how many places we should shift 1 to the left
   (remainder bit) to the target the correct bit in the correct location */
void Set::calculateArrayIndexAndRemainder(int &arrayIndex, int &remainderBit, size_t x)
{
  arrayIndex = x/INT_BITS;
  remainderBit = x-arrayIndex*INT_BITS;
}
