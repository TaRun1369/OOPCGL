#include <iostream>
#include <string>
using namespace std;
class Publication
{
protected:
string title;
float price;
};
class Book : public Publication
{
int pagecount;
public:
void setdetails();
void display();
};
class Tape : public Publication
{
float play_time;
public:
void setdetails();
void display();
};
void Book :: setdetails()
{
try
{
cout << "Enter the title of the book: " << endl;
getline(cin,title);
cout << "Enter the price of the book: " << endl;
cin >> price;
cout << "Enter the number of pages in the book: " << endl;
cin >> pagecount;
if(this->title.size()<3){
cout<<"\nInvalid title!\n"<<endl;
throw this->title;
}
if(this->price<0.0){
cout<<"\nInvalid price!\n"<<endl;
throw this->price;
}
if(this->pagecount<0){
cout<<"\nInvalid pagecount!\n"<<endl;
throw this->pagecount;
}
}
catch(string title)
{
this->title = "";
this->price = 0.0;
this->pagecount = 0;
}
catch(float price)
{
this->title = "";
this->price = 0.0;
this->pagecount = 0;
}
catch(int pagecount)
{
this->title = "";
this->price = 0.0;
this->pagecount = 0;
}
}
void Book :: display()
{
cout << "\nDetails of the Book:- " << endl;
cout << "Title: " << title << endl;
cout << "Price: " << price << endl;
cout << "Number of pages: " << pagecount << endl;
}
void Tape :: setdetails()
{
try
{
cout << "Enter the title of the tape: " << endl;
cin.ignore();
getline(cin,title);
cout << "Enter the price of the tape: " << endl;
cin >> price;
try{
cout << "Enter the playing time in minutes: " << endl;
cin >> play_time;
if(this->play_time<0.0){
throw this->play_time;
}
}
catch(float play_time)
{
cout<<"\nInvalid playtime!\n"<<endl;
this->title = "";
this->price = 0.0;
this->play_time = 0.0;
}
if(this->title.size()<3){
cout<<"\nInvalid title!\n"<<endl;
throw this->title;
}
if(this->price<0.0){
throw this->price;
}
}
catch(string title)
{
this->title = "";
this->price = 0.0;
this->play_time = 0.0;
}
catch(float price)
{
cout<<"\nInvalid price!\n"<<endl;
this->title = "";
this->price = 0.0;
this->play_time = 0.0;
}
}
void Tape :: display()
{
cout << "\nDetails of the Tape:- " << endl;
cout << "Title: " << title << endl;
cout << "Price: " << price << endl;
cout << "Playing Time: " << play_time << " minutes" << endl;
}
int main()
{
Book b;
Tape t;
b.setdetails();
t.setdetails();
b.display();
t.display();
return 0;
}
