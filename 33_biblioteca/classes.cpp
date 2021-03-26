#include "classes.hh"


ostream& operator<<(ostream& os, const Book& book){
  return os << "  * " << book.title << (book.person != nullptr ? " - in prestito a " + book.person->getName() : "") << endl;
}

Book::Book(string title){
	person = nullptr;
	this->title = title;
}

bool Book::operator==(const Book &b){
  return (title == b.title);
}

bool Person::operator==(const Person &p){
  return (name == p.name);
}

void Person::display(){
  if (!books.empty()){
     cout << name << " ha in prestito i seguenti libri:" << endl;
     for (list<LendBook>::iterator it = books.begin(); it != books.end(); ++it)
       cout << "   ***  " << it->getAuthor()->getName() << ", " << it->getBook()->getTitle() << endl;
  }
  else
    cout << name << " non ha libri in prestito" << endl;
}

Author::Author(string name){
  this->name = name;
}

bool Author::operator==(const Author &a){
  return (name == a.name);
}

void Author::display(){
  cout << name << endl;
  for (list<Book>::iterator it = books.begin(); it != books.end(); ++it)
    cout << *it;
}

bool LendBook::operator==(const LendBook &lb) const{
  return (book->getTitle() == lb.book->getTitle() && (author->getName() == lb.author->getName()));
}

