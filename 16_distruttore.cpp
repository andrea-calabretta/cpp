#include <iostream>

class C
{
  private:
    int a;

  public:
    C();
    ~C();
};

C::C()
{
  std::cout <<"Costruttore chiamato" << std::endl;
}

C::~C()
{
  std::cout <<"Distruttore chiamato" << std::endl;
}

int main()
{
  C *pc;

  std::cout <<"\nOggetto allocato" << std::endl;
  pc = new C();

  std::cout <<"Oggetto distrutto" << std::endl;
  delete pc;
//In caso di allocazione dinamica, dobbiamo essere noi esplicitamente a deallocare l'oggetto
  std::cout << "\n [ ALLOCAZIONE STATICA ]" << std::endl;

  {
     C c;
  }
}
//In caso di allocazione statica, appena siamo fuori dallo scope dell'oggetto, l'oggetto viene automaticamente rimosso dallo stack, essendo inaccessibile fuori dal suo scope

