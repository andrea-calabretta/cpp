#include <iostream>

using namespace std;
class Oggetto
{
  public:
    static int numero_oggetti;
    Oggetto();
};

  int Oggetto::numero_oggetti = 0;
  Oggetto::Oggetto() { ++numero_oggetti;}

int main()
{
  Oggetto o1;
  cout <<"o1 :" << o1.numero_oggetti << endl; // ->1

  Oggetto o2, o3;
  cout <<"Dopo o2 e o3, o1 ha numero_oggetti: " << o1.numero_oggetti << endl; // ->3

  cout <<"o3 ha numero_oggetti: " << o3.numero_oggetti <<endl;

  cout << "\nTutti gli oggetti hanno lo stesso valore dell'attributo statico!" << endl;

}
