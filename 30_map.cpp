#include <iostream>
#include <map>
#include <string>
using namespace std;

class Studente
{
	private:
		string nome, cognome;
	public:
//facciamo un costruttore di default perchè le mappe hanno bisogno di poter istanziare un elemento di default nel caso in cui cerchiamo di accedere ad una chiave che non esiste:
		Studente()
		{
			nome = "";
			cognome = "";
		}
//posso inizializzare i valori della classe ancora prima di entrare nel costruttore, così:
		Studente(string name, string surname): nome(name), cognome(surname){}
	
	void print()
	{
		cout << "Cognome: " << cognome << " Nome: " << nome << endl;
	}
};

int main()
{
	map<string, Studente> my_map;
	
	my_map["0123456"] = Studente("Giuseppe", "Mangioni");
	my_map["0123456"].print();
	
	map<string, Studente>::iterator findIter = my_map.find("0123456");
	if(findIter != my_map.end())
	  cout << "Elemento trovato! "<< endl;
	else
	  cout << "Elemento non trovato!" << endl;
}
