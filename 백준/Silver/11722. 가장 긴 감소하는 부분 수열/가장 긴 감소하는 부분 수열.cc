#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/11722
int p[1001];
int dp[1001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = n; i >= 1; i--) {
		cin >> p[i];
	}

	int m = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (p[i] > p[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
				m = max(dp[i], m);
			}
		}
	}
	cout << m << '\n';

	return 0;
}