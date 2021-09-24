#include "LinkedList.h"

int main()
{
  LinkedList root;
  root.insertHead(1);
  root.insertHead(2);
  root.insertHead(3);
  root.insertHead(4);
  root.insertHead(5);
  cout << root;
}