#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2473

#define ll long long
int arr[5'000];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	
	ll m = 3'000'000'001;
	int a, b, c;
	for (int i = 0; i < n - 2; i++) {
		ll standard = arr[i];

		ll st = i + 1, ed = n - 1;

		while (st < ed) {
			ll sum = standard + arr[st] + arr[ed];
			if (m > abs(sum)) {
				m = abs(sum);
				a = standard;
				b = arr[st];
				c = arr[ed];
			}
			else {
				if (sum > 0) { ed--; }
				else { st++; }
			}
		}
	}

	cout << a << ' ' << b << ' ' << c << '\n';


	return 0;
}