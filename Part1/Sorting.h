#pragma once

template<typename T>
void insertionSort(T arr[], int N) {
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
	return binarySearch<T>(arr, item, begin_i, (begin_i + end_i + 1) / 2 - 1);
}

template<typename T>
void bInsertionSort(T arr[], int N) {
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
void merge(T arr[], int arrL_size, int arrR_size, T wsArr[]) {
	int arrL_i = 0;
	int arrR_i = arrL_size;
	int wsArr_i = 0;

	while (wsArr_i < arrL_size + arrR_size) {
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
	for (int i = 0; i < arrL_size + arrR_size; ++i) {
		arr[i] = wsArr[i];
	}
}

template<typename T, void (*func)(T*, int)>
void mergeSort(T arr[], int N, int k, T wsArr[]) {
	if (N <= k) {
		func(arr, N);
		
		//std::cout << N << ":[ "; // This is just so that I can show off how good my array looks when divided
		//for (int i = 0; i < N; ++i) {
		//	std::cout << arr[i] << " ";
		//}
		//std::cout << "]  ";
		
		return;
	}
	if (N % k == 0) { // For dividing the array into as many pieces of size k as possible. I wanted to figure out how to do it, so now it's here
		mergeSort<T, func>(arr, N - k * ((N / k) / 2), k, wsArr);
		mergeSort<T, func>(arr + N - k * ((N / k) / 2), k * ((N / k) / 2), k, wsArr);
		merge<T>(arr, N - k * ((N / k) / 2), k * ((N / k) / 2), wsArr);
	}
	else if (N <= N % k + N) { // Also for print prettiness
		mergeSort<T, func>(arr, k, k, wsArr);
		mergeSort<T, func>(arr + k, N - k, k, wsArr);
		merge<T>(arr, k, N - k, wsArr);
	}
	else { // Can use only this without the other if-statements if desired, but it wouldn't look as cool when you print out the divisions
		mergeSort<T, func>(arr, N / 2, k, wsArr);
		mergeSort<T, func>(arr + N - N / 2, N - N / 2, k, wsArr);
		merge<T>(arr, N / 2, N - N / 2, wsArr);
	}
}

template<typename T, void(*func)(T*, int)>
void sort(T arr[], int N, int k) {
	T* work_space_arr = new T[N];
	mergeSort<T, func>(arr, N, k, work_space_arr);
	delete[] work_space_arr;
}