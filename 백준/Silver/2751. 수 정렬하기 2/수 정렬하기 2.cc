#include <iostream>
using namespace std;



void mergeSort(int* inputArr, int* sortedArr, int start, int end);
void merge(int* inputArr, int* sortedArr, int start, int end);


int main() {

	int N;
	cin >> N;

	int* dataArr = new int[N];
	int* tempArr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> dataArr[i];
	}

	mergeSort(dataArr, tempArr, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << dataArr[i] << ' ';
	}



	delete[] dataArr, tempArr;



	return 0;
}

void mergeSort(int* dataArr, int* tempArr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(dataArr, tempArr, start, mid);
		mergeSort(dataArr, tempArr, mid + 1, end);
		merge(dataArr, tempArr, start, end);
	}
}

void merge(int* dataArr, int* tempArr, int start, int end) {
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = start;

	while (i <= mid && j <= end) {
		if (dataArr[i] <= dataArr[j]) {
			tempArr[k] = dataArr[i];
			i++;
		}
		else {
			tempArr[k] = dataArr[j];
			j++;
		}
		k++;
	}

	if (i > mid) {
		for (int t = j; t <= end; t++) {
			tempArr[k] = dataArr[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			tempArr[k] = dataArr[t];
			k++;
		}
	}

	for (int t = start; t <= end; t++) {
		dataArr[t] = tempArr[t];
	}
}
