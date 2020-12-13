#include <iostream>

class Data {
  public:
    int giorno; 
  public:
    Data();
    ~Data();
    
    Data & incrementa_giorno();
    Data*  incrementa_giorno2();
    Data   incrementa_giorno3();
    void stampa();
};


Data::Data()
{
  std::cout << "Istanza di Data creata" << std::endl;
  giorno = 1;
}

Data::~Data()
{
  std::cout << "Istanza distrutta" << std::endl;
}

Data & Data::incrementa_giorno()
{
  ++giorno;
  return *this; //restituisce un reference poichè "return this" restituirebbe un puntatore all'oggetto corrente; invece "return *this" restituisce l'oggetto puntato da this che è di tipo Data; se ci metto la "&", sto restituendo un reference all'oggetto corrente, quindi un alias.
}

Data* Data::incrementa_giorno2()
{
  ++giorno;
  return this;//restituisce un puntatore all'oggetto quindi il tipo di ritorno sarà Data*
}

Data Data::incrementa_giorno3()
{
  ++giorno;
  return *this; //restituisce una COPIA dell'oggetto puntato da this, a differenza di incrementa_giorno() in cui restituisco un puntatore all'oggetto corrente
}
void Data::stampa()
{
 std::cout <<" Il giorno è: "<< this->giorno <<std::endl;
}

int main()
{
 {
   Data d;
   d.incrementa_giorno();
   std::cout << " d.giorno è: " << d.giorno << std::endl;
   (d.incrementa_giorno2())->stampa(); //d.incrementa_giorno2() restituisce un puntatore, se voglio chiamare il metodo stampa devo fare "->" per deferenziarlo
   (d.incrementa_giorno3()).stampa();
 }
}



