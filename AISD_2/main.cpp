/*#������� ���������� ������ ��������� std::vector<int> -����������� ����� ���������.
#https://docs.google.com/document/d/1L-doO_8pcQJ2gBpHUw7w7zEiB3auwPjt/edit
#. ���������� �������
#   ���������� �����
#0. ���������� ������������
����������� ��������

1 000, 2 000, 3 000, �, 10 000,  25000, 50000, 100000:
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

stats sorting_choice(std::vector<int> Vector) {
	auto start = high_resolution_clock::now();
	bool needing_restart = false;
	stats A;
	int min = 0; // ��� ������ ������������ ��������
	int buf = 0; // ��� ������ ���������� 

	/*********** ������ ���������� **************/
	for (int i = 0; i < Vector.size(); i++)
	{

		min = i; // �������� ����� ������� ������, ��� ������ � ����������� ���������
		// � ����� ������ �������� ����� ������ � ����������� ���������
		for (int j = i + 1; j < Vector.size(); j++)
			min = (Vector[j] < Vector[min]) ? j : min;
		A.copy_count += 1;
		A.comparison_count += 1;
		// c������ ������������ ����� ��������, ������� ��� ������� � �������
		if (i != min)
		{
			buf = Vector[i];
			Vector[i] = Vector[min];
			Vector[min] = buf;
			A.copy_count += 3;
		}
		A.comparison_count += 1;
	}
	auto stop = high_resolution_clock::now();
	duration<double> duration = stop - start;
	A.time = (double)duration.count();
	return A;
}
stats sorting_shell(std::vector<int> Vector) {
	auto start = high_resolution_clock::now();
	stats A;
	for (int s = Vector.size() / 2; s > 0; s /= 2) {
		for (int i = s; i < Vector.size(); ++i) {
			for (int j = i - s; j >= 0 && Vector[j] > Vector[j + s]; j -= s) {
				int temp = Vector[j];
				Vector[j] = Vector[j + s];
				Vector[j + s] = temp;
				A.comparison_count += 1;
				A.copy_count += 3;
			}
		}
	}
	auto stop = high_resolution_clock::now();
	duration<double> duration = stop - start;
	A.time = (double)duration.count();

	return A;
}

