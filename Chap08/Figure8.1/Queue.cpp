//
// @Time   : 2021/9/17 20:49
// @Author : junstat@163.com

#include "Queue.h"

Queue::Queue() : myFront(0), myBack(0) {}

bool Queue::empty() const {
    return (myFront == myBack);
}

void Queue::enqueue(const QueueElement &value) {
    int newBack = (myBack + 1) % QUEUE_CAPACITY;
    if (newBack != myFront) {
        myArray[myBack] = value;
        myBack = newBack;
    } else {
        cerr << "*** Queue full -- can't add new value ***\n"
                "Must increase value of QUEUE_CAPACITY in Queue.h\n";
        exit(1);
    }
}

void Queue::display(ostream &out) const {
    for (int i = myFront; i != myBack; i = (i + 1) % QUEUE_CAPACITY)
        out << myArray[i] << " ";
    cout << endl;
}

QueueElement Queue::front() const {
    if (!empty())
        return (myArray[myFront]);
    else {
        cerr << "*** Queue is empty -- returning garbage value ***\n";
        QueueElement garbage;
        return garbage;
    }
}

void Queue::dequeue() {
    if (!empty())
        myFront = (myFront + 1) % QUEUE_CAPACITY;
    else {
        cerr << "*** Queue is empty -- "
                "can't remove a value ***\n";
        exit(1);
    }
}