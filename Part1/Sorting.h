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

template<typename T>
int binarySearch(T arr[], T item, int begin_i, int end_i) {
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
