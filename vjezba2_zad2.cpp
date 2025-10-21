/*Definirati strukturu koja opisuje vektor. Struktura se sastoji od niza int
elemenata, logičke i fizičke veličine niza.
· Logička veličina - stvarni broj elemenata u vektoru,
· Fizička veličina - alocirani kapacitet memorije.
Fizička veličina je inicijalno init, a kada se ta veličina napuni vrijednostima,
alocira se duplo.
Napisati funkcije:
· vector_new - kreira novi vektor s početnim kapacitetom,
· vector_delete - oslobađa memoriju vektora,
· vector_push_back - dodaje element na kraj vektora (ako logička veličina
prelazi kapacitet, alocira se duplo),
· vector_pop_back - uklanja element s kraja vektora,
· vector_front - vraća prvi element vektora,
· vector_back - vraća zadnji element vektora,
· vector_size - vraća logičku veličinu vektora.
Funkcije nisu članovi strukture.*/
#include <iostream>
#include <cstdlib>

typedef struct {
	int* niz;
	size_t velicina;
	size_t kapacitet;

}vektor;

vektor* vector_new(size_t init_kapacitet)
{
	vektor* v = new vektor;

	v->niz = new int[init_kapacitet];
	v->velicina = 0;
	v->kapacitet = init_kapacitet;
	return v;
}

void vector_delete(vektor* v)
{
	delete[] v->niz;
	delete v;
}

void vector_push_back(vektor* v, int vrijednost)
{
	if (v->velicina >= v->kapacitet)
	{
		size_t novi_kapacitet = v->kapacitet * 2;
		int* novi_niz = new int[novi_kapacitet];
		for (int i = 0;i < v->velicina;i++)
		{
			novi_niz[i] = v->niz[i];
		}
		delete[] v->niz;
		v->niz = novi_niz;
		v->kapacitet = novi_kapacitet;
	}
	v->niz[v->velicina++] = vrijednost;
}

void vector_pop_back(vektor* v)
{
	if (v->velicina > 0)
	{
		v -> velicina--;
	}
}

int vector_front(vektor* v)
{
	if (v->velicina == 0)
	{
		return 0;
	}
	return v->niz[0];
}

int vector_back(vektor* v)
{
	if (v->velicina == 0)
	{
		return 0;
	}
	return v->niz[v->velicina-1];
}

int vector_size(vektor* v)
{
	return v->velicina;
}

int main()
{
	vektor* v = vector_new(2);
	vector_push_back(v, 1);
	vector_push_back(v, 2);
	vector_push_back(v, 3);

	std::cout << "Prije promjene" << '\n';
	std::cout << "Prvi element: " << vector_front(v) << '\n';
	std::cout << "Zadnji element: " << vector_back(v) << '\n';
	std::cout << "Velicina: " << vector_size(v) << '\n';

	std::cout << "Nakon promjene" << '\n';
	vector_pop_back(v);
	std::cout << "Prvi element: " << vector_front(v) << '\n';
	std::cout << "Zadnji element: " << vector_back(v) << '\n';
	std::cout << "Velicina: " << vector_size(v) << '\n';

	vector_delete(v);

	return 0;
}

