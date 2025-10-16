/*Napisati funkciju koja vraća niz int vrijednosti veličine n u kojem je svaki
element zbroj svoja dva prethodnika (Fibonacci). Prvi i drugi element u nizu
su jedinice. U main funkciji ispisati dobiveni niz i osloboditi memoriju.*/

#include <iostream>

int* zbroji(int n)
{
	if (n <= 0)
	{
		return nullptr;
	}

	int* niz = new int[n];

	niz[0] = 1;
	niz[1] = 1;

	for (int i = 2; i < n; i++)
	{
		niz[i] = niz[i - 1] + niz[i - 2];
	}

	return niz;
}

int main()
{
	int n = 6;

	int* rez=zbroji(n);

	if (rez != nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << rez[i] << " ";
		}
	}

	delete[] rez;

	return 0;
}