#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
#include <ctime>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

struct Admin
{
    string username;
    string password;
};

struct Book
{
    string id;
    string title;
    string author;
    string genre;
    string borrowed_by;
    bool is_borrowed;
};


struct Member
{
    string username;
    string password;
    string fullname;
    string phone;
    string registery_date;
    int borrowed_books_number;
    vector<Book> borrowed_books;
};
Member current_member;

extern vector<Book> all_books;
extern vector<Member> all_members;

void manager_menu();
void show_borrowed_books();
void show_people_who_borrowed();
void add_book();
void delete_member();
void delete_book();
void member_account_menu();

void member_register();
void member_login();
void member_menu();
void  borrowed_book();

void member_info();
void select_book_menu();
void show_available_books();
void  borrow_book();
void edit_book();

void main_menu();

void member_account_menu()
{    system ("cls");
      cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    cout << "Member account menu\t" ;

    cout << "Date: ";
      time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";
    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
      cout << "";
    cout << "1.Register" << endl;
    cout << "2.Login" << endl;

    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        member_register();
        break;
    case 2:
        member_login();
        break;
    default:
        break;
    }
}

void member_register()
{
    system ("cls");
     cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
      cout << "";

    cout << "Member register\t"  ;

    cout << "Date: ";
      time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";

     cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
      cout << "";

    Member member;
    cout << "Enter your username: ";
    cin >> member.username;
    cout << "Enter your password: ";
    cin >> member.password;
    cout << "Enter your fullname: ";
    cin >> member.fullname;
    cout << "Enter your phone: ";
    cin >> member.phone;

    all_members.push_back(member);
    current_member = member;
    member_menu();

}

void member_login()
{
    system ("cls");
    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";
    cout << "Member login\t" ;

    cout << "Date: ";
      time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";
    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";


    bool user_exists = false;
    while (!user_exists)
    {
        cout<< "If you want to exit, press 0!"<<endl;
        cout << "Enter your username: ";
        string username;
        cin >> username;
        if(username == "0"){
            break;
        }
        cout << "Enter your password: ";
        string password;
        cin >> password;

        for (int i = 0; i < all_members.size(); i++)
        {
            if (username == all_members[i].username && password == all_members[i].password)
            {
                user_exists = true;
                current_member = all_members[i];
                break;
            }
        }
        if(user_exists==false)
        {
            cout << "Incorrect username or password. Please try again." << endl;
        }else{
            member_menu();}

        }

}

void member_menu()
{
    while(true)
    {
        system ("cls");

    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

        cout << "Member menu\t";
        cout << "Date: ";
        time_t t = time(0);   // get time now
        tm* now = localtime(&t);
      cout << (now->tm_year + 1900) << '-'
           << (now->tm_mon + 1) << '-'
           <<  now->tm_mday
           << "\n";
        cout << "";
        SetConsoleTextAttribute(h, 0xF6);
        cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
        cout << "";

        cout << "1.Member info" << endl;
        cout << "2.Select a book" << endl;
        cout << "3.Show borrowed books" << endl;
        cout << "";
        SetConsoleTextAttribute(h, 0xF4);
        cout << "4.Exit" << endl;
        SetConsoleTextAttribute(h, 0xF0);
        cout << "";




        int option;
        cin >> option;
        switch (option)
        {

        case 1:
              member_info();
              break;
        case 2:
            select_book_menu();
            break;
        case 3:
            borrowed_book();
            break;
        case 4:
            main_menu();
            break;
        default:
            break;
        }

    }

}
void member_info()
{
    cout<< "your username: "<< current_member.username << '\n';
    cout<< "yourfullname: "<< current_member.fullname << '\n';
    cout<< "phone: "<< current_member.phone << '\n';

       cout << "";
        SetConsoleTextAttribute(h, 0xF5);
      cout<<"1.back";
        SetConsoleTextAttribute(h, 0xF0);
        cout << "";
    int a=0;
    while(a!=1){
        cin>> a;}
        member_menu();

}

void borrowed_book()
{
    bool checker = false;
    for (int i = 0; i < all_books.size(); i++)

       {
            if (all_books[i].is_borrowed==true && all_books[i].borrowed_by==current_member.username){
                cout << all_books[i].title<<"  borrowed by you"<<endl;
                checker = true;
            }


        }
        if(checker == false){
        cout<< "you did not borrow a book"<<endl;
        }
           cout << "";
        SetConsoleTextAttribute(h, 0xF5);
          cout<<"1.back";
        SetConsoleTextAttribute(h, 0xF0);
        cout << "";
    int a=0;
    while(a!=1){
        cin>> a;}
        member_menu();
}



void select_book_menu()

