#ifndef _Point_h_
#define _Point_h_

// a point on the integer grid
class Point
{
public:
  // constructor with value (0,0)
  Point();

  // constructor
  Point(int x, int y);

  // copy constructor
  Point(const Point &p);

  // add point componentwise
  void add(const Point &p);

  // substract point componentwise
  void substract(const Point &p);

  // returns true if both points are equal
  bool equals(const Point &p);

  // scale the point components by the given factor
  void scale(int s);

  // return the length of the vector from the origin to the point
  double length() const;

  // print to standard output
  void print() const;
  
private:
  // data
  int _x, _y;
};
#endif
