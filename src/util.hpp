#ifndef _util_hpp_INCLUDED
#define _util_hpp_INCLUDED

#include <vector>

namespace CaDiCaL {

using namespace std;

/*------------------------------------------------------------------------*/

inline double relative (double a, double b) { return b ? a / b : 0; }
inline double percent (double a, double b) { return relative (100 * a, b); }
inline int sign (int lit) { return (lit > 0) - (lit < 0); }

/*------------------------------------------------------------------------*/

bool is_int_str (const char * str);
bool is_double_str (const char * str);
bool has_suffix (const char * str, const char * suffix);

/*------------------------------------------------------------------------*/

// The standard 'Effective STL' way (though not guaranteed) to clear a
// vector and reduce its capacity to zero, thus deallocating all its
// internal memory.  This is quite important for keeping the actual
// allocated size of watched and occurrence lists small particularly during
// bounded variable elimination where many clauses are added and removed.

template<class T> void erase_vector (vector<T> & v) {
  if (v.capacity ()) { vector<T>().swap (v); }
  assert (!v.capacity ());                          // not guaranteed though
}

// The standard 'Effective STL' way (though not guaranteed) to shrink the
// capacity of a vector to its size thus kind of releasing all the internal
// access memory not needed at the moment any more.

template<class T> void shrink_vector (vector<T> & v) {
  if (v.capacity () > v.size ()) { vector<T>(v).swap (v); }
  assert (v.capacity () == v.size ());              // not guaranteed though
}

// Shallow memory usage of a vector.

template<class T> size_t bytes_vector (const vector<T> & v) {
  return sizeof (T) * v.capacity ();
}

/*------------------------------------------------------------------------*/

};

#endif
