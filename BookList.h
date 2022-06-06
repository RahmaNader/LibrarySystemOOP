#ifndef BOOKLIST_H_INCLUDED
#define BOOKLIST_H_INCLUDED
#include<cstring>
#include<iostream>
#include "book.h"
using namespace std;
class BookList
{
private:
    Book* books;
    Book* BOU;
    int capacity;
    int booksCount;
    int counter;
public:
    BookList();
    BookList(const BookList& anotherList);//copy constructor
    void addBook(Book book);
    BookList(int capacity);//parameterized constructor for capacity
    Book* searchBook(string name);//search for books by name
    Book* searchBook(int id);//search for books by id
    void deleteBook(int id); //delete a book
    Book getTheHighestRatedBook();//search for the book with the highest rate
    Book* getBooksForUser(User); // get all books of this author
    int getbooksforusercounter();
    int getbookscount();
    Book & operator [ ] (int position);
    friend ostream &operator<<( ostream &output, BookList &booklist ); //to display all books
    ~BookList();
};
#endif // BOOKLIST_H_INCLUDED
