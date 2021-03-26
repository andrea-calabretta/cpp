#include <iostream>
#include <list>
#include <algorithm>
#include "library.hh"

using namespace std;

Library::Library(){

}

void Library::addBook(){
  string authorName, bookTitle;
  int id;

  cout << "Inserisci il nome dell'autore: ";
  getline(cin, authorName);
  Author *pauthor = new Author(authorName);

  cout << "Inserisci il titolo del libro: ";
  getline(cin, bookTitle);
  Book *pbook = new Book(bookTitle);

  id = (int)(toupper(authorName[0])) - (int)'A';

  list<Author>::iterator findAuthorIter = find(authors[id].begin(), authors[id].end(), authorName);
  if (findAuthorIter == authors[id].end()){
    pauthor->getBooks().push_front(*pbook);
    authors[id].push_front(*pauthor);
  }
  else
    findAuthorIter->getBooks().push_front(*pbook);
}

void Library::lendBook(){
  string personName, authorName, bookTitle;
  int ida, idp;

  cout << "Inserisci il nome dell'utente: ";
  getline(cin, personName);
  Person *puser = new Person(personName);

  cout << "Inserisci il nome dell'autore: ";
  getline(cin, authorName);

  ida = (int)(toupper(authorName[0]))-(int)'A';
  list<Author>::iterator findAuthorIter = find(authors[ida].begin(), authors[ida].end(), authorName);
  if (findAuthorIter == authors[ida].end()){
    cout << "Autore non presente nella biblioteca" << endl;
    return;
  }

  cout << "Inserisci il titolo del libro: ";
  getline(cin, bookTitle);
  
  list<Book> &books = findAuthorIter->getBooks();
  list<Book>::iterator findBookIter = find(books.begin(), books.end(), bookTitle); 
  if(findBookIter == books.end()){
    cout << "Libro non presente nella biblioteca" << endl;
    return;
  }

  LendBook *plbook = new LendBook(&(*findAuthorIter), &(*findBookIter));

  idp = (int)(toupper(personName[0])) - (int)'A';
  list<Person>::iterator findPersonIter = find(users[idp].begin(), users[idp].end(), personName);
  if (findPersonIter == users[idp].end()){
    findBookIter->setUser(puser);
    puser->getBooks().push_front(*plbook);
    users[idp].push_front(*puser);
  }
  else{
    findPersonIter->getBooks().push_front(*plbook);
    findBookIter->setUser(&(*findPersonIter));
  }
}

void Library::returnBook(){
  string personName, authorName, bookTitle;
  int ida, idp;

  cout << "Inserisci il nome dell'utente: ";
  getline(cin, personName);

  idp = (int)(toupper(personName[0])) - (int) 'A';
  list<Person>::iterator findPersonIter = find(users[idp].begin(), users[idp].end(), personName);
  if (findPersonIter == users[idp].end()){
    cout << "L'utente non ha libri in prestito" << endl;
    return;
  }

  cout << "Inserisci il nome dell'autore: ";
  getline(cin, authorName);

  ida = (int)(toupper(authorName[0])) - (int)'A';
  list<Author>::iterator findAuthorIter = find(authors[ida].begin(), authors[ida].end(), authorName);
  if (findAuthorIter == authors[ida].end()){
    cout <<"Author non presente nella biblioteca" << endl;
    return;
  }

  cout << "Inserisci il titolo del libro: ";
  getline(cin, bookTitle);

  list<Book> &books = findAuthorIter->getBooks();
  list<Book>::iterator findBookIter = find(books.begin(), books.end(), bookTitle);
  if (findBookIter == books.end()){
    cout << "Libro non presente nella biblioteca" << endl;
    return;
  }

  LendBook *plbook = new LendBook(&(*findAuthorIter), &(*findBookIter));

  findPersonIter->getBooks().remove(*plbook);
  findBookIter->setUser(nullptr);
}

void Library::printLibrary(){

  cout << "\nLibri presenti in biblioteca: " << endl;
  for (int i = 0; i < ((int)('Z' + 1) - (int)('A')); i++){
    for (list<Author>::iterator it = authors[i].begin(); it != authors[i].end(); ++it)
       it->display();
  }
  cout << "\nLibri in prestito: " << endl;
  for (int i = 0; i <((int)('Z' + 1) - (int)('A')); i++){
    for (list<Person>::iterator it = users[i].begin(); it != users[i].end(); ++it)
         it->display();
  }
}


int Library::menu(){
  
  string msg = string("\n\nScegli una delle seguenti opzioni:\n") +
  		     "1. Inserimento di un nuovo libro nel catalogo della bibleoteca\n" +
                     "2. Prestito di un libro\n"
 	 	     "3. Restituzione di un libro\n"
		     "4. Stampa situazione libri e prestiti\n"
		     "5. Uscita\n"
		     "La tua scelta: ";
  string choice = "";

  while(true){
	cout << msg << endl;
	getline(cin, choice);
	switch(choice[0]){
	  case '1': addBook(); break;
	  case '2': lendBook(); break;
	  case '3': returnBook(); break;
	  case '4': printLibrary(); break;
	  case '5': return(0);
	}
  }
}


