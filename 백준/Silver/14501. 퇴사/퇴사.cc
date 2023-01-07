#include <iostream>
#include <algorithm>

using namespace std;

int dp[16] = {};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, t, p, temp = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> t >> p;

		if (i + t - 1 <= n) {
			dp[i + t - 1] = max(temp + p, dp[i + t - 1]);
		}

		temp = max(temp, dp[i]);

	}
	
	cout << temp;

	return 0;
}
