#include <iostream>
#include <string>

int print(int n, int low=1, int high=10)
{
	if (n < low)
	{
		return low;
	}
	else if (n > high)
	{
		return high;
	}
	else {
		return n;
	}
}
double print(double x, int low = 1.5, int high = 10.5)
{
	if (x < low)
	{
		return low;
	}
	else if (x > high)
	{
		return high;
	}
	else {
		return x;
	}
}

int main() {
	int n;
	double x;

	std::cout << print(2) << '\n';
	std::cout << print(0) << '\n';
	std::cout << print(12) << '\n';
	std::cout << print(2.5) << '\n';
	std::cout << print(1.1) << '\n';
	std::cout << print(15.3) << '\n';

	return 0;
}