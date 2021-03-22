#include <fstream>

using namespace std;

int main() {
  ofstream fout("prova.txt");
  fout << "Ciao" ;
  fout.close();


}
