#include "USER.h"
#include "BOOK.h"
#include<cstring>
#include<iostream>
#include <bits/stdc++.h>
#include<string>
int Book::count = 0;
using namespace std;

/*
*The default constructor initializes the object's private members to their default values
*It has no parameters and no return values
*/
Book::Book()
{
    title="";
    isbn="";
    id=0;
    category="";
    averageRating=0.0;
    r=0;
    total=0;
    count++;
    id=count;
}
/*
*The Parameterized constructor to initialize the object
*takes parameters of title of type string, isbn of type string, category of type string
*returns no values
*/
Book::Book(string title, string isbn, string category)
{
    averageRating=0.0;
    this->title=title;
    this->isbn=isbn;
    this->category=category;
    r=0;
    total=0;
    count++;
    id=count;
}
/*
 *copy constructor that is used to copy the private members of old object to the new object
 *it takes the old object which is passed by reference as a parameter with the same type of the object(the class name)
 *const must be written to insure that the new object will not modify the sent object
 *has no return value
*/
Book::Book(const Book& book)
{
    title=book.title;
    isbn=book.isbn;
    category=book.category;
    averageRating=book.averageRating;
    author=book.author;
    id=book.id;
    r=book.r;
    total=book.total;
}
/*
*this function sets the title of the objects of the class
*it takes the title of type string as parameter
*returns no values
*/
void Book::setTitle(string title)
{
    this->title=title;
}
/*
* this function returns the object's title
*takes no parameters
*/
string Book::getTitle()const
{
    return title;
}
/*
*this function sets the isbn
*takes the object's isbn of type string as parameter
*returns no value
*/
void Book::setISBN(string isbn)
{
    this->isbn=isbn;
}
/*
*this function returns the isbn
*takes no parameters
*/
string Book::getISBN() const
{
    return isbn;
}
/*
*this function sets the object's id
*takes the object's id of type int as parameter
*returns no values
*/
void Book::setId(int id)
{
    this->id=id;
}
/*
*this function returns the object's id
*takes no parameters
*/
int Book::getId() const
{
    return id;
}
/*
*this function sets the category of the objects
*takes the object's category of type string as parameters
*returns no values
*/
void Book::setCategory(string category)
{
    this->category=category;
}
/*
*this function returns the object's category
*takes no parameters
*/
string Book::getCategory() const
{
    return category;
}
/*
*this function is used to assign one of the users to be the author of a book
which include assigning it's name, email, age
the variable x is used to check whether it has been used before by a book before printing to make sure
it assigns the author an id of 0 in case it hasn't been used before
*it takes an object of type user as it's parameter
*it returns no value
*/
void Book::setAuthor(User user)
{
    x=1;
    User::count-=2;
    author.name=user.name;
    author.email=user.email;
    author.age=user.age;
    author.id=user.id;
}
/*
* this function returns an author of a certain book
and in case the user hasn't been used before it sets the id to equal 0
*it takes no parameters
*/
User Book::getAuthor()
{

    if(x==1)
    {
        return author;
    }
    else
    {
        author.id=0;
        author.setName("");
        User::count-=2;
        return author;
    }
}
// this function should update averageRating attribute as a new rating is
// introduced to the book so the average rating should be affected.
// Check the main screenshot to know more information
/*
*in this function there are 2 static variables (total) which sums
the total of rates assigned to a book and (r) which counts the number of books
together they're used to calculate the average rating of a book
*it takes rating of type int as a parameter
*returns no value
*/
void Book::rateBook(int rating)
{
    r++;
    total+=rating;
    averageRating = double(total)/double(r);

}
/*
*this function returns the average rating of the books that was originally calculated
*takes no parameters
*/
double Book::getrate() const
{
    return averageRating;
}
/* overloading the == operator which compares 2 objects if they are equal or not
 * takes the object of the right hand side as an parameter which is passed by reference
 * const is written to to insure that the object on the LHS will not modify the sent object
 * returns bool value, true if they are equal and false if they are not
 */
bool Book::operator==(const Book& book)
{
    bool status=false;
    if(title==book.title&&isbn==book.isbn&&category==book.category&&id==book.id&&author==book.author)
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
 *friend stand alone function of type istream used to overload the >>operator to help cin the object easily in the main
 * it takes 2 parameters the input parameter and the object which we want to take it from the user (cin)
 * it returns the input value of type istream
*/
istream &operator>>( istream &input, Book &book )
{
    cout<<"Enter the book information in this order"<<endl;
    cout<<"Title ISBN Category(Space separated)"<<endl;
    input>>book.title>>book.isbn>>book.category;
    return input;
}
/*
 *friend stand alone function of type ostream used to overload the <<operator to help cout the object easily in the main
 * it takes 2 parameters the output parameter and the object which we want to print , it must be const to insure the function will not change the output
 * it returns the output value of type ostream
*/
ostream &operator<<(ostream &output, const Book &book )
{
    output<<"======= Book "<<book.getId()<<" info ========"<<endl;
    output<<"Title: "<<book.title<<endl;
    output<<"ISBN: "<<book.isbn<<endl;
    output<<"Id:"<<book.id<<endl;
    output<<"Category: "<<book.category<<endl;
    output<<"Avg Rating: "<<book.averageRating<<endl;
    return output;
}
