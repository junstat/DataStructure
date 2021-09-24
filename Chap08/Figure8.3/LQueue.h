//
// @Time   : 2021/9/18 08:46
// @Author : junstat@163.com

#include <iostream>

using namespace std;

#ifndef LQUEUE
#define LQUEUE

typedef int QueueElement;

class Queue {
public:
    Queue();

    Queue(const Queue &original);

    ~Queue();

    const Queue &operator=(const Queue &rightHandSide);

    bool empty() const;

    void enqueue(const QueueElement &value);

    void display(ostream &out) const;

    QueueElement front() const;

    void dequeue();

private:
    class Node {
    public:
        QueueElement data;
        Node *next;

        Node(QueueElement value, Node *link = nullptr) {
            data = value;
            next = link;
        }
    };

    typedef Node *NodePointer;
    NodePointer myFront, myBack;
};

#endif
