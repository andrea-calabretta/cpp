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
    
    void stampa(){
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
	Base::stampa();
    }
};

int main()
{
	Derivata d1;
	Derivata d2(10);
}
