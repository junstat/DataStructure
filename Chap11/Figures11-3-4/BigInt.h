/*---- BigInt.h ----------------------------------------------------------

  This  header file defines the data type BigInt for processing
  integers of any size.
  Basic Operations are:
      Constructor
      +:          Addition operator
      read():     Read a BigInt object
      display():  Display a BigInt object
      <<, >> :    Input and output operators
 ------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>    // setfill(), setw()
#include <list>

using namespace std;

#ifndef BIGINT
#define BIGINT

const int DIGITS_PER_BLOCK = 3;

class BigInt
{
public:
  // Constructor
  // Let the list<short int> constructor take care of this.

  void read(istream &in);

  void display(ostream &out) const;

  BigInt operator+(BigInt addend2);

private:
  list<short int> myList;
};

inline istream &operator>>(istream &in, BigInt &number)
{
  number.read(in);
  return in;
}

inline ostream &operator<<(ostream &out, const BigInt &number)
{
  number.display(out);
  return out;
}

#endif
