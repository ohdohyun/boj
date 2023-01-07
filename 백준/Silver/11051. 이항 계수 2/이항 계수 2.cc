#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, k;
	cin >> n >> k;

	dp[0][0] = 1;
	
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			dp[i][j] %= 10007;
		}
	}
	
	cout << dp[n][k] << '\n';
	
	return 0;
}