#include <iostream>
#include <cstdlib>
#include "Sorting.h"

template<typename T, size_t N>
void fillArray(T arr[N]) {
	for (int i = 0; i < N; ++i) {
		arr[i] = rand() % 1001;
	}
}

int main() {
	int a[128];
	fillArray<int, 128>(a);
	for (auto i : a) {
		std::cout << i << ", ";
	}
	std::cout << "\n";
	std::cout << "\n";
	bInsertionSort<int, 128>(a);
	for (auto i : a) {
		std::cout << i << ", ";
	}
	std::cout << "\n";
	insertionSort<int, 128>(a);
	for (auto i : a) {
		std::cout << i << ", ";
	}
}