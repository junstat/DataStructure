//
// @Time   : 2021/9/16 21:54
// @Author : junstat@163.com

#include <iostream>

using namespace std;

#ifndef DLIST
#define DLIST

typedef int ElementType;

class List {
public:
    List(int maxSize = 1024);

    ~List();

    List(const List &origList);

    const List &operator=(const List &rightHandSide);

    bool empty() const;

    void insert(ElementType item, int pos);

    void erase(int pos);

    void display(ostream &out) const;

private:
    int mySize;
    int myCapacity;
    ElementType *myArray;
};

ostream &operator<<(ostream &out, const List);

#endif