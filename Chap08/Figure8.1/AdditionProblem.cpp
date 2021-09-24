//
// @Time   : 2021/9/17 20:50
// @Author : junstat@163.com

#include <cstdlib>
#include <ctime>
#include "AdditionProblem.h"

AdditionProblem::AdditionProblem(int maxAdded) {
    myAddend1 = rand() % (maxAdded + 1);
    myAddend2 = rand() % (maxAdded + 1);
    myAnswer = myAddend1 + myAddend2;
}

void AdditionProblem::display(ostream &out) const {
    out << myAddend1 << " + " << myAddend2 << " = ? ";
}

int AdditionProblem::answer() const {
    return (myAddend1 + myAddend2);
}

ostream &operator<<(ostream &out, const AdditionProblem &problem) {
    problem.display(out);
    return out;
}

void initialize() {
    long seed = long(time(0));
    srand(seed);
}