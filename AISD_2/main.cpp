/*#‘ункции сортировки должны принимать std::vector<int> -сортируемый набор элементов.
#https://docs.google.com/document/d/1L-doO_8pcQJ2gBpHUw7w7zEiB3auwPjt/edit
#. —ортировка выбором
#   —ортировка Ўелла
#0. —ортировка естественным
двухпутевым сли€нием

1 000, 2 000, 3 000, Е, 10 000,  25000, 50000, 100000:
*/
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std::chrono;

struct stats {
	long comparison_count = 0;
	long copy_count = 0;
	double time = 0;
};
size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

std::vector<int> create_vector(int N, int chose) {
	std::vector<int> TMP;
	if (chose == 1)
	{
		for (int i = 0; i < N; i++)
		{
			TMP.push_back(lcg());
		}
	}
	else if (chose == 2)
	{
		for (int i = 0; i < N; i++)
		{
			TMP.push_back(i);
		}

	}
	else {
		for (int i = N; i > 0; i--)
		{
			TMP.push_back(i);
		}

	}
	return TMP;
}

