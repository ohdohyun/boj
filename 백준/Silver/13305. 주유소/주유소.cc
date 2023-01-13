#include <iostream>
#include <algorithm>

using namespace std;

int price[100001], dstnc[100001], price_copy[100001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> dstnc[i];
	}
	dstnc[N - 1] = 0;

	for (int i = 0; i < N; i++) {
		cin >> price[i];
		price_copy[i] = price[i];
	}


	sort(price_copy, price_copy + N);

	int sum_of_distance = 0, result = 0, position = 0;
	for (int i = N - 1; i >= 0; i--) {

		if (price_copy[position] == price[i]) {
			sum_of_distance += dstnc[i];
			result += sum_of_distance * price[i];
			position++;
			sum_of_distance = 0;
		}
		else {
			sum_of_distance += dstnc[i];
			if (i == 0) {
				result += sum_of_distance * price[i];
			}
		}
	}

	cout << result;


	return 0;
}
