#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/

long long arr[1'000'001];
long long sum[1'000'001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 1'000'000; i++) {
		for (int j = 1; i * j <= 1'000'000; j++) {
			arr[i * j] += i;
		}
	}
	for (int i = 1; i <= 1'000'000; i++) {
		sum[i] = arr[i] + sum[i - 1];
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << sum[n] << '\n';
	}

	return 0;
}