
#include <iostream>
#include "Header_zad2.h"

int main()
{
	int rows = 2;
	int cols = 2;

	double** A = alociraj_matricu(rows, cols);
	unos_matrice(rows, cols, A);

	return 0;
}