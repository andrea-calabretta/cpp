#ifndef CLASSES_HH
#define CLASSES_HH

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Person;
class LendBook;

class Book{
  private:
    string title;
    Person *person;

  public:
    Book(string title);
    bool operator==(const Book&);
    void setUser(Person *p){ person = p;}
    string getTitle(){ return title;}
    friend ostream& operator<<(ostream& os, const Book& book);
};

class Person{
  private:
    string name;
    list<LendBook> books;

  public:
    Person(string name){ this->name = name;}
    bool operator==(const Person&);
    void display();
    string getName(){ return name; }
    list<LendBook>& getBooks() { return books;}
};

class Author{
  private:
    string name;
    list<Book> books;

  public:
    Author(string);
    bool operator==(const Author&);
    list<Book>& getBooks(){ return books;}
    string getName() const { return name;}
    void display();
};


class LendBook{
  private:
    Author *author;
    Book *book;

  public:
    LendBook(Author *a, Book *b){
      author = a;
      book = b;
    }
    bool operator==(const LendBook&) const;
    Author* getAuthor(){ return author;}
    Book* getBook(){ return book;}
};
#endif
