//
// @Time   : 2021/9/19 17:07
// @Author : junstat@163.com

#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char **argv) {
    deque<int> d;
    cout << d.size() << " elements in an empty dequeue" << endl;

    for (int i = 1; i <= 6; i += 2) {
        d.push_back(i);
        d.push_back(i + 1);
    }

    cout << "Contents after alternating adds at front and back:\n";
    for (int i = 0; i < d.size(); i++)
        cout << d[i] << "  ";
    cout << endl;

    d.back() = 999;
    d.pop_front();

    cout << "Contents (via iterators) after changing back "
            "and popping front:\n";
    for (auto it = d.begin(); it != d.end(); it++)
        cout << *it << "  ";
    cout << endl;

    cout << "Dumping the dequeue from the back:\n";
    while (!d.empty()) {
        cout << d.back() << "  ";
        d.pop_back();
    }
    cout << endl;
    return 0;
}

