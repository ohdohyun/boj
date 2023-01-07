#include <iostream>
#include <algorithm>

using namespace std;

long long dp[91];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	dp[1] = 1;
	dp[2] = 1;
	
	int n;
	cin >> n;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[n] << '\n';
	

	return 0;
}
