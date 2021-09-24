//
// @Time   : 2021/9/19 16:53
// @Author : junstat@163.com

#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

using namespace std;

#ifndef LOGIN_LOG
#define LOGIN_LOG

template<typename Info>
class LoginLog {
public:
    void build(string &fileName);

    int search(Info item) const;

    void display(ostream &out) const;

private:
    vector<Info> myUserLog;
};

template<typename Info>
void LoginLog<Info>::build(string &fileName) {
    ifstream fin(fileName.data());
    assert(fin.is_open());

    Info userInfo;
    for (;;) {
        fin >> userInfo;
        if (fin.eof()) break;

        int pos = search(userInfo);
        if (pos == myUserLog.size())        // new user
            myUserLog.push_back(userInfo);
    }
}

template<typename Info>
int LoginLog<Info>::search(Info item) const {
    int i;
    for (i = 0; i < myUserLog.size(); i++)
        if (item == myUserLog[i])
            break;
    return i;
}

template<typename Info>
inline void LoginLog<Info>::display(ostream &out) const {
    for (int i = 0; i < myUserLog.size(); i++)
        out << myUserLog[i] << endl;
}

#endif //LOGIN_LOG
