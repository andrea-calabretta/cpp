#include <iostream>

using namespace std;

class Vehicle{
  protected:
    double acc;
	
  public:
    Vehicle(){
	acc = 0;
    }
 void  setAcceleration(double a){
    acc = a;
  }  
  double getAcceleration(){
    return acc; 
  }
};

class Car: virtual  public Vehicle{

   public:
     Car(){
	cout << "Costruttore di Car" << endl;
}
     virtual void guida(){
	cout << "guida auto" << endl;
     }
     void stampa(){
	cout << "sono una Car" << endl;
     }
};

class Jet: virtual public Vehicle{
  public:
    Jet(){
	      cout << "Costruttore di Jet" << endl;
	}
  virtual void vola(){
	cout << "sto volando" << endl;
  }
  void stampa(){
	cout << "sono un Jet" << endl;
  }
};

   
class JetCar: public Car, public Jet{
  public:
     JetCar(){
	cout << "Costruttore di JetCar" << endl;
  }
  virtual void guida(){
	cout << "guida JetCar" << endl;
  }
  virtual void vola(){
	cout << "JetCar volo!" << endl;
  }
  void stampa(){
     Car::stampa();
  }
  
};


int main(){
  JetCar myJetCar;
  
  //myJetCar.setAcceleration(10.7); //se faccio così, il compilatore non capisce se voglio utilizzare il metodo setAccelerarion di Car o di Jet e quindi devo specificarlo
  myJetCar.Jet::setAcceleration(10.7);
  cout << "Acceleration = " << myJetCar.Car::getAcceleration() << endl;
  myJetCar.Car::stampa();

  myJetCar.stampa(); //posso farlo dopo aver specificato a riga 59 che si riferisce a quello di Car (metodo chaining up ovvero riscrivo il metodo dentro la classe JetCar), altrimenti dovevo specificarlo come al rigo precedente, a quale classe facevo riferimento sul metodo stampa

}
