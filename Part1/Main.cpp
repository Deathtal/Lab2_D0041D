#include <iostream>
#include <cstdlib>
#include "Sorting.h"

static const size_t ARRAY_SIZE = 12;

template<typename T, size_t N>
void fillArray(T arr[N], const int& max_value) {
	for (int i = 0; i < N; ++i) {
		arr[i] = rand() % (max_value + 1);
	}
}

int main() {
	int a[ARRAY_SIZE];
	fillArray<int, ARRAY_SIZE>(a, 100);
	/*for (auto i : a) {
		std::cout << i << ", ";
	}*/
	std::cout << "\n";
	std::cout << "\n";
	aSort<int>(a, ARRAY_SIZE, 4);
	/*for (int i = 1; i < ARRAY_SIZE; ++i) {
		if (a[i-1] > a[i]) {
			std::cout << "\n\n";
			std::cout << "ERROR at index " << i - 1 << " and " << i << ", value " << a[i - 1] << " more than " << a[i];
			std::cout << "\n";
		}
	}*/
	std::cout << "\n";
	std::cout << "\n";
	for (auto i : a) {
		std::cout << i << ", ";
	}
	std::cout << "\n";
}