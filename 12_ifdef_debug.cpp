/*
 g++ 12_ifdef_debug.cpp -o 12_ifdef_debug -DDEBUG
*/
#include <iostream>

#ifdef DEBUG
void debug(char *s)
{
  std::cout << "xxxxx: " << s << std:endl;
}
#else
void debug(char *s)
{
 //se non c'è debug settato non stampa nulla
}
#endif


int main()
{
  debug("stampa di debug");
}
