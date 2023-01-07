#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/11047

int price[1'000'000];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}

	n--;
	int cnt = 0;
	while (k > 0) {
		if (k >= price[n]) {
			cnt += k / price[n];
			k %= price[n];
		}
		n--;
	}

	cout << cnt << '\n';

	return 0;
}