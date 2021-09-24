#include <iostream>

using namespace std;

#ifndef LINKEDLIST
#define LINKEDLIST

typedef int ElementType;

class Node
{
public:
  ElementType data;
  Node *next;

  Node(ElementType value, Node *link = nullptr)
      : data(value), next(link)
  {}
};

typedef Node *NodePointer;

class LinkedList
{
public:
  LinkedList();

  ~LinkedList();

  LinkedList(const LinkedList &origList);

  const LinkedList &operator=(const LinkedList &rightHandSide);

  void insertHead(ElementType value);

  void insertTail(ElementType value);

  int getSize() const;

  bool empty() const;

  void display(ostream &out) const;

  NodePointer listInsert(ElementType data);
  /*-------------------------------------------------------------------------
    (2020年真题) 五、
    将指定值插入到单链表倒数第二个位置上
    Precondition:  None
    Postcondition: 若插入成功，返回指向链表表头的指针，若插入失败，返回nullptr。
   ------------------------------------------------------------------------*/

private:
  NodePointer first;    // points to first node
  int mySize;           // number of nodes
};

ostream &operator<<(ostream &out, const LinkedList &aList);

#endif