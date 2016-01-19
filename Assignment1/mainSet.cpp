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
# mainSet.cpp is the main function of Set.cpp that performs
# a number of tests to ensure that the program is working OK.
#
#---------------------------------------------------------------
*/
#include "Set.h"
using namespace std;

int main()
{
  Set a(64), b(64), c(64);
  Set d(65);
  
  a = b = c;

  a.add(1); a.add(5);
  b.add(3); b.remove(3);
  c.add(4);
  c.add(1); c.add(a);

  c.print(cout); cout << endl;
  /* Output : [ 1 4 5 ] */
  
  Set z(0);
  z.add(5);
  z.add(10);
  z.remove(5);
  z.add(7);
  z.complement();
  z.print(cout); cout << endl;
  /* Output : [ ]
     Nothing crashes.. so works good
  */

  Set g(1);
  g.add(6);
  g.add(7);
  g.add(8);
  g.remove(8);
  g.print(cout); cout << endl;
  /* Output : [ ] */
  /* Probably working as intended.. You can't turn on the 6th bit
     if you only allocated for the first bit. You can only add 0 to this
     set . */

  g.add(0);
  g.print(cout); cout << endl;
  /* Output : [ 0 ] *
   * 0 is now in the set which is the only element possible to be added. */
  
  g.complement();
  g.print(cout); cout << endl;

  /* Output : [  ]
	Now 0 is no longer turned on.
  */
  
  Set k = a;
  k.print(cout); cout << endl;
  /* Output : [ 1 5 ]
     Working as intended..
  */

  
  Set o(2);
  o.add(1);
  o.add(7);
  o.add(8);
  o.print(cout); cout << endl;

  /* Output : [ 1 ]
     Working as intended since we only asked that integers from
     0..1 would be possible when we wrote Set o(2)
  */

  a.print(cout); cout << endl;
  b.print(cout); cout << endl;
  c.print(cout); cout << endl;

  a.complement();
  a.print(cout); cout << endl;
  cout << a.get_n() << endl;
  cout << a.has(1) << endl;
  cout << a.has(63) << endl;

  a.remove(a);
  a.print(cout); cout << endl;
  
  
  /* output:
    Same as normal mainSet.cpp output
	[ 1 5 ]
	[ ]
	[ 1 4 5 ]
	[ 0 2 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 ]
	64
	0
	1
	[ ]

  */
  
  c.clear();
  c.print(cout); cout << endl;
  
  /* Output : [] */
  
  Set p = c;
  p.print(cout); cout << endl;
  
  /* Output : [] */

  b = c;
  b.print(cout); cout << endl;
  /* Output : [] */
}


