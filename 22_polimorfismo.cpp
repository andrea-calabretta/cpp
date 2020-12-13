#include <iostream>

using namespace std;

class Base
{
  public:
    Base(){
	cout << "costruttore Base() chiamato" << endl;
    
    }
    Base (int x){
	cout << "costruttore Base(int) chiamato" << endl;    }
    
    virtual void stampa(){
	cout << "Stampa qualcosa di... base" << endl;
    }
};

class Derivata: public Base {
  public:
    Derivata (): Base() {
	cout << "costruttore Derivata() chiamato" << endl;
	}
    Derivata (int x): Base(x){
	cout << "costrutture Derivata(int) chiamato" << endl;
	}

    void stampa(){
	cout << "Stampa qualcosa di...Derivata" << endl;
	//Base::stampa();
    }
};

int main()
{
	Derivata d;
	Base b;
	Derivata *pd = &d;
	Base *p = &d;//Qui assegno l'indirizzo di un oggetto di tipo derivata
	Base *p2 = &b;//qui assegno l'indirizzo di un oggetto di tipo base
	
	pd->stampa(); //non ci sono dubbi su quale "stampa()" viene chiamata perchè pd è puntatore a Derivata

	p->stampa(); //qui invece è polimorfismo, il compilatore deve capire quale metodo chiamare, siccome l'oggetto puntato è derivato chiamerà il metodo del derivato.
	p2->stampa();//stavolta l'oggetto puntato è di tipo base e quindi si chiama il metodo del tipo base
}

   
