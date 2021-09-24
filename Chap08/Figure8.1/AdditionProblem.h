//
// @Time   : 2021/9/17 20:50
// @Author : junstat@163.com


#include <iostream>

using namespace std;
#ifndef ADDITION_PROBLEM
#define ADDITION_PROBLEM

class AdditionProblem {
public:
    AdditionProblem(int maxAddend = 10);


    void display(ostream &out) const;

    int answer() const;

private:
    int myAddend1, myAddend2, myAnswer;
};

void initialize();

ostream &operator<<(ostream &out, const AdditionProblem &problem);

#endif
