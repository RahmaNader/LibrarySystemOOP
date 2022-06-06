#include <iostream>
#include <string>
#include <algorithm>
#include "UserList.h"
#include "USER.h"
#include <bits/stdc++.h>
/*A parametrized constructor that takes the capacity of the userlist entered by the user */
UserList::UserList(int capacity)
{
    this->capacity = capacity;
    usersCount = 0;
    users = new User[capacity];
}
/*A destructor to release the dynamic allocation of []users */
UserList::~UserList()
{
    delete []users;
}
/* a function that takes a user as a parameter to add it to the userlist
 * has no return value */
void UserList::addUser(User user)
{
    users[usersCount]=user;
    usersCount++;
}
/* a function that takes a name as a parameter to search by that name in the userlist to find the user with that name
 * it returns a pointer of type User that contains the found user with the given name
 * it returns NULL if there is no user with the given name
*/
User* UserList::searchUser(string name)
{
    for(int i=0; i<usersCount; i++)
    {
        if(name==users[i].getName())
            return (users+i);
    }
    return NULL;
}
/* a function that takes a id as a parameter to search by that id in the userlist to find the user with that id
 * it returns a pointer of type User that contains the found user with the given id
 * it returns NULL if there is no user with the given id
*/
User* UserList::searchUser(int id)
{

    for(int i=0; i<usersCount; i++)
    {
        if(id==users[i].getId()){
            return (users+i);}
    }
    return NULL;
}
/* a function with no return value
 * takes id as a parameter to delete the user with that id from the list by shifting all the users to the right
*/
void UserList::deleteUser(int id)
{
    for(int i=0; i<usersCount; i++)
    {
        if(id==users[i].getId())
        {
            for(int j=i; j<usersCount-1; j++)
            {
                users[j]=users[j+1];
            }
        }
    }
    usersCount--;

}
/*
 *friend stand alone function of type ostream used to overload the <<operator to help cout the object of type userlist easily in the main
 * it takes 2 parameters the output parameter and the object which we want to print , it must be const to insure the function will not change the output
 * it returns the output value of type ostream
*/
ostream &operator<<( ostream &output,const UserList &userList )
{
    for(int i=0; i<userList.usersCount; i++)
    {
         output<<"======= User "<<userList.users[i].getId()<<" info ========"<<endl;
        output<<userList.users[i]<<endl;
    }
    return output;
}
