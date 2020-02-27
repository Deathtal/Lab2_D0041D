#include <iostream>
#include <cstdlib>
#include "Sorting.h"

template<size_t N>
void fillIntArray(int arr[N]) {
	for (size_t i = 0; i < N; ++i) {
		arr[i] = rand() % 1001;
	}
}

int main() {
	int a[128];
	fillIntArray<128>(a);
	for (auto i : a) {
		std::cout << i << ", ";
	}
	std::cout << "\n";
	insertionSort<int, 128>(a);
	for (auto i : a) {
		std::cout << i << ", ";
	}
	*binarySearch<int, 128>(a, 6) = 100;
	for (auto i : a) {
		std::cout << i << ", ";
	}
}