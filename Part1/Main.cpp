#include <iostream>
#include <cstdlib>
#include "Sorting.h"

static const size_t ARRAY_SIZE = 1000;
static const int MAX_RAND_VALUE = 100;
static const int K = 69;

template<typename T, size_t N>
void fillArray(T arr[N], const int& max_value) {
	for (size_t i = 0; i < N; ++i) {
		arr[i] = rand() % (max_value + 1);
	}
}

int main() {
	int a[ARRAY_SIZE];
	srand(10);
	fillArray<int, ARRAY_SIZE>(a, MAX_RAND_VALUE);
	sort<int, bInsertionSort>(a, ARRAY_SIZE, K);
	/*std::cout << "\n";
	for (auto i : a) {
		std::cout << i << ", ";
	}*/
	for (int i = 1; i < ARRAY_SIZE; ++i) {
		if (a[i - 1] > a[i]) {
			std::cout << "\n\n";
			std::cout << "ERROR at index " << i - 1 << " and " << i << ", value " << a[i - 1] << " more than " << a[i];
			std::cout << "\n";
		}
	}
	srand(10);
	fillArray<int, ARRAY_SIZE>(a, MAX_RAND_VALUE);
	sort<int, insertionSort>(a, ARRAY_SIZE, K);
	/*for (auto i : a) {
		std::cout << i << ", ";
	}
	std::cout << "\n";*/
	for (int i = 1; i < ARRAY_SIZE; ++i) {
		if (a[i - 1] > a[i]) {
			std::cout << "\n\n";
			std::cout << "ERROR at index " << i - 1 << " and " << i << ", value " << a[i - 1] << " more than " << a[i];
			std::cout << "\n";
		}
	}
}