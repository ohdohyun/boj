#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2725

int arr[1001];

int gcd(int a, int b) {
	int c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	arr[1] = 3;
	for (int i = 2; i <= 1000; i++) {
		int cnt = 0;
		for (int j = 1; j < i; j++) {
			if (gcd(i, j) == 1) { cnt++; }
		}
		arr[i] = arr[i - 1] + cnt * 2;
	}

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << arr[n] << '\n';
	}
	return 0;
}