//
// @Time   : 2021/9/18 08:46
// @Author : junstat@163.com

#include "LQueue.h"

Queue::Queue() : myFront(nullptr), myBack(nullptr) {}

Queue::Queue(const Queue &original) {
    myFront = myBack = nullptr;
    if (!original.empty()) {
        myFront = myBack = new Queue::Node(original.front());

        Queue::NodePointer origPtr = original.myFront->next;

        while (origPtr) {
            myBack->next = new Queue::Node(origPtr->data);
            myBack = myBack->next;
            origPtr = origPtr->next;
        }
    }
}

Queue::~Queue() {
    Queue::NodePointer prev = myFront, ptr;

    while (prev) {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}

const Queue &Queue::operator=(const Queue &rightHandSide) {
    if (this != &rightHandSide) {
        this->~Queue();
        if (rightHandSide.empty())
            myFront = myBack = nullptr;
        else {
            // copy first node
            myFront = myBack = new Queue::Node(rightHandSide.front());

            // Set pointer to run through rightHandSide's linked list
            Queue::NodePointer rhsPtr = rightHandSide.myFront->next;

            while (rhsPtr) {
                myBack->next = new Queue::Node(rhsPtr->data);
                myBack = myBack->next;
                rhsPtr = rhsPtr->next;
            }
        }
    }
    return *this;
}

bool Queue::empty() const {
    return (myFront == nullptr);
}

void Queue::enqueue(const QueueElement &value) {
    Queue::NodePointer newptr = new Queue::Node(value);
    if (empty())
        myFront = myBack = newptr;
    else {
        myBack->next = newptr;
        myBack = newptr;
    }
}

void Queue::display(ostream &out) const {
    Queue::NodePointer ptr;
    for (ptr = myFront; ptr != nullptr; ptr = ptr->next)
        out << ptr->data << " ";
    out << endl;
}

QueueElement Queue::front() const {
    if (!empty())
        return (myFront->data);
    else {
        cerr << "*** Queue is empty "
                "-- returning garbage ***\n";
        QueueElement *temp = new (QueueElement);
        QueueElement garbage = *temp;
        delete temp;
        return garbage;
    }
}

void Queue::dequeue() {
    if (!empty()) {
        Queue::NodePointer ptr = myFront;
        myFront = myFront->next;
        delete ptr;
        if (myFront == nullptr)  // queue is now empty
            myBack = nullptr;
    } else
        cerr << "*** Queue is empty -- can't remove a value ***\n";
}
