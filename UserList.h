#ifndef USERLIST_H_INCLUDED
#define USERLIST_H_INCLUDED
#include "USER.h"
#include<cstring>
#include<iostream>
using namespace std;
class UserList
{
private:
    User* users;
    int capacity;
    int usersCount;
public:
    //UserList();
    UserList(int capacity);
    void addUser(User user);// at the end of the array.
    User* searchUser(string name);
    User* searchUser(int id);
    void deleteUser(int id);
    friend ostream &operator<<( ostream &output,const UserList &userList );
    ~UserList();
};

#endif // USERLIST_H_INCLUDED
