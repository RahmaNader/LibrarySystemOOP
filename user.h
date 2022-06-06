#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include<cstring>
#include<iostream>
using namespace std;
class User
{
private:
    string name;
    int age;
    int id;
    string password;
    string email;
public:
    static int count;
    User();
    User(string name, int age, string email, string password);
    User(const User&user);
    bool operator==(const User& user);
    void setName(string name);
    string getName() const;
    void setPassword(string password);
    string getPassword() const;
    void setEmail(string email);
    string getEmail() const;
    void setAge(int age);
    int getAge() const;
    void setId(int id);
    int getId() const;
    friend class Book;
    friend ostream &operator<<(ostream &output, const User &user );
    friend istream &operator>>( istream &input, User &user );

};

#endif // USER_H_INCLUDED
