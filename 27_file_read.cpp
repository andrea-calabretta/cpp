#include <iostream>
#include <fstream>

using namespace std;

int main(){
  char s[10];
  
  ifstream fin("prova.txt");
  fin >> s;
  cout << s << endl;
  fin.close();
}
