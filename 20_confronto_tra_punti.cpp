#include <iostream>

using namespace std;

class Point2
{
  private:
    double v[2];

  public:
    Point2(){
      Point2(0,0);
    }

    Point2(double x, double y)
    {
      v[0] = x;
      v[1] = y;
    }

    void print(){
      cout << "(" << v[0] << "," << v[1] << ")" << endl;
    }

    Point2 operator+(const Point2 &p) const
    {
      return Point2(v[0] + p.v[0], v[1] + p.v[1]);
    }

    Point2& operator= (const Point2 &p) //stavolta non c'è const perchè dovendo fare l'assegnazione, andremo a modificare il point2 che invoca la funzione che è referenziato tramite this
    {
      v[0] = p.v[0];
      v[1] = p.v[1];
      return *this; //ritorna il reference all'oggetto su cui facciamo l'assegnazione
    }

    Point2& operator+=(const Point2 &p)
    {
      v[0] += p.v[0];
      v[1] += p.v[1];
      return *this;
    }

    bool operator== (const Point2 &p)    {
      return (v[0] == p.v[0]) && (v[1] == p.v[1]);
    }

    bool operator!= (const Point2 &p){
      return (v[0] != p.v[0]) || (v[1] != p.v[1]);  
    }

    bool operator< (const Point2 &p){
      return v[1] != p.v[1] ? v[1] < p.v[1] : v[0] < p.v[0];
    }
   
    bool operator[] (int pos){
      return v[pos];
    }

    bool operator() (int pos){
      return v[pos];
    }
};

int main()
{
  Point2 p1(1,2), p2(10,5), p3(2,7);

  cout <<"\n p1, p2, p3: " << endl;
  p1.print();
  p2.print();
  p3.print();

  cout << "\nSomma di p1 + p2:" << endl; 
  (p1 + p2).print();
  cout << "\nSomma di p1 + p2 + p3:" << endl;
  ((p1 + p2) + p3).print();

  Point2 p4 = p1 + p2 + p3; //overloading operatore "="
  cout <<"\np4:" << endl;
  p4.print();
  
  cout <<"\np5: " << endl;
  Point2 p5 = (p4 += p1);
  p5.print();

  if ( p1 == p2)
	cout << "I due punti sono uguali" << endl;
  else
	cout << "I due punti sono diversi" << endl;

  if ( p1 != p2)
	cout << "I due punti sono diversi" << endl;
  else
	cout << "I due punti sono uguali" << endl;
  if (p1 < p2)
	cout << "Primo punto minore del secondo" << endl;
  else
	cout << "Primo punto maggiore del secondo"<<endl;

  cout << "Prima coordinata di p3: " <<p3[0] << endl;
  cout << "Seconda coordinata di p3: " <<p3[1] << endl;

  cout << "Prima coordinata di p3: " <<p3(0) << endl;
  cout << "Seconda coordinata di p3: " <<p3(1) << endl;

}


