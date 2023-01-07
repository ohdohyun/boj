#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int result = 0;
	for (int i = 0; i < N; i++) {
		result += arr[i] * (N - i);
	}
	cout << result;



	return 0;
}
