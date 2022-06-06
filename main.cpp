/*
*This program is an OOP assignment coded by Rahma Nader Osama Mohammed and Arwa Hazem Mohamed Khalil
*The purpose of the program is to create an online library system with users and books.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include "USER.h"
#include "BOOK.h"
#include "BookList.h"
#include "UserList.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int c;
    int option=0;//option for when i want to take any option at any time
    int bookcap=0;//capacity of the book list
    int usercap=0;//capacity of the user list
    int usermenu=0;//option of user menu
    int bookmenu=0;//option of book menu
    int mainchoice=0;//main menu option
    string name;//string for when I need to use one
    int id=0;
    int choice=0;
    int userindex=0;//id counter for users array and thus users list
    int usercheck=0;//creation counter for user list
    int bookindex=0;//id counter
    int bookcheck=0;//creation counter
    int mainmcheck=0;
    int useraftersearch=0;
    int bookaftersearch=0;
    int rate=0;
    string newcategory;
    string newname;
    UserList* uGlobal=0;
    BookList* bGlobal=0;
    Book b;
    Book t;
    User u;
    BookList* bCopy=0;
    do
    {
        //main menu choices
        cout<<"Select one of the following choices: "<<endl;
        cout<<"1- Books Menu"<<endl;
        cout<<"2- Users Menu"<<endl;
        cout<<"3- Exit"<<endl;
        cin>>mainchoice;
        //main menu choices
        if(mainchoice==1)
        {
            //book menu
            if(bookcheck==0)
            {
                cout<<"How many books will be added?"<<endl;
                cin>>bookcap;
            }
            bGlobal = new BookList(bookcap);
            do
            {
                //book menu choices
                cout<<"BOOKS MENU"<<endl;
                cout<<"1- Create a book and add it to the list"<<endl;
                cout<<"2- Search for a book"<<endl;
                cout<<"3- Display all books (with book rating)"<<endl;
                cout<<"4- Get the highest rating book"<<endl;
                cout<<"5- Get all books of a user"<<endl;
                cout<<"6- Copy the current Book List to a new Book List and switch to it"<<endl;
                cout<<"7- Back to the main menu"<<endl;
                cin>>bookmenu;
                //book menu choices
                //option 1
                if(bookmenu==1)
                {
                    cin>>b;
                    b.setId(bookindex+1);
                    //t=(*(bl.searchBook(b[bookindex].getId())));
                    while(choice!=2)
                    {
                        cout<<"1- Assign author"<<endl;
                        cout<<"2- Continue"<<endl;
                        cin>>choice;
                        if(choice==1)
                        {
                            cout<<"Enter author (user) id: "<<endl;
                            int userid=0;
                            cin>>userid;
                            if((uGlobal->searchUser(userid))==NULL)
                            {
                                cout<<"No Author Found with id = "<<userid<<endl;
                            }
                            else
                            {
                                b.setAuthor(*(uGlobal->searchUser(userid)));
                                bGlobal->addBook(b);
                                (*(bGlobal->searchBook(bookindex+1)))=b;
                                bookindex++;
                                break;

                            }
                        }
                        else
                        {
                            bGlobal->addBook(b);
                            bookindex++;
                        }
                    }
                    //end of option 1
                }
                //option 2
                else if(bookmenu==2)
                {
                    do
                    {
                        cout<<"SEARCH FOR A BOOK"<<endl;
                        cout<<"1- Search by name"<<endl;
                        cout<<"2- Search by id"<<endl;
                        cout<<"3- Return to Books menu"<<endl;
                        cin>>bookaftersearch;
                        //book after search option 1
                        if(bookaftersearch==1)
                        {
                            cout<<"Enter name"<<endl;
                            cin>>name;
                            if(bGlobal->searchBook(name)==NULL)
                            {
                                cout<<"book not found"<<endl;
                            }
                            else
                            {
                                cout<<*(bGlobal->searchBook(name));
                                t=(*(bGlobal->searchBook(name)));
                                cout<<"Author: "<<t.getAuthor().getName()<<endl;
                                do
                                {
                                    cout<<endl;
                                    cout<<"1- Update author"<<endl;
                                    cout<<"2- Update name"<<endl;
                                    cout<<"3- Update category"<<endl;
                                    cout<<"4- Delete Book"<<endl;
                                    cout<<"5- Rate book"<<endl;
                                    cout<<"6- Get back to books menu"<<endl;
                                    cin>>option;
                                    //option1
                                    if(option==1)
                                    {
                                        t=(*(bGlobal->searchBook(name)));
                                        cout<<"Enter author (user) id: "<<endl;
                                        int userid=0;
                                        cin>>userid;
                                        if((uGlobal->searchUser(userid))==NULL)
                                        {
                                            cout<<"No Author Found with id = "<<userid<<endl;
                                        }
                                        else
                                        {
                                            t.setAuthor(*(uGlobal->searchUser(userid)));
                                            (*(bGlobal->searchBook(name)))=t;

                                        }
                                    }
                                    //end of option 1

                                    //option 2 update name
                                    else if(option==2)
                                    {
                                        cout<<"Enter new name:"<<endl;
                                        t=(*(bGlobal->searchBook(name)));
                                        cin>>newname;
                                        t.setTitle(newname);
                                        (*(bGlobal->searchBook(name)))=t;
                                        name=newname;
                                    }
                                    //end of option 2

                                    //option3
                                    else if(option==3)
                                    {
                                        cout<<"Enter new category:"<<endl;
                                        t=(*(bGlobal->searchBook(name)));
                                        cin>>newcategory;
                                        t.setCategory(newcategory);
                                        (*(bGlobal->searchBook(name)))=t;
                                    }
                                    //end of option 3

                                    //option 4
                                    else if(option==4)
                                    {
                                        Book btemp;
                                        btemp=*(bGlobal->searchBook(name));
                                        bGlobal->deleteBook(btemp.getId());
                                    }
                                    //end of option 4

                                    //option 5
                                    else if(option==5)
                                    {

                                        cout<<"Enter the book rating"<<endl;
                                        cin>>rate;
                                        t=(*(bGlobal->searchBook(name)));
                                        t.rateBook(rate);
                                        (*(bGlobal->searchBook(name)))=t;
                                    }
                                    //end of option 5
                                }
                                while(option!=6);
                                break;
                            }    //copy here
                        }//end of book after search option 1

                        //book after search option 2
                        if(bookaftersearch==2)
                        {
                            cout<<"Enter id"<<endl;
                            int id;
                            cin>>id;
                            if(bGlobal->searchBook(id)==NULL)
                            {
                                cout<<"No Book was found by that id"<<endl;
                            }
                            else
                            {
                                cout<<*(bGlobal->searchBook(id));
                                t=(*(bGlobal->searchBook(id)));
                                cout<<"Author: "<<t.getAuthor().getName()<<endl;
                                do
                                {
                                    cout<<endl;
                                    cout<<"1- Update author"<<endl;
                                    cout<<"2- Update name"<<endl;
                                    cout<<"3- Update category"<<endl;
                                    cout<<"4- Delete Book"<<endl;
                                    cout<<"5- Rate book"<<endl;
                                    cout<<"6- Get back to books menu"<<endl;
                                    cin>>option;
                                    //option1
                                    if(option==1)
                                    {
                                        cout<<"Enter author (user) id: "<<endl;
                                        int userid=0;
                                        cin>>userid;
                                        if((uGlobal->searchUser(userid))==NULL)
                                        {
                                            cout<<"No Author Found with id = "<<userid<<endl;
                                        }
                                        else
                                        {
                                            t.setAuthor(*(uGlobal->searchUser(userid)));
                                            (*(bGlobal->searchBook(id)))=t;
                                        }

                                    }
                                    //end of option 1

                                    //option 2 update name
                                    else if(option==2)
                                    {
                                        cout<<"Enter new name:"<<endl;
                                        t=(*(bGlobal->searchBook(id)));
                                        cin>>newname;
                                        t.setTitle(newname);
                                        (*(bGlobal->searchBook(id)))=t;
                                        name=newname;
                                    }
                                    //end of option 2

                                    //option3
                                    else if(option==3)
                                    {
                                        cout<<"Enter new category:"<<endl;
                                        t=(*(bGlobal->searchBook(id)));
                                        string newcategory;
                                        cin>>newcategory;
                                        t.setCategory(newcategory);
                                        (*(bGlobal->searchBook(id)))=t;
                                    }
                                    //end of option 3

                                    //option 4
                                    else if(option==4)
                                    {
                                        bGlobal->deleteBook(id);
                                    }
                                    //end of option 4

                                    //option 5
                                    else if(option==5)
                                    {

                                        cout<<"Enter the book rating"<<endl;
                                        cin>>rate;
                                        t=(*(bGlobal->searchBook(id)));
                                        t.rateBook(rate);
                                        (*(bGlobal->searchBook(id)))=t;
                                    }
                                    //end of option 5
                                }
                                while(option!=6);
                                break;
                            }    //copy here
                        }
                        //end of book after search option 2
                    }
                    while(bookaftersearch!=3);
                }
                //end of option 2

                //option 3
                else if(bookmenu==3)
                {
                    cout<<*(bGlobal);
                }//end of option 3

                //option 4
                else if(bookmenu==4)
                {
                    cout<<bGlobal->getTheHighestRatedBook();
                    c=bGlobal->getTheHighestRatedBook().getId();
                     t=(*(bGlobal->searchBook(c)));
                    cout<<"=======Author info======="<<endl;
                    cout<<t.getAuthor();
                }//end of option 4

                //option 5
                else if(bookmenu==5)
                {
                    cout<<"Enter User ID"<<endl;
                    int uid;
                    cin>>uid;
                    u=*(uGlobal->searchUser(uid));
                    Book *bu;
                    bu=((bGlobal->getBooksForUser(u)));
                    for(int i=0; i<bGlobal->getbooksforusercounter(); i++)
                    {
                        cout<<*(bu+i);
                        cout<<"Author: "<<u.getName()<<endl;
                    }
                    delete[] bu;
                }//end of option 5

                //option 6
                else if(bookmenu==6)
                {

                    bCopy = new BookList(*bGlobal);
                    cout<<"Copied current list ("<<bCopy->getbookscount()<<" books) to a new List and switched to it"<<endl;

                }//end of option 6

                bookcheck=1;
            }
            while(bookmenu!=7);
            //end of book menu
        }
        if(mainchoice==2)
        {
            //user menu
            if(usercheck==0)
            {
                cout<<"How many users will be added?"<<endl;
                cin>>usercap;
            }
            uGlobal = new UserList(usercap);
            do
            {

                //user menu choices
                cout<<"USERS MENU"<<endl;
                cout<<"1- Create a USER and add it to the list"<<endl;
                cout<<"2- Search for a user"<<endl;
                cout<<"3- Display all users"<<endl;
                cout<<"4- Back to the main menu"<<endl;
                cin>>usermenu;
                // user menu choices
                //option 1 adding a user
                if(usermenu==1)
                {
                    cin>>u;
                    u.setId(userindex+1);
                    uGlobal->addUser(u);
                    userindex++;
                }//end of option 1 adding a user

                //option 2 search for user
                else if(usermenu==2)
                {
                    do
                    {
                        cout<<"SEARCH FOR A USER"<<endl;
                        cout<<"1- Search by name"<<endl;
                        cout<<"2- Search by id"<<endl;
                        cout<<"3- Return to Users menu"<<endl;
                        cin>>useraftersearch;
                        //user after search option 1
                        if(useraftersearch==1)
                        {
                            cout<<"Enter name"<<endl;
                            cin>>name;
                            if(uGlobal->searchUser(name)==NULL)
                            {
                                cout<<"user not found"<<endl;
                            }
                            else
                            {
                                u=*(uGlobal->searchUser(name));
                                cout<<"======= User "<<u.getId()<<" info ========"<<endl;
                                cout<<*(uGlobal->searchUser(name));
                                cout<<"1- Delete user"<<endl;
                                cout<<"2- Return to Users Menu"<<endl;
                                cin>>option;
                                if(option==1)
                                {
                                    User utemp;
                                    utemp=*(uGlobal->searchUser(name));
                                    uGlobal->deleteUser(utemp.getId());
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }//end of user after search option 1

                        //user after search option 2
                        else if(useraftersearch==2)
                        {
                            cin>>id;
                            if(uGlobal->searchUser(id)==NULL)
                                cout<<"user not found"<<endl;
                            else
                            {
                                cout<<"======= User "<<id<<" info ========"<<endl;
                                cout<<*(uGlobal->searchUser(id));
                                cout<<"1- Delete user"<<endl;
                                cout<<"2- Return to Users Menu"<<endl;
                                cin>>option;
                                if(option==1)
                                {
                                    uGlobal->deleteUser(id);
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }
                        //end of user after search option 2
                    }
                    while(useraftersearch!=3);
                }//end of option 2

                //option 3
                else if(usermenu==3)
                {
                    cout<<*(uGlobal);
                }//end of option 3

                usercheck=1;
            }
            while(usermenu!=4); //end of user menu
        }

        mainmcheck=1;
    }
    while(mainchoice!=3); //end of main menu
    delete[] uGlobal;
    delete[] bGlobal;
    delete[] bCopy;
    return 0;
}//end main
