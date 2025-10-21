/*Napišite funkciju at koja vraća referencu na neki element C-niza. Koris-
teći povratnu vrijednost funkcije kao lvalue uvećajte i-ti element niza
za jedan.*/

#include <iostream>

int& at(int* c, unsigned i)
{
	return c[i];
}

int main()
{
	int c[] = { 1,2,3,4,5,6 };

	std::cout << "Prije: " << c[2] << std::endl;

	at(c, 2)+=1;

	std::cout << "Poslije: " << c[2] << std::endl;
	return 0;
}

