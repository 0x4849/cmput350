#include <iostream>
#include "String.h"
using namespace std;

/* Run various tests to ensure that the code works and that there
   are no memory leaks afterwards by using valgrind --leak-check=full */
int main ( void )
{
  String s("aaa"), t("bbbb");  // construct
  String u = t;                // copy construct

  cout << "t: " << t.cstr() << " " << t.size() << " " << t.ref_count() << endl;
  cout << "u: " << u.cstr() << " " << u.size() << " " << u.ref_count() << endl;
  
  /* Outputs t: bbbb 4 2
     u: bbbb 4 2
  */
  
  u = s;
  t = s;
  String v("cccc");            // construct
  v = s;                       // assign
 

  cout << "s: " << s.cstr() << " " << s.size() << " " << s.ref_count() << endl;
  cout << "t: " << t.cstr() << " " << t.size() << " " << t.ref_count() << endl;
  cout << "u: " << u.cstr() << " " << u.size() << " " << u.ref_count() << endl;
  cout << "v: " << v.cstr() << " " << v.size() << " " << v.ref_count() << endl;

  /* Outputs s: aaa 3 4
     t: aaa 3 4
     u: aaa 3 4
     v: aaa 3 4
  */
  s = v;

  cout << "s: " << s.cstr() << " " << s.size() << " " << s.ref_count() << endl;
  cout << "v: " << v.cstr() << " " << v.size() << " " << v.ref_count() << endl;

  /* Outputs
     s: aaa 3 4
     v: aaa 3 4
  */

  s = s;
  cout << "s: " << s.cstr() << " " << s.size() << " " << s.ref_count() << endl;
  /* Outputs
     s: aaa 3 4
  */

  String z = s;
  cout << "s: " << s.cstr() << " " << s.size() << " " << s.ref_count() << endl;
  cout << "z: " << z.cstr() << " " << z.size() << " " << z.ref_count() << endl;
  cout << "u: " << u.cstr() << " " << u.size() << " " << u.ref_count() << endl;
  cout << "v: " << v.cstr() << " " << v.size() << " " << v.ref_count() << endl;
  cout << "t: " << t.cstr() << " " << t.size() << " " << t.ref_count() << endl;

  /* Outputs s: aaa 3 5
     z: aaa 3 5
     u: aaa 3 5
     v: aaa 3 5
     t: aaa 3 5
  */

  String k("onea");
  s = k;
  cout << "s: " << s.cstr() << " " << s.size() << " " << s.ref_count() << endl;
  cout << "k: " << k.cstr() << " " << k.size() << " " << k.ref_count() << endl;
  cout << "z: " << z.cstr() << " " << z.size() << " " << z.ref_count() << endl;
  cout << "u: " << u.cstr() << " " << u.size() << " " << u.ref_count() << endl;
  cout << "v: " << v.cstr() << " " << v.size() << " " << v.ref_count() << endl;
  cout << "t: " << t.cstr() << " " << t.size() << " " << t.ref_count() << endl;
  /* Outputs s: onea 4 2
     k: onea 4 2
     z: aaa 3 4
     u: aaa 3 4
     v: aaa 3 4
     t: aaa 3 4
  */
  
  s = z;
  
  cout << "s: " << s.cstr() << " " << s.size() << " " << s.ref_count() << endl;
  cout << "k: " << k.cstr() << " " << k.size() << " " << k.ref_count() << endl;
  cout << "z: " << z.cstr() << " " << z.size() << " " << z.ref_count() << endl;
  cout << "u: " << u.cstr() << " " << u.size() << " " << u.ref_count() << endl;
  cout << "v: " << v.cstr() << " " << v.size() << " " << v.ref_count() << endl;
  cout << "t: " << t.cstr() << " " << t.size() << " " << t.ref_count() << endl;
  
  /* Output :
     s: aaa 3 5
     k: onea 4 1
     z: aaa 3 5
     u: aaa 3 5
     v: aaa 3 5
     t: aaa 3 5
  */
  
  k = k;
  cout << "k: " << k.cstr() << " " << k.size() << " " << k.ref_count() << endl;
  // k: onea 4 1

  k = t;
  cout << "s: " << s.cstr() << " " << s.size() << " " << s.ref_count() << endl;
  cout << "k: " << k.cstr() << " " << k.size() << " " << k.ref_count() << endl;
  cout << "z: " << z.cstr() << " " << z.size() << " " << z.ref_count() << endl;
  cout << "u: " << u.cstr() << " " << u.size() << " " << u.ref_count() << endl;
  cout << "v: " << v.cstr() << " " << v.size() << " " << v.ref_count() << endl;
  cout << "t: " << t.cstr() << " " << t.size() << " " << t.ref_count() << endl;
  
  /* Output:
   * s: aaa 3 6
   k: aaa 3 6
   z: aaa 3 6
   u: aaa 3 6
   v: aaa 3 6
   t: aaa 3 6
  */
  String a("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
  s = k = z = u = v = t = a;
 
  cout << "a: " << a.cstr() << " " << a.size() << " " << a.ref_count() << endl;
  cout << "s: " << s.cstr() << " " << s.size() << " " << s.ref_count() << endl;
  cout << "k: " << k.cstr() << " " << k.size() << " " << k.ref_count() << endl;
  cout << "z: " << z.cstr() << " " << z.size() << " " << z.ref_count() << endl;
  cout << "u: " << u.cstr() << " " << u.size() << " " << u.ref_count() << endl;
  cout << "v: " << v.cstr() << " " << v.size() << " " << v.ref_count() << endl;
  cout << "t: " << t.cstr() << " " << t.size() << " " << t.ref_count() << endl;
  
  /* Output:
   * a: bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb 82 7
   s: bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb 82 7
   k: bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb 82 7
   z: bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb 82 7
   u: bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb 82 7
   v: bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb 82 7
   t: bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb 82 7
  */
  
  String g("");
  cout << "g: " << g.cstr() << " " << g.size() << " " << g.ref_count() << endl;
  // g:  0 1
  
  a = g;
  cout << "a: " << a.cstr() << " " << a.size() << " " << a.ref_count() << endl;
  cout << "g: " << g.cstr() << " " << g.size() << " " << g.ref_count() << endl;
  
  //a:  0 2
  //g:  0 2

  a = g = k;
  cout << "a: " << a.cstr() << " " << a.size() << " " << a.ref_count() << endl;
  cout << "g: " << g.cstr() << " " << g.size() << " " << g.ref_count() << endl;
  cout << "k: " << k.cstr() << " " << k.size() << " " << k.ref_count() << endl;
  
  /* Output:
     a: bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb 82 8
     g: bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb 82 8
     k: bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb 82 8
  */
  
  String o("aaa"), p("bbb");
  o = p;
  cout << "o: " << o.cstr() << " " << o.size() << " " << o.ref_count() << endl;
  cout << "p: " << p.cstr() << " " << p.size() << " " << p.ref_count() << endl;
  
  /* Output:
	o: bbb 3 2
	p: bbb 3 2
  */
  
  
  return 0;
}
