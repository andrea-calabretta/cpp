#include <iostream>
 
using namespace std;

class Point {
  private:
    double x, y;
  public:
    Point(){
      Point(0.0, 0.0);
    }
    Point(double x, double y){
	this->x = x;
	this->y = y;
}
  friend void doActionOnPoint(Point &);
};

void doActionOnPoint(Point &p){
  cout << "(" << p.x << "," << p.y << ")" << endl;
}

int main(){
  Point p;
  int x;
  doActionOnPoint(p);

  cout << "Dammi un valore : ";
  cin >> x;

  cout << "Valore di x = " << std::hex << x << endl;
  //lo stesso risultato io posso ottenerlo andando a cambiare il flag e impostandolo ad esadecimale
  cout.setf(ios::hex, ios::basefield); //in questo modo io setto in modo permanente la formattazione
  cout << 100 << endl; //da ora in poi quello che stampo sarà esadecimale
  //se voglio fare l'unset
  cout.unsetf(ios::hex);
  cout << "Valore di x = " << x << endl;
  cout << 100 << endl;


}
