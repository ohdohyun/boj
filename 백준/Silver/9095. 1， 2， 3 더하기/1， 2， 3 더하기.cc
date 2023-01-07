#include <iostream>
#include <algorithm>

using namespace std;

int dp[11];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	int N, input;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		cout << dp[input] << '\n';
	}

	return 0;
}
