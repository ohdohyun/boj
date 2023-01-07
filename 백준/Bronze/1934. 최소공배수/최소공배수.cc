#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b;

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		int gcd, lcm = a * b;

		if (a < b) { swap(a, b); }

		while (true) {
			gcd = a % b;
			a = b;
			b = gcd;

			if (b == 0) {
				cout << lcm / a << '\n';
				break;
			}
		}
	}

	return 0;
}
