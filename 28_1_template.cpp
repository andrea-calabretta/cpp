/*
	Il formato per dichiarare funzioni template con parametri tipo è:
		template <class identifier> function_declaration;
		template <typename identifier> function_declaration;
*/
#include <iostream>
using namespace std;

template <typename T>
T GetMax(T a, T b){
	return (a>b?a:b);
}

template <class T>
T GetMin(T a, T b){
	return(a<b?a:b);
}

int main(){
	cout << "The max is: " <<  GetMax <int>(4,5) << endl;
	cout << "The max is: " << GetMax <float>(4.9, 4.8)<< endl;
	cout << "The mix is: " <<  GetMin <int>(4,5) << endl;
	cout << "The min is: " << GetMin <float>(4.9, 4.8)<< endl;

}
