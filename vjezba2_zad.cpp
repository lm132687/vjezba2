/*Alocirati matricu na heapu. Napisati program za osnovne operacije s ma-
tricama čiji su elementi decimalni brojevi. Program treba imati sljedeće
funkcije:
· funkciju za unos matrice mxn,
· funkciju za generiranje matrice mxn s elementima u rasponu [a,b],
· funkcije za zbarajanje, oduzimanje, množenje matrica,
· funkciju za trasponiranje matrice,
· funkciju za ispisivanje matrice. Elementi matrice se ispisuju na četiri
decimale, poravnati udesno.*/

#include <iostream>
#include <iomanip>

double** alociraj_matricu(int rows, int cols)
{
	double** matrix = new double* [rows];
	for (int i = 0;i < rows;i++)
	{
		matrix[i] = new double[cols];
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

void ispisi_matricu(int rows, int cols, double** matrix)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << std::fixed << std::setprecision(4) << std::setw(10)<<"matrica [" << i << "][" << j << "]: " << matrix[i][j] << '\n';
		}
	}
}

void oslobodi_matricu(int rows, int cols, double** matrix)
{
	for (int i = 0;i < rows;i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void unesi_matricu(double** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << "Unesi element matrice [" << i << "][" << j << "]: ";
			std::cin >> matrix[i][j];
		}
	}
}

void generiraj_matricu(double** matrix, int rows, int cols, double a, double b)
{
	int n = rows * cols;
	double korak = 0;
	double aa = a;
	if (n > 1)
	{
		korak = (b - a) / (n - 1);
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = aa;
			aa += korak;
		}
	}
}

double** zbrajanje_matrice(int rows, int cols, double** matrix, double** matrix1)
{
	double** mat = alociraj_matricu(rows, cols);

	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++)
		{
			mat[i][j] = matrix[i][j] + matrix1[i][j];
		}
	}
	return mat;
}

double** oduzimanje_matrice(int rows, int cols, double** matrix, double** matrix1)
{
	double** mat = alociraj_matricu(rows, cols);

	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++)
		{
			mat[i][j] = matrix[i][j] - matrix1[i][j];
		}
	}
	return mat;
}

double** mnozenje_matrice(int row1, int col1, int row2, int col2, double** matrix, double** matrix1)
{

	if (col1 != row2)
	{
		return nullptr;
	}

	double** mat = alociraj_matricu(row1, col2);

	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			for (int k = 0; k < col1; k++)
				mat[i][j] += matrix[i][k] * matrix1[k][j];
		}
	}

	return mat;
}

double** transponiranje_matrice(int rows, int cols, double** matrix)
{
	double** mat = alociraj_matricu(cols, rows);

	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++)
		{
			mat[j][i] = matrix[i][j];
		}
	}
	return mat;
}

int main()
{
	int rows=2;
	int cols=2;
	double** A = alociraj_matricu(rows, cols);
	double** B = alociraj_matricu(rows, cols);

	generiraj_matricu(A, rows, cols, 1.5, 10.5);
	generiraj_matricu(B, rows, cols, 2, 8);

	double** rez2 = mnozenje_matrice(2, 2, 2, 2, A, B);

	double** rez = zbrajanje_matrice(rows, cols, A, B);

	double** rez1 = oduzimanje_matrice(rows, cols, A, B);

	double** rez3 = transponiranje_matrice(rows, cols, A);

	//ispisi_matricu(rows, cols, A);
	//ispisi_matricu(rows, cols, B);
	std::cout << "Zbrajanje" << '\n';
	ispisi_matricu(rows, cols, rez);

	std::cout << "Oduzimanje" << '\n';
	ispisi_matricu(rows, cols, rez1);


	std::cout << "Mnozenje" << '\n';
	ispisi_matricu(rows,cols, rez2);

	std::cout << "Transponiranje" << '\n';
	ispisi_matricu(cols, rows, rez3);

	oslobodi_matricu(rows, cols, A);
	oslobodi_matricu(rows, cols, B);
	oslobodi_matricu(rows, cols, rez);
	oslobodi_matricu(rows, cols, rez1);
	oslobodi_matricu(rows, cols, rez2);
	oslobodi_matricu(rows, cols, rez3);
	
	//unesi_matricu(A, rows, cols);
	return 0;
}

/*
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
		niz[i] = niz[i - 1] + niz[i-2];
	}

	return niz;
}

int main()
{
	int n=8;

	int* rez = zbroji(n);

	if (rez != nullptr)
	{
		for (int i = 0;i < n;i++)
		{
			std::cout << rez[i] << " ";
		}
		std::cout << std::endl;
		delete[] rez;
	}
	
	return 0;
}*/