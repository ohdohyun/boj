#include<iostream>
using namespace std;


int main() {

	int N, M;
	cin >> N >> M;
	int *arr = new int[N];
	int result = 0, sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum >=result && sum <= M) {
					result = sum;
				}

			}
		}
	}

	cout << result << endl;

	delete[] arr;

	return 0;

}
