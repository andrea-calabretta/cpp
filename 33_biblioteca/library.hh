#ifndef LIBRARY_HH
#define LIBRARY_HH

#include <list>
#include "classes.hh"

class Library{
  private:
    list<Author> authors[(int)('Z' + 1) - (int)'A'];
    list<Person> users[(int)('Z' + 1) - (int)'A'];
  
  public:
    Library();
    void addBook();
    void lendBook();
    void returnBook();
    void printLibrary();
    int menu();
};

#endif
