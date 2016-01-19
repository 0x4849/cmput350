/*
#---------------------------------------------------------------
# Assignment:           01
# Exercise:             2
# Due Date:             September 30, 2015
# Lab Section:          D01
# Name:                 Brad Harrison
# Instructor:           Nicolas Barriga
# Course:               CMPUT 350
#---------------------------------------------------------------

#---------------------------------------------------------------
# String.cpp implementation of String.h string class.
#
#
#---------------------------------------------------------------
*/
#include "String.h"
#include <string.h>
#include <iostream>
using namespace std;
typedef unsigned char uint1;

/* This constructor allocates enough memory for a SharedData structure that
   the shared pointer can point to and then it allocates enough memory
   so that the shared->data can copy over the string that was passed in. */
String::String(const char *p)
{
  shared = new struct SharedData;
  int bytesToAllocate = strlen(p)+1;
  shared->data = new char[bytesToAllocate];
  memcpy(shared->data,p,bytesToAllocate);

  /* Set the number of non-0 characters in string to the string length */
  shared->n = strlen(p);
  /* Set the count of the number of objects using this shared object to 1 */
  shared->count = 1;
 
}

/* This destructor will delete the string as well as the pointer to the
   shared object if the number of objects using the shared object becomes
   zero */
String::~String()
{
  shared->count --;
  if (shared->count == 0)
  {
    // Free the String
    delete [] shared->data;
    
    //Free the Pointer to the Shared Object
    delete shared;
    shared = nullptr;
  }
}

/* CC That simply re-points rhs shared to lhs shared after incrementing
   the count of the shared object */
String::String(const String &x)
{  
  if (x.shared == 0)
  {
    delete shared;
    shared = 0;
    return;
  }

  /* increment the RHS shared count and re-point shared to RHS shared
     Note : this will trigger a segmentation fault for String a = a;
     for some undefined variable a, but catching segmentation faults
     is probably outside the scope of this exercise */
  x.shared->count += 1;
  shared = x.shared;

}

/* AO that will delete the shared object if and only if the count of the LHS
   shared object is to become zero after performing LHS = RHS
   Also, it will re-point lhs shared to rhs shared. */
String& String::operator=(const String &x)
{
  if (this == &x)
  {
    return *this;
  }
  
  this->~String();

  if (x.shared == 0)
  {
    delete shared;
    shared = nullptr;
  }
  
  else
  {
    x.shared->count += 1;
    shared = x.shared;
  }
  return *this;
}

/* Return the number of non zero characters in the string of the shared
   object */
size_t String::size() const
{
  return shared->n;
}

/* Return the number of objects that are currently using this particular
   shared object */
size_t String::ref_count() const
{
  return shared->count;
}

/* Return the string that is shared inside of the shared object */
const char * String::cstr() const
{
  return shared->data;
}