{
    system ("cls");
    while(true){
    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    cout << "Select book menu\t";
    cout << "Date: ";
      time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";
    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    cout << "1.Show available books" << endl;
    cout << "2.Borrow a book" << endl;
    cout << "";
    SetConsoleTextAttribute(h, 0xF4);
    cout << "3.Exit" << endl;
    SetConsoleTextAttribute(h, 0xF0);
    cout << "";
    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        show_available_books();
        break;
    case 2:
        borrow_book();
        break;
    case 3:
        member_menu();
        break;
    default:
        break;
     }
    }
}

void show_available_books()
{
    for (int i = 0; i < all_books.size(); i++)
    {
        if (!all_books[i].is_borrowed)
        {
            cout << all_books[i].title << endl;
        }
    }
     cout << "";
    SetConsoleTextAttribute(h, 0xF5);
     cout<<"1.back";
    SetConsoleTextAttribute(h, 0xF0);
    cout << "";
    int a=0;
    while(a!=1){
        cin>> a;}
    select_book_menu();
}

 void borrow_book()
 {
    // id ketab ro begir baraye borrow kardan
    string book_id;
    cout<< "enter book id you want:";
    cin>>book_id;

    for (int i = 0; i < all_books.size(); i++)
    {
        if (all_books[i].id == book_id)
        {
            cout<< all_books[i].title<<endl;
            if(all_books[i].is_borrowed){
                cout << "is not availble "<<endl;
            } else { // baraye current_member migire in ketab ro
                all_books[i].is_borrowed = true;
                all_books[i].borrowed_by = current_member.username;
            }
            break;
        }

    }
    cout<< "saving..."<<endl;
     cout << "";
        SetConsoleTextAttribute(h, 0xF5);
     cout<<"1.back";
        SetConsoleTextAttribute(h, 0xF0);
       cout << "";
    int a=0;
    while(a!=1){
        cin>> a;}
    select_book_menu();
 }




void manager_login()
{
    system ("cls");
    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    cout << "Admin login\t" ;
    cout << "Date: ";
      time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";

    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    string username;
    string password;
    while (username != "admin" || password != "admin")
    {
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
        if (username != "admin" || password != "admin")
        {
            cout << "Incorrect username or password. Please try again." << endl;
        }
    }
    manager_menu();

}

void manager_menu()
{
    system ("cls");
    while(true)

{
    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    cout << "Manager menu\t";
    cout << "Date: ";
      time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";

    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    cout << "1.Show borrowed books" << endl;
    cout << "2.Show people who have borrowed a book" << endl;
    cout << "3.Add a book" << endl;
    cout << "4.Delete a book" << endl;
    cout << "5.Delete a member" << endl;
    cout << "6.edit a book" << endl;
    cout << "";
    SetConsoleTextAttribute(h, 0xF4);
    cout << "7.exit" << endl;
    SetConsoleTextAttribute(h, 0xF0);
    cout << "";
    int option;
    cin >> option;

    switch (option)
    {

    case 1:
        show_borrowed_books();
        break;
    case 2:
        show_people_who_borrowed();
        break;
    case 3:
        add_book();
        break;
    case 4:
        delete_book();
        break;
    case 5:
        delete_member();
        break;
    case 6:
        edit_book();
        break;
    case 7:
        main_menu();
        break;
    default:
        cout << "Please select an option" << endl;
        break;
    }


}
}


void show_borrowed_books()
{
    system ("cls");
    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    cout << "Borrowed books\t";
    cout << "Date: ";
      time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";

    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    for (int i = 0; i < all_books.size(); i++)
    {
       if (all_books[i].is_borrowed)
        {
            cout << "title: "<<all_books[i].title << endl;
            cout << "genre: "<< all_books[i].genre << endl;
            cout << "author: "<<all_books[i].author << endl;
            cout << "borrwed by: "<<all_books[i].borrowed_by << endl;


       }

    }
     cout << "";
        SetConsoleTextAttribute(h, 0xF5);
     cout<<"1.back";
        SetConsoleTextAttribute(h, 0xF0);
      cout << "";
    int a=0;
    while(a!=1){
        cin>> a;}
        manager_menu();

}

