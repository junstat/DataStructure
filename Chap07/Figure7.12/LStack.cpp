//
// @Time   : 2021/9/17 20:06
// @Author : junstat@163.com

#include "LStack.h"

Stack::Stack() : myTop(0) {}

Stack::Stack(const Stack &original) {
    myTop = nullptr;
    if (!original.empty()) {
        myTop = new Stack::Node(original.top());

        Stack::NodePointer lastPtr = myTop, origPtr = original.myTop->next;

        while (origPtr) {
            lastPtr->next = new Stack::Node(origPtr->data);
            lastPtr = lastPtr->next;
            origPtr = origPtr->next;
        }
    }
}

Stack::~Stack() {
    Stack::NodePointer currPtr = myTop, nextPtr;

    while (currPtr) {
        nextPtr = currPtr->next;
        delete currPtr;
        currPtr = nextPtr;
    }
}

const Stack &Stack::operator=(const Stack &rightHandSide) {
    if (this != &rightHandSide) {
        this->~Stack();
        if (rightHandSide.empty())
            myTop = nullptr;
        else {
            myTop = new Stack::Node(rightHandSide.top());

            // Set pointers to run through the stacks' linked lists
            Stack::NodePointer lastPtr = myTop, rhsPtr = rightHandSide.myTop->next;

            while (rhsPtr) {
                lastPtr->next = new Stack::Node(rhsPtr->data);
                lastPtr = lastPtr->next;
                rhsPtr = rhsPtr->next;
            }
        }
    }
    return *this;
}

bool Stack::empty() const {
    return (myTop == nullptr);
}

void Stack::push(const StackElement &value) {
    myTop = new Stack::Node(value, myTop);
}

void Stack::display(ostream &out) const {
    Stack::NodePointer ptr;
    for (ptr = myTop; ptr != nullptr; ptr = ptr->next)
        out << ptr->data << endl;
}

StackElement Stack::top() const {
    if (!empty())
        return (myTop->data);
    else {
        cerr << "*** Stack is empty "
                " -- returning garbage ***\n";
        StackElement *temp = new (StackElement);
        StackElement garbage = *temp;
        delete temp;
        return garbage;

    }
}

void Stack::pop() {
    if (!empty()) {
        Stack::NodePointer ptr = myTop;
        myTop = myTop->next;
        delete ptr;
    } else
        cerr << "*** Stack is empty -- can't remove a value ***\n";
}
