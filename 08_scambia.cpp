#include <iostream>

void scambia1 (int x, int y)
{
	int tmp;
	
	tmp = x;
	x = y;
	y = tmp;
}

void scambia2 (int *px, int *py) //passaggio per valore
{
	int tmp;
	
	tmp = *px;
	*px = *py;
	*py = tmp;
}

void scambia3 (int &x, int &y)//passaggio per riferimento{
	int tmp;
	
	tmp = x;
	x = y;
	y = tmp;
}
int main()
{
	int i, j;
	
	i = 1;
	j = 10;
	
	std::cout << "Prima di scambia1 " << std::endl;
	std::cout << "i = " << i << ", j = " << j << std::endl;

	scambia1(i, j);
	std::cout << "Dopo di scambia1 " << std::endl;
	std::cout << "i = " << i << ", j = " << j << std::endl;
	
	scambia2(&i, &j);
	std::cout << "Dopo di scambia2 " << std::endl;
	std::cout << "i = " << i << ", j = " << j << std::endl;
	scambia3(i, j);
	std::cout << "Dopo di scambia3 " << std::endl;
	std::cout << "i = " << i << ", j = " << j << std::endl;
		
}

