#include <iostream>
#include <map>

using namespace std;

class Studente
{
	private:
		string nome, cognome;
	public:
//facciamo un costruttore di default perchè le mappe hanno bisogno di poter
// istanziare un elemento di default nel caso in cui cerchiamo di accedere ad una chiave che 
// non esiste:
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
class Date
{
	private:
		int giorno, mese, anno;
	
	public:
		Date(int g, int m, int a){
		  giorno = g;
		  mese = m;
		  anno = a;
		}	
		bool operator<(const Date &d) const{
		  if (anno < d.anno)
		    return true;
		  else if (anno == d.anno)
		  {
		    if (mese < d.anno)
		      return true;
		    else if (mese == d.mese)
		      return (giorno < d.giorno);
		  }
		}
};

int main()
{
	map<Date, Studente> my_map;
	my_map[Date(27, 11, 2020)] = Studente("Giuseppe", "Mangioni");

	my_map[Date(27, 11, 2020)].print();
	
}

