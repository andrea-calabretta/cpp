#include <iostream>
#include <fstream>

using namespace std;

int main(){
  char s[10];
  
  ifstream fin("prova.txt");
  while(!fin.eof()){
    fin >> s;
    cout << s << endl;
  }
  fin.close();
}
