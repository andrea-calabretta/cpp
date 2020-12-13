class A{
  public:
    int a;
};

class B : public A{

};
/*
SCRIVERE ->

class B : A{}; 

EQUIVALE A SCRIVERE ->	

class B : private A{};
*/

int main()
{
  B b;
  
  b.a = 10;

}
