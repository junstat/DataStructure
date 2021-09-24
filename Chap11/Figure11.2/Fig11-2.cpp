/*-- Class AddressCounter --------------------------------------------------
             Models occurrences of IP addresses in a login file.
 -------------------------------------------------------------------------*/

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class AddressCounter
{
public:
  AddressCounter();

  void read(istream &in);

  void print(ostream &out) const;

  void tally();

  bool operator==(const AddressCounter &addr);

private:
  string myAddress;
  int myCount;
};

inline AddressCounter::AddressCounter()
    : myCount(0)
{}

inline void AddressCounter::read(istream &in)
{
  in >> myAddress;
  myCount = 1;
}

inline void AddressCounter::print(ostream &out) const
{
  out << left << setw(16) << myAddress << "\t occurs " << myCount << " times\n";
}

inline void AddressCounter::tally()
{
  myCount++;
}

inline bool AddressCounter::operator==(const AddressCounter &addr)
{
  return myAddress == addr.myAddress;
}

/*--------------------------------------------------------------------------
  Program to read IP addresses from a file and produce a list of distinct
  addresses and a count of how many times each appeared in the file.
 -------------------------------------------------------------------------*/

#include <fstream>
#include <cassert>
#include <list>
#include <algorithm>

int main()
{
  string fileName = "/Users/jun/Documents/Learn/CLinonCode/DataStructure/Chap11/Figure11.2/file11-2.dat";
  ifstream inStream;
  inStream.open(fileName.data());
  assert(inStream.is_open());

  list<AddressCounter> addressList;
  AddressCounter addr;
  while (!inStream.eof())
  {
    addr.read(inStream);

    auto it = find(addressList.begin(), addressList.end(), addr);
    if (it != addressList.end())
      (*it).tally();
    else
      addressList.push_back(addr);
  }

  cout << "\nList of addresses:\n\n";
  for (auto &item: addressList)
    item.print(cout);
}