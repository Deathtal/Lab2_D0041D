#pragma once

template<typename T, size_t N>
void insertionSort(T arr[N]) {
	for (size_t i = 1; i < N; ++i) {
		for (size_t ii = 0; ii < i; ++ii) {
			if (arr[i] >= arr[ii]) {
				continue;
			}
			else {
				T temp_arr_element = arr[ii];
				arr[ii] = arr[i];
				arr[i] = temp_arr_element;
			}
		}
	}
}

template<typename T, size_t N>
void bInsertionSort(T arr[N]) {
	size_t sorted = 0;
	for (size_t i = 1; i < N; ++i) {
		
	}
}

int* binarySearch(int* arr, size_t size, int element) {
	if (arr[size /2] < element) {
		return binarySearch(arr[size /2]);
	}
	else if (arr[size / 2] > element) {
		return binarySearch(arr[size /2]);
	}
	else {
		return arr;
	}
}