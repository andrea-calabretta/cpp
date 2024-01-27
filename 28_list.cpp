#include <iostream>
#include <list>

using namespace std;

class Studente{
  private:
    string nome, cognome;
    string matricola;

  public:
    Studente(string n, string c, string mat){
			nome = n;
			cognome = c;
			matricola = mat;
    }
    
    void print(){
	cout << "Cognome: " << cognome << ", Nome: " << nome << ", Matricola: " << matricola << endl;
    }
};

void print_list(string s, list<int> &l){
  list<int>::iterator i;

  cout << s << "[";
  for ( i=l.begin(); i != l.end(); ++i){
    cout << *i << ",";
  }
  cout << "]" << endl;

}

bool test_element(int v){
  return(v==20);
}
int main(){
  /*list<int> l; 
  list<int> l2;

  l.push_front(20);
  l.push_front(10);
  l.push_front(20);
  l.push_back(30);

  l2.push_front(5);
  l2.push_front(55);
  l2.push_front(70);
  l2.push_back(15);

  print_list("lista l:", l);
  print_list("lista l2:",l);

  l.sort();
  l2.sort();
//  l.remove_if(test_element);
//  l.pop_front();
  
  print_list("lista l:",  l);
  print_list("lista l2:", l2);

  l.merge(l2);

  print_list("lista l:",  l);
  print_list("lista l2:", l2);
*/

// In questo caso la lista è più pesante perchè l'oggetto studente viene memorizzata nella lista
/*
  list<Studente> ls1;
  ls1.push_front(Studente("Paperino","Paolino", "0000001"));//Quindi questa operazione di inserimento è più pesante
  ls1.front().print();
*/
//in questo caso invece la lista è più leggera perchè contiene solo puntatori a Studente e gli studenti vengono memorizzati nell'heap
  list<Studente *> ls;
  ls.push_front(new Studente("Paperino","Paolino", "0000002"));//se metto new, devo dichiarare una lista di puntatori a studente

  ls.push_front(new Studente("Paperone","Zio", "000000"));
  ls.push_front(new Studente("Qui","Nipote", "000003"));

  for (list<Studente*>::iterator i = ls.begin(); i != ls.end(); ++i){
  (*i)->print();
}
  //ls1.front()->print();
}
