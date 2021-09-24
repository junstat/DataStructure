//
// @Time   : 2021/9/17 20:49
// @Author : junstat@163.com

#include <iostream>

using namespace std;

#ifndef QUEUE
#define QUEUE

#include "AdditionProblem.h"

const int QUEUE_CAPACITY = 128;
typedef AdditionProblem QueueElement;

class Queue {
public:
    Queue();

    bool empty() const;

    void enqueue(const QueueElement &value);

    void display(ostream &out) const;

    QueueElement front() const;

    void dequeue();

private:
    int myFront, myBack;
    QueueElement myArray[QUEUE_CAPACITY];
};

#endif
