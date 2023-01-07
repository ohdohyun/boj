#include <iostream>
#include <algorithm>

using namespace std;

int price[100001], dstnc[100001];

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
	}

	long long sum_of_distance = 0, result = 0;
	int fuel = 1000000001;

	for (int i = 0; i < N; i++) {
		if (price[i] < fuel) {
			fuel = price[i];
		}
		result += static_cast<long long>(fuel) * dstnc[i];
		
	}

	cout << result;


	return 0;
}
