#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, max = 0, sum = 0;
	int arr[1000] = {};

	double average = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];

		if (max < arr[i]) {
			max = arr[i];
		}

		
	}

	average = (double)(sum) / (double)max * 100 / N;
	
	cout << average << '\n';

	return 0;
}


