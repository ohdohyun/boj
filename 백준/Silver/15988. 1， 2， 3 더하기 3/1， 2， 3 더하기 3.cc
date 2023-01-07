#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/15988

int dp[1'000'001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 1'000'000; i++) {
		dp[i] = ((dp[i - 1] + dp[i - 2]) % 1'000'000'009 + dp[i - 3]) % 1'000'000'009;
	}

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	
	return 0;
}