void show_people_who_borrowed()
{
   cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    cout << "People who have borrowed a book\t\t";
    cout << "Date: ";
      time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";

     cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";



    for (int i = 0; i < all_books.size(); i++)
    {
        if (all_books[i].is_borrowed =true)
            {
                for(int j = 0; j< all_members.size(); i++){
                    if(all_members[j].username == all_books[i].borrowed_by){
                        cout << "Book title: " << all_books[i].title << endl;
                        cout << "Borrowed by: " << all_members[j].fullname << endl;
                        cout << "Username: " << all_members[j].username << endl;
                        break;
                    }
                }
                break;
            }
    }
     cout << "";
        SetConsoleTextAttribute(h, 0xF5);
     cout<<"1.back";
      cout << "";
        SetConsoleTextAttribute(h, 0xF0);
    int a=0;
    while(a!=1){
        cin>> a;}
        manager_menu();

}
void add_book()
{

    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    cout << "Add a book\t";
    cout << "Date: ";
      time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";

    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    Book book;
    cout << "Enter the id" << endl;
    cin >> book.id;

    cout << "Enter the title" << endl;
    cin >> book.title;

    cout << "Enter the author" << endl;
    cin >> book.author;

    cout << "Enter the genre" << endl;
    cin >> book.genre;
    book.is_borrowed = false;
    all_books.push_back(book);

    cout<< "saving..."<<endl;
     cout << "";
        SetConsoleTextAttribute(h, 0xF5);
      cout<<"1.back";
       cout << "";
        SetConsoleTextAttribute(h, 0xF0);
    int a=0;
    while(a!=1){
        cin>> a;}
        manager_menu();
}

void delete_book()
{

   cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    cout << "Delete a book\t" ;
    cout << "Date: ";
      time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";

    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;



    string username;
    cout << "Enter the username" << endl;
    cin >> username;

    int foundIdx = -1;
    for (int i = 0; i < all_members.size(); i++)
    {
        if (all_members[i].username == username)
        {
            foundIdx = i;
            break;
        }
    }

    all_members.erase(all_members.begin() + foundIdx);

     cout<< "saving..."<<endl;

      cout << "";
        SetConsoleTextAttribute(h, 0xF5);
     cout<<"1.back";
      cout << "";
        SetConsoleTextAttribute(h, 0xF0);
    int a=0;
    while(a!=1){
        cin>> a;}
        manager_menu();
}

void delete_member()
{
    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    cout << "Delete a member\t";
    cout << "Date: ";
      time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";

   cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";


    string username;
    cout << "Enter the username" << endl;
    cin >> username;

    int foundIdx = -1;
    for (int i = 0; i < all_members.size(); i++)
    {
        if (all_members[i].username == username)
        {
            foundIdx = i;
            break;
        }
    }

    all_books.erase(all_books.begin() + foundIdx);

     cout<< "saving..."<<endl;

      cout << "";
        SetConsoleTextAttribute(h, 0xF5);
     cout<<"1.back";
      cout << "";
        SetConsoleTextAttribute(h, 0xF0);
    int a=0;
    while(a!=1){
        cin>> a;}
        manager_menu();
}

void edit_book()
{
   string book_id;
   cout << "enter book id : ";
   cin >>book_id;
     for(int i = 0; i < all_books.size(); i++)
     {
       if(all_books[i].id==book_id)
       {
          cout<< "enter new title : ";
          cin>> all_books[i].title;
          cout<< "enter new genre : ";
          cin>> all_books[i].genre;
          cout<< "enter new author : ";
          cin >> all_books[i].author;

       }

     }

     cout<< "saving..."<<endl;
      cout<<"1.back";
    int a=0;
    while(a!=1){
        cin>> a;}
        manager_menu();
}


void main_menu();

vector<Book> all_books;
vector<Member> all_members;

int main()
{
    system("color F0");

     Member member;
     member.username="sarvenaz";
     member.password="naz";
     member.fullname="nazanin zahra";
     member.phone="1234";
     all_members.push_back(member);

    Book book1;
    book1.id = "1";
    book1.author = "elif shafak";
    book1.title = "forty rules of love";
    book1.genre = "novel";
    book1.is_borrowed = false;
    all_books.push_back(book1);

    Book book2;
    book2.id = "2";
    book2.author = "saramago";
    book2.title = "blindness";
    book2.genre = "novel";
    book2.is_borrowed = true;
    book2.borrowed_by= "sarvenaz";
    all_books.push_back(book2);

    Book book3;
    book3.id = "3";
    book3.author = "george orwell";
    book3.title = "animal farm";
    book3.genre = "novel";
    book3.is_borrowed = false;
    all_books.push_back(book3);

    main_menu();
    return 0;
}

void main_menu()
{ while(true)
{   system ("cls");
    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    cout << "Main menu\t";
    cout << "Date: ";
      time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";

    cout << "";
        SetConsoleTextAttribute(h, 0xF6);
    cout << "*************************************" << endl;
        SetConsoleTextAttribute(h, 0xF0);
    cout << "";

    cout << "1.Management" << endl;
    cout << "2.User" << endl;
    cout << "";
    SetConsoleTextAttribute(h, 0xF4);
    cout << "3.Exit" << endl;
    SetConsoleTextAttribute(h, 0xF0);
    cout << "";
    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        manager_login();
        break;
    case 2:
        member_account_menu();
        break;
    case 3:
        break;
    default:
        break;
    }
}

}
