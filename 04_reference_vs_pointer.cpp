#include <iostream>

int main ()
{
	int x   = 5;
	int *p  = &x; //puntatore a x
	int &rx = x; //reference a x

	std::cout <<" *p = "<< *p << std::endl;
	std::cout <<" rx = "<< rx << std::endl;
	std::cout <<" p = "<< p << std::endl;
	std::cout <<" &rx = "<< &rx << std::endl;
}

