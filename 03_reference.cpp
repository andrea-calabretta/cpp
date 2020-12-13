#include <iostream>

int main()
{
	int x = 3;
	int& y = x; //y è un alias di x, dentro y non c'è una copia di x ma è sempre un puntatore a x, solo che avendolo definito reference, il deferenziamento è automatico. Cioè, ogni volta che io scrivo "y", in realtà è come se scrivessi "*y". La stessa cosa che avveniva in java con gli oggetti

	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;
}
