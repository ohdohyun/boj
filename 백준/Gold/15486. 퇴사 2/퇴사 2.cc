#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/15486

int dp[1'500'002];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int t, p;
		cin >> t >> p;

		dp[i] = max(dp[i], dp[i - 1]);

		if (i + t - 1 <= n) {
			dp[i + t] = max(dp[i + t], dp[i] + p);
		}
		//cout << i << "번째 : " << dp[i] << '\n';
	}
	dp[n + 1] = max(dp[n], dp[n + 1]);
	cout << dp[n + 1] << '\n';

	return 0;
}