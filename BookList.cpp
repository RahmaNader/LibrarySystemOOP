#include <iostream>
#include <string>
#include <algorithm>
#include "BookList.h"
#include <bits/stdc++.h>
using namespace std;
/*
 *parameterized constructor for capacity used to create a new object of type BookList
 * it takes 1 parameter of type int to set the capacity which is the size of the array created
*/
BookList::BookList(int capacity)
{
    this->capacity = capacity;
    booksCount = 0;
    books = new Book[capacity];
}
/*
 *copy constructor used to create a new object of type BookList and copy the content of an old book list to a new book list
 * it takes 1 parameter of type BookList
*/
BookList::BookList(const BookList& anotherList)
{
    capacity = anotherList.capacity;
    booksCount = anotherList.booksCount;
    books = new Book[capacity];
    for(int i=0; i<capacity; i++)
    {
        books[i] = anotherList.books[i];
    }
}
/*
 *addBook of type void used to insert a new book to the book list
 * it takes 1 parameter of type Book
*/
void BookList::addBook(Book book)
{
    books[booksCount]=book;
    books[booksCount].setAuthor(book.getAuthor());
    booksCount++;
}
/*
 *searchBook of type Book* used to a search book by its name
 * it takes 1 parameter of type string which is the title of the book
 *returns the book if found else it returns NULL
*/
Book* BookList::searchBook(string name)
{

    for(int i=0; i<booksCount; i++)
    {
        if(name==books[i].getTitle())
        {
            return (books+i);
        }
    }
    return NULL;
}
/*
 *searchBook of type Book* used to a search book by its id
 * it takes 1 parameter of type int which is the id of the book
 *returns the book if found else it returns NULL
*/
Book* BookList::searchBook(int id)
{
    for(int i=0; i<booksCount; i++)
    {
        if(id==books[i].getId())
        {

            return (books+i);
        }
    }
    return NULL;
}

/*
 *deleteBook of type void used to delete a certain book
 * it takes 1 parameter of type int which is the id of the book, searches for it then delete it
*/
void BookList::deleteBook(int id)
{
    for(int i=0; i<booksCount; i++)
    {
        if(id==books[i].getId())
        {
            for(int j=i; j<booksCount-1; j++)
            {
                books[j]=books[j+1];
            }
        }
    }
    booksCount--;
}

/*
 *getTheHighestRatedBook of type Book used to search for the book with the highest rate
 * it returns the book that has the highest rate value
*/
Book BookList::getTheHighestRatedBook()
{
    double maxi=0;
    int maxiindex=0;
    for(int i=0; i<booksCount; i++)
    {
        if(books[i].getrate()>maxi)
        {
            maxi=books[i].getrate();
            maxiindex=i;
        }
    }
    return books[maxiindex];
}
/*
 *getBooksForUser of type Book* used to get all books that are assigned to an author
 *it takes one parameter of type User
 * it returns an array of books containing all books that are assigned to a user
*/
Book* BookList::getBooksForUser(User user)
{
    counter=0;
    int j=0;
    for (int i = 0; i < booksCount; i++)
    {
        if (books[i].getAuthor()== user)
        {
            counter++;
        }
    }
    BOU = new Book[counter];
    for (int i = 0; i < booksCount; i++)
    {
        if (books[i].getAuthor()== user)
        {
            BOU[j] = books[i];
            j++;
        }
    }
    return BOU;
}
/*
 *getbooksforusercounter of type int used to get the number of books that are assigned to a user
 * it returns an integer that is the number of books that are assigned to a user
*/
int BookList::getbooksforusercounter()
{
    return counter;
}
/*
 *this function overloads the [] operators to make sure that I only deal with elements of the array that are in range
 *it takes 1 parameter of type int that indicates the position of the array index
 * it returns an element of the array books if the position is in allowed range
*/
Book & BookList::operator [] (int position)
{
    if(position < 0 || position >= capacity)
    {
        exit(0);
    }
    return books[position];
}
/*
 *this function overloads the << operator to be able to display all elements of the array books and thus the booklist
 *it takes 1 parameter of type booklist that's the list I wish to display
 * it returns the members of the list an they assigned authors if they exist
*/
ostream &operator<<( ostream &output, BookList &booklist )
{
    for(int i=0; i<booklist.booksCount; i++)
    {
        output<<booklist.books[i]<<endl;

        if((booklist.books[i]).getAuthor().getName()!="")
        {
            output<<"=======Author info========"<<endl;
            output<<booklist.books[i].getAuthor();
        }
    }
    return output;
}
/*
 *getbookscount of type int returns the number of  books in a list
 * it returns an element of type int that's the number of  books in a list
*/
int BookList::getbookscount()
{
    return booksCount;
}
/*
 *~BookList is the destructor of the object and it deletes all array pointers
*/
BookList::~BookList()
{
    delete []books;
    delete []BOU;

}
