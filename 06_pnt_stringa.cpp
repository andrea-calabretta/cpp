#include <iostream>

int main()
{
	char *p = "cavallo";
	char c1  = p[2];
	char c2  = *(p+2); // 2*sizeof(char) <-- ecco come lo traduce il compilatore, dentro le parentesi c'è il tipo degli elementi dell'array, in questa caso è un char
	
	std::cout << " *p = " << p << std::endl;
	std::cout << " p[2] = " << p[2] << std::endl;
	std::cout << " *(p+2) = " << *(p+2) << std::endl;
}

