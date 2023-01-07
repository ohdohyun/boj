#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
// https://www.acmicpc.net/problem/23888

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	unsigned long long int a, d;
	cin >> a >> d;

	int t;
	cin >> t;
	while (t--) {
		unsigned long long int n, l, r;
		cin >> n;
		if (n == 1) {
			cin >> l >> r;
			unsigned long long int temp = r - l + 1;
			cout << temp * a + temp * (temp - 1) / 2 * d + temp * (l - 1) * d << '\n';
		}
		else if (n == 2) {
			cin >> l >> r;
			if (l == r) { cout << a + (l - 1) * d << '\n'; continue; }
			unsigned long long int g = gcd(a + (l - 1) * d, a + l * d);
			cout << g << '\n';
		}
	}

	return 0;
}