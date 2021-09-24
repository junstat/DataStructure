//
// @Time   : 2021/9/19 16:58
// @Author : junstat@163.com

#include "LoginLog.h"

int main() {
    string userInfoFile = "/Users/jun/Documents/Learn/CLinonCode/DataStructure/Chap09/Figure9.5-6/UserIdFile";
//    cout << "Enter name of login-in file:";
//    getline(cin, userInfoFile);

    LoginLog<string> userIdLog;
    userIdLog.build(userInfoFile);

    cout << "\nList of distinct user-ids who logged in:\n";
    userIdLog.display(cout);
}

