#include <iostream>
#include "Point.h"

int main()
{
  const int N = 200;
  Point sum;

  for (int i=0; i < N; ++i) {
    Point a(i,-i);
    sum.add(a);
  }
  sum.print();
  std::cout<<std::endl;
  for (int i=0; i < N; ++i) {
    Point a(i,-i);
    sum.substract(a);
  }
  sum.print();
  std::cout<<std::endl;
  Point b(3,2);
  Point c(b);
  std::cout<<c.equals(b);
  std::cout<<std::endl;
  c.scale(3); 
  std::cout<<c.length();
  std::cout<<std::endl;

  return 0;
}
// output: 
//(19900, -19900)
//(0, 0)
//1
//10.8167

