/*
  Per definire il flag, in fase di compilazione bisogna usare l'opzione per definire il flag, e poi tutto attaccatto il nome del flag, così:

g++ 11_ifdef.cpp -o 11_ifdef -DDEBUG
 
altrimenti lui considererà il codice relativo all' #else
*/
#include <iostream>

#ifdef DEBUG
void stampa(char *s)
{
  std::cout << "Questa è una stampa più ricca: " << s << std::endl;

}

#else
void stampa(char *s)
{

  std::cout << s << std::endl;
}
#endif


int main() 
{
  stampa("ciao");
}
