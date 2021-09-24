//
// @Time   : 2021/9/19 08:28
// @Author : junstat@163.com

#include <iostream>

using namespace std;

template<typename ElementType>
void display(ElementType array[], int numElements) {
    for (int i = 0; i < numElements; ++i)
        cout << array[i] << "  ";
    cout << endl;
}

int main() {
    double x[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    display(x, 5);
    int num[] = {1, 2, 3, 4};
    display(num, 4);
}