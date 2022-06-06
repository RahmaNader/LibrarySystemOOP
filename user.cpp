#include <iostream>
#include <string>
#include <algorithm>
#include "USER.h"
#include <bits/stdc++.h>
int User::count = 0;/*a static variable to increment the id every time an object is created */
using namespace std;
/*
 *A default constructor that is used to initialize the private members of class user
 * has no parameter and no return value
 */
User::User()
{
    name="";
    age=0;
    email="";
    password="";
    count++;
    id=count;
}
/*
 * parametrized constructor used to get the values of the private members except the id
   *take 4 parameters string name,integer age,string email and string password which are passed when creating the object
   * has no return value
*/
User::User(string name, int age, string email, string password)
{
    this->name=name;
    this->age=age;
    this->email=email;
    this->password=password;
    count++;
    id=count;
}
/*
 *copy constructor that is used to copy the private members of old object to the new object
 *it takes the old object which is passed by reference as a parameter with the same type of the object(the class name)
 *const must be written to insure that the new object will not modify the sent object
 *has no return value
*/
User::User(const User& user)
{
    name=user.name;
    age=user.age;
    email=user.email;
    password=user.password;
    id=user.id;
}
/* overloading the == operator which compares 2 objects if they are equal or not
 * takes the object of the right hand side as an parameter which is passed by reference
 * const is written to to insure that the object on the LHS will not modify the sent object
 * returns bool value, true if they are equal and false if they are not
 */
bool User::operator==(const User& user)
{
    bool status=false;
    if(email==user.email&&name==user.name&&age==user.age&&id==user.id)
    {
        status=true;
        return status;
    }
    else
    {
        return status;
    }

}
/*
 * public void function (setter) used to take the value of name from outside the class and assign it to the private member name
 * takes 1 parameter which is name of type string
 * has no return value
 */
void User::setName(string name)
{
    this->name=name;
}
/*
 * public function of type string (getter) used to get the value from the private member name outside the class to be used
 * has no parameters
 *returns name of type string
 */
string User::getName() const
{
    return name;
}
/*
 * public void function (setter) used to take the value of password from outside the class and assign it to the private member password
 * takes 1 parameter which is password of type string
 * has no return value
 */
void User::setPassword(string password)
{
    this->password= password;
}
/*
 * public function of type string (getter) used to get the value from the private member password outside the class to be used
 * has no parameters
 *returns password of type string
 */
string User::getPassword() const
{
    return password;
}
/*
 * public void function (setter) used to take the value of email from outside the class and assign it to the private member email
 * takes 1 parameter which is email of type string
 * has no return value
 */
void User::setEmail(string email)
{
    this->email=email;
}
/*
 * public function of type string (getter) used to get the value from the private member email outside the class to be used
 * has no parameters
 *returns email of type string
 */
string User::getEmail() const
{
    return email;
}
/*
 * public void function (setter) used to take the value of age from outside the class and assign it to the private member age
 * takes 1 parameter which is age of type int
 * has no return value
 */
void User::setAge(int age)
{
    this->age=age;
}
/*
 * public function of type string (getter) used to get the value from the private member age outside the class to be used
 * has no parameters
 *returns age of type int
 */
int User::getAge() const
{
    return age;
}
/*
 * public void function (setter) used to take the value of id from outside the class and assign it to the private member id
 * takes 1 parameter which is id of type int
 * has no return value
 */
void User::setId(int id)
{
    this->id=id;
}
/*
 * public function of type int (getter) used to get the value from the private member id outside the class to be used
 * has no parameters
 *returns id of type int
 */
int User::getId() const
{
    return id;
}
/*
 *friend stand alone function of type istream used to overload the >>operator to help cin the object easily in the main
 * it takes 2 parameters the input parameter and the object which we want to take it from the user (cin)
 * it returns the input value of type istream
*/
istream &operator>>( istream &input, User &user )
{
    cout<<"Enter information in this order"<<endl;
    cout<<"Name Age Email Password (space separated)"<<endl;
    input>>user.name>>user.age>>user.email>>user.password;
    return input;
}
/*
 *friend stand alone function of type ostream used to overload the <<operator to help cout the object easily in the main
 * it takes 2 parameters the output parameter and the object which we want to print , it must be const to insure the function will not change the output
 * it returns the output value of type ostream
*/
ostream &operator<<(ostream &output, const User &user )
{
    output<<"Name: "<<user.name<<endl;
    output<<"Age: "<<user.age<<endl;
    output<<"Id:"<<user.id<<endl;
    output<<"Email:"<<user.email<<endl;
    output<<"==============================="<<endl;
    return output;
}
