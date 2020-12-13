#include <iostream>

//posso evidenziare il namespace ogni volta che utilizzo una funzione o una variabile che appartiene a quel namespace
/*
int main()
{
  std::cout << "Hello World!!" << std::endl;
}
*/

//Oppure, se sono pigro, posso scriverlo solo all'inizio e poi usare direttamente le variabili o le funzioni appartenenti a quel namespace ma devo stare molto attento a non creare conflitti di nomi

using namespace std;

int main() 
{
  cout << "Hello World!" << std:: endl;
}

