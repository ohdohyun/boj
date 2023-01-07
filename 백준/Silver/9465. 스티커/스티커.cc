#include <iostream>
#include <algorithm>

using namespace std;

int dp[2][100000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while (T-- != 0) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> dp[0][i];
		}
		for (int i = 0; i < n; i++) {
			cin >> dp[1][i];
		}

		dp[0][1] += dp[1][0];
		dp[1][1] += dp[0][0];
		//cout << "i=" << 1 << " : " << dp[0][1] << ' ' << dp[1][1] << '\n';
		for (int i = 2; i < n; i++) {
			dp[0][i] += max(dp[1][i - 2], dp[1][i - 1]);
			dp[1][i] += max(dp[0][i - 2], dp[0][i - 1]);


			//cout << i << " : " << dp[0][i] << ' ' << dp[1][i] << '\n';
		}


		cout << max(dp[0][n-1], dp[1][n-1]) << '\n';

	}

	return 0;
}
