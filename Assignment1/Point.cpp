/*
  #---------------------------------------------------------------
  # Assignment:           01
  # Exercise:             1
  # Due Date:             September 30, 2015
  # Lab Section:          D01
  # Name:                 Brad Harrison
  # Instructor:           Nicolas Barriga
  # Course:               CMPUT 350
  #---------------------------------------------------------------

  #---------------------------------------------------------------
  # Point.cpp implementation for given Point.H and PointMain.cpp files
  #
  #
  #---------------------------------------------------------------
*/
#include "Point.h"
#include <math.h>
#include <iostream>
using namespace std;

// constructor gives vector value (0,0)
Point::Point(void)
{
  _x = 0;
  _y = 0;
}

// constructor gives vector value (x,y)
Point::Point(int x, int y)
{
  _x = x;
  _y = y;
}

// copy constructor
Point::Point(const Point &p)
{
  _x = p._x;
  _y = p._y;
}

// add point componentwise
void Point::add(const Point &p)
{
  _x += p._x;
  _y += p._y;
}

// substract point componentwise
void Point::substract(const Point &p)
{
  _x -= p._x;
  _y -= p._y;

}

// returns true if both points are equal
bool Point::equals(const Point &p)
{
  return ((_x == p._x) && (_y == p._y));

}

// scale the point components by the given factor
void Point::scale(int s)
{
  _x *= s;
  _y *= s;

}

// return the length of the vector from the origin to the point
double Point::length() const
{
  return sqrt((double) _x*_x + _y*_y);

}

// print to standard output
void Point::print() const
{
  cout << "(" << _x << ", " << _y << ")";
}
