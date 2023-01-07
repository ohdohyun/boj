#include <iostream>
#include <algorithm>
using namespace std;

int result[501];
int input[501];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin >> N;
	cin >> input[1];
	result[1] = input[1];

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> input[j];

			if (j == 1) {
				input[j] += result[j];
			}
			else if (j == i) {
				input[j] += result[j - 1];
			}
			else {
				input[j] += max(result[j - 1], result[j]);
			}
		}

		for (int j = 1; j <= i; j++) {
			result[j] = input[j];
		}
	}


	int maxNum = result[1];
	for (int i = 2; i <= N; i++) {
		maxNum = max(maxNum, result[i]);
	}

	cout << maxNum << '\n';

	return 0;
}