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
  doActionOnPoint(p);

}
