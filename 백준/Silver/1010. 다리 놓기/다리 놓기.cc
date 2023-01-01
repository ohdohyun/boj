#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;

		int result = 1;
		int r = 1;
		for (int j = m; j > m - n; j--) {
			result *= j;
			result /= r++;
		}

		cout << result << '\n';
	}
	

	return 0;
}
