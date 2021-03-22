#include <iostream>
#include <map>

using namespace std;

void print_map(map<int, char> &m, string s)
{
	cout << s << endl;
//	la mappa si scorre con gli iteratori
	for (map<int, char>::iterator it = m.begin(); it !=m.end(); ++it) 	
	   cout << "Key: " << it-> first << " Value: " << it->second << endl;
}	

bool my_find_func (const pair<int, char> &p)
{
//in questo caso facciamo una ricerca per valore
	return(p.second == 'B');

}
int main()
{
	map<int, char> my_map;
	
	my_map[1] = 'A';
	my_map[2] = 'B';
	my_map[3] = 'C';

	print_map(my_map, "Stampa my_map dopo inserimento");
	
	cout << my_map[2] << endl;
	//se io provo ad accedere ad un elemento di chiave inesistente, vediamo cosa succede...
//	cout << my_map[5] << endl;
	//succede che provoco l'inserimento a quella chiave di un valore di default, in questo caso un carattere vuoto, quindi bisogna accertarsi che quando si accede ad una certa chiave, quella chiave esiste altrimenti si può incorrere in qualche problema
	print_map(my_map, "Stampa my_map dopo ");
	
	try{
	     cout << my_map.at(5) << endl;
	}
	catch(out_of_range &e){
	     cout <<e.what() << endl; //mi da informazioni sull'eccezione verificata
	}
	print_map(my_map, "Stampa my_map dopo accesso chiave non esistente ");
	
	map<int, char>::iterator findIter = my_map.find(2);
	if(findIter != my_map.end())
	  cout <<" -->  Key: 2" << " Value: " << findIter->second << endl;
	else
 	  cout  << "Key not present!" << endl;


	map<int, char>::iterator findIt = my_map.find(5);
	if(findIt != my_map.end())
	  cout <<" -->  Key: 2" << " Value: " << findIt->second << endl;
	else
 	  cout  << "Key not present!" << endl;
	
	//my_map.erase(2);
	
	print_map(my_map, "Stampa my_map dopo erase:");
	
	map<int, char>::iterator findIfIter = find_if(my_map.begin(), my_map.end(), my_find_func);
	if(findIfIter != my_map.end())
		cout << "Key: " << findIfIter->first << " Value: " << findIfIter->second << " found!" << endl;
	else
		cout << "Find Failed!" << endl;
}
