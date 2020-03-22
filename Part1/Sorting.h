#pragma once

#include "InstrumentationTimer.h"

template<typename T>
void insertionSort(T arr[], int N) { // Insertion sort
	InstrumentationTimer timer("insertionSort");
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

template<typename T>
int binarySearch(T arr[], T item, int begin_i, int end_i) { // Binary search
	if (begin_i >= end_i) {
		return (item > arr[begin_i]) ? (begin_i + 1) : begin_i;
	}
	if (arr[(begin_i + end_i) / 2] == item) {
		return (begin_i + end_i) / 2 + 1;
	}
	if (arr[(begin_i + end_i) / 2] < item) {
		return binarySearch<T>(arr, item, (begin_i + end_i) / 2 + 1, end_i);
	}
	return binarySearch<T>(arr, item, begin_i, (begin_i + end_i + 1) / 2 - 1);
}

template<typename T>
void bInsertionSort(T arr[], int N) { // Binary search insertion sort
	InstrumentationTimer timer("bInsertionSort");
	int selected, shift_i, selected_pos;
	for (int i = 1; i < N; ++i) {
		shift_i = i - 1;
		selected = arr[i];
		selected_pos = binarySearch(arr, selected, 0, shift_i);
		while (shift_i >= selected_pos) {
			arr[shift_i + 1] = arr[shift_i];
			shift_i--;
		}
		arr[shift_i + 1] = selected;
	}
}

template<typename T>
void merge(T arr[], int arrL_size, int arrR_size, T wsArr[]) { // Merges two parts of an array
	int arrL_i = 0; // Index of left array
	int arrR_i = arrL_size; // Index of right array
	int wsArr_i = 0; // work_space_arr used to store the sorted array 

	while (wsArr_i < arrL_size + arrR_size) { // Repeat until all elements has been merged into work_space_arr
		// Insert the smallest value between the elements at index arrL_i and arrR_i into work_space_arr[wsArr_i]
		if ((arrR_i < arrL_size + arrR_size && arr[arrL_i] > arr[arrR_i]) || arrL_i > arrL_size - 1) {
			wsArr[wsArr_i] = arr[arrR_i];
			arrR_i++;
		}
		else {
			wsArr[wsArr_i] = arr[arrL_i];
			arrL_i++;
		}
		wsArr_i++;
	}
	for (int i = 0; i < arrL_size + arrR_size; ++i) { // Copy all data from the work_space_arr to the original array
		arr[i] = wsArr[i];
	}
}

template<typename T, void (*func)(T*, int)>
void mergeSort(T arr[], int N, int k, T wsArr[]) {
	if (N <= k) {
		func(arr, N); // Calls insertionSort or bInsertionSort (or some other function if you pass that through the template)
		return;
	}
	// The if statements bellow are pretty much pointless and are only there because I wanted to divide each array into as many parts of size k.
	//For example an array of 12 elements with k = 4 would be divide into three 4 size arrays instead of four 3 size arrays (because you divide in half until n<=k, (12 / 2) / 2 == 3 < 4)
	if (N % k == 0) {
		mergeSort<T, func>(arr, N - k * ((N / k) / 2), k, wsArr);
		mergeSort<T, func>(arr + N - k * ((N / k) / 2), k * ((N / k) / 2), k, wsArr);
		merge<T>(arr, N - k * ((N / k) / 2), k * ((N / k) / 2), wsArr);
	}
	else if (N <= N % k + N) {
		mergeSort<T, func>(arr, k, k, wsArr);
		mergeSort<T, func>(arr + k, N - k, k, wsArr);
		merge<T>(arr, k, N - k, wsArr);
	}
	else { // Can use only this without the other if-statements if desired
		mergeSort<T, func>(arr, N / 2, k, wsArr); // Left half
		mergeSort<T, func>(arr + N - N / 2, N - N / 2, k, wsArr); // Right half
		merge<T>(arr, N / 2, N - N / 2, wsArr); // Merge
	}
}

template<typename T, void(*func)(T*, int)>
void sort(T arr[], int N, int k) {
	const char* sortType = "aSort"; // Name of timer
	if (__FUNCSIG__ == "void __cdecl sort<int,void __cdecl bInsertionSort<int>(int [],int)>(int [],int,int)") { // If bInsertionSort is used then change the name of the timer
		sortType = "bSort";
	}
	InstrumentationTimer timer(sortType); // Create timer

	T* work_space_arr = new T[N]; // Array used for storing data when moving elements in the target array
	mergeSort<T, func>(arr, N, k, work_space_arr);
	delete[] work_space_arr;
}