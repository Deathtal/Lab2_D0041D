#pragma once

template<typename T>
void insertionSort(T arr[], size_t N) {
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
int binarySearch(T arr[], T item, size_t begin_i, size_t end_i) {
	if (begin_i >= end_i) {
		return (item > arr[begin_i]) ? (begin_i + 1) : begin_i;
	}
	if (arr[(begin_i + end_i) / 2] == item) {
		return (begin_i + end_i) / 2 + 1;
	}
	if (arr[(begin_i + end_i) / 2] < item) {
		return binarySearch<T>(arr, item, (begin_i + end_i) / 2 + 1, end_i);
	}
	return binarySearch<T>(arr, item, begin_i, (begin_i + end_i) / 2 - 1);
}

template<typename T, size_t N>
void bInsertionSort(T arr[N]) {
	int shift_i, selected, selected_pos;
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
void merge(T arr[], size_t N, size_t k) {
	T* left_arr = new T[N];
	T* right_arr = new T[k];
	for (int i = 0; i < k; ++i) {
		left_arr[i] = arr[i];
	}
	for (int i = k; i < k * 2; ++i) {

	}
}


template<typename T>
void aSort(T arr[], size_t N, size_t k) {
	if (N <= k) {
		insertionSort<T>(arr, N);
		
		std::cout << N << ":[ "; // This is just so that I can show off how good my array looks when divided
		for (size_t i = 0; i < N; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << "]  ";
		
		return;
	}
	if (N % k == 0) { // For dividing the array into as many pieces of size k as possible. I wanted to figure out how to do it, so now it's here
		aSort<T>(arr, N - k * ((N / k) / 2), k);
		aSort<T>(arr + N - k * ((N / k) / 2), k * ((N / k) / 2), k);
	}
	else if (N <= N % k + N) { // Also for print prettiness
		aSort<T>(arr, k, k);
		aSort<T>(arr + k, N - k, k);
	}
	else { // Can use only this without the other if-statements if desired, but it wouldn't look as cool when you print out the divisions
		aSort<T>(arr, N / 2, k);
		aSort<T>(arr + N / 2, N / 2, k);
	}
	merge<T>(arr, N, k);
}