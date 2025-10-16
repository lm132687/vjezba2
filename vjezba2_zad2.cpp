/*Alocirati matricu na heapu. Napisati program za osnovne operacije s ma-
tricama čiji su elementi decimalni brojevi.
Program treba imati sljedeće
funkcije:
· funkciju za unos matrice mxn,
· funkciju za generiranje matrice mxn s elementima u rasponu [a,b],
· funkcije za zbarajanje, oduzimanje, množenje matrica,
· funkciju za trasponiranje matrice,
· funkciju za ispisivanje matrice. Elementi matrice se ispisuju na četiri
decimale, poravnati udesno.*/
#include <iostream>
#include "Header_zad2.h"

double** alociraj_matricu(int rows, int cols)
{
	double** matrix = new double*[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];
	}
	return matrix;
}

void unos_matrice(int rows, int cols, double** matrix)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << "Unesi matricu: " << "[" << i << "][" << j << "]" << "\n";
			std::cin >> matrix[i][j];
		}
	}
}