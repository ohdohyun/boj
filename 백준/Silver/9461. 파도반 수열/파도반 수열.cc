#include <iostream>

using namespace std;

long long int dp[101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for (int j = 4; j <= 100; j++) {
		dp[j] = dp[j - 2] + dp[j - 3];
	}

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		cout << dp[N] << '\n';

	}

	return 0;
}


