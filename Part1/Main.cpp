#include <iostream>
#include <cstdlib>
#include "Sorting.h"
#include "Instrumentor.h"

static const int32_t ARRAY_SIZE = 10000000;
static const int32_t MAX_RAND_VALUE = ARRAY_SIZE;
static const int32_t K = 1000;

Instrumentor Instrumentor::_Instance;

template<typename T, size_t N>
void fillArray(T arr[N], const int& max_value) { // Fill an array with random numbers
	for (size_t i = 0; i < N; ++i) {
		arr[i] = rand() % (max_value + 1);
	}
}

template<typename T, size_t N>
void copyArrayValues(T arrFrom[N], T arrTo[N]) { // Copy all values from one array to another
	for (size_t i = 0; i < N; ++i) {
		arrTo[i] = arrFrom[i];
	}
}

int main() {
	int* a = new int[ARRAY_SIZE];
	int* b = new int[ARRAY_SIZE];
	srand(58);
	fillArray<int, ARRAY_SIZE>(a, MAX_RAND_VALUE); // Fill array
	copyArrayValues<int, ARRAY_SIZE>(a, b); // Copy values from a to b
	sort<int, insertionSort>(a, ARRAY_SIZE, K); // aSort
	sort<int, bInsertionSort>(b, ARRAY_SIZE, K); // bSort
	Instrumentor::Get().Print(); // Print result

	// Error check
	for (int i = 1; i < ARRAY_SIZE; ++i) {
		if (a[i - 1] > a[i]) {
			std::cout << "\na:\n";
			std::cout << "ERROR at index " << i - 1 << " and " << i << ", value " << a[i - 1] << " more than " << a[i];
			std::cout << "\n";
		}
	}
	for (int i = 1; i < ARRAY_SIZE; ++i) {
		if (b[i - 1] > b[i]) {
			std::cout << "\nb:\n";
			std::cout << "ERROR at index " << i - 1 << " and " << i << ", value " << a[i - 1] << " more than " << a[i];
			std::cout << "\n";
		}
	}
	delete[] a;
	delete[] b;
}