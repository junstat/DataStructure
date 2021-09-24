//
// @Time   : 2021/9/19 15:15
// @Author : junstat@163.com

#include <iostream>
#include <cassert>

#ifndef DSTACKT
#define DSTACKT

template<typename StackElement>
class Stack {
public:
    Stack(int numElements = 128);

    Stack(const Stack<StackElement> &original);

    ~Stack();

    const Stack<StackElement> &operator=(const Stack<StackElement> &rightHandSide);

    bool emmpty() const;

    void push(const StackElement &value);

    void display(ostream &out) const;

    StackElement top() const;

    void pop();

private:
    int myCapacity, myTop;
    StackElement *myArray;
};

#include <new>

template<typename StackElement>
Stack<StackElement>::Stack(int numElements) {
    assert (numElements > 0);
    myCapacity = numElements;

    myArray = new(nothrow) StackElement[myCapacity];
    if (myArray)
        myTop = -1;
    else {
        cerr << "Inadequate memory to allocate stack\n"
                " -- termininating execution\n";
        exit(1);
    }
}

template<typename StackElement>
Stack<StackElement>::Stack(const Stack<StackElement> &original)
        :myCapacity(original.myCapacity), myTop(original.myTop) {
    myArray = new(nothrow) StackElement[myCapacity];
    if (myArray)
        for (int pos = 0; pos <= myTop; pos++)
            myArray[pos] = original.myArray[pos];
    else {
        cerr << "*Inadequate memory to allocate stack ***\n";
        exit(1);
    }
}

template<typename StackElement>
inline Stack<StackElement>::~Stack() {
    delete[] myArray;
}

template<typename StackElement>
const Stack<StackElement> &Stack<StackElement>::operator=(const Stack<StackElement> &rightHandSide) {
    if (this != &rightHandSide) {
        if (myCapacity != rightHandSide.myCapacity) {
            delete[] myArray;

            myCapacity = rightHandSide.myCapacity;
            myArray = new StackElement[myCapacity];

            if (myArray) {
                cerr << "*** Inadequate memory ***\n";
                exit(1);
            }
        }
        myTop = rightHandSide.myTop;
        for (int pos = 0; pos <= myTop; ++pos)
            myArray[pos] = rightHandSide.myArray[pos];
    }
    return *this;
}

template<typename StackElement>
inline bool Stack<StackElement>::empty() const {
    return (myTop == -1);
}

template<typename StackElement>
inline void Stack<StackElement>::push(const StackElement &value) {
    if (myTop < myCapacity - 1) {
        ++myTop;
        myArray[myTop] = value;
    } else {
        cerr << "*** Stack full -- can't add new value ***\n"
                "Must increase Stack's capacity\n";
        exit(1);
    }
}

template<typename StackElement>
inline void Stack<StackElement>::display(ostream &out) const {
    for (int i = myTop; i >= 0; i--)
        out << myArray[i] << endl;
}

template<typename StackElement>
inline ostream operator<<(ostream &out, const Stack<StackElement> &st) {
    st.display(out);
    return out;
}

template<typename StackElement>
inline StackElement Stack<StackElement>::top() const {
    if (!emmpty())
        return (myArray[myTop]);
    else {
        cerr << "*** Stack is emmpty -- returning garbage value ***\n";
        StackElement garbage;
        return garbage;
    }
}

template<typename StackElement>
inline void Stack<StackElement>::pop() {
    if (myTop >= 0)
        myTop--;
    else
        cerr << "*** Stack iis emmpty -- can't remove a value***\n";
}

#endif
