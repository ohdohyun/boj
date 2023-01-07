#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][10];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 9; i >= 0; i--) {
		dp[0][i] = 10 - i;
	}

	for (int row = 1; row < n; row++) {
		for (int col = 9; col >= 0; col--) {

			if (col == 9) { dp[row][col] = dp[row - 1][col]; }
			else { dp[row][col] = (dp[row - 1][col] + dp[row][col + 1]) % 10007; }
		}
	}

	cout << dp[n - 1][0] << '\n';

	return 0;
}
