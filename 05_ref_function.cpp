#include <iostream>

 void f1(int *p)
{ 

 std::cout << "stampa parametro in f1 = " << *p << std::endl;

}

void f2(int &r) 
{

 r++; //è come se ci fosse (*r)++ se fosse stato un puntatore, ma siccome è un reference, il deferenziamento è automatico
 std::cout << "stampa parametro in f2 = " << r << std::endl;

}

int main()
{
 int x = 5;
 int *px = &x;
 int &rx = x;

 std::cout << "x = " << x << std::endl;
 std::cout << "*p = " << *px << std::endl;
 std::cout << "&x = " << rx << std::endl;

 f1(&x);
 f2(x);
}

