#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2302

int dp[41];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	dp[0] = dp[1] = 1;
	for (int i = 2; i <= 40; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int n, m;
	cin >> n >> m;

	int standard = 0, k = 1, input;
	for (int i = 0; i < m; i++) {
		cin >> input;
		k *= dp[input - standard - 1];
		standard = input;
		//cout << input << ", " << k << '\n';
	}
	if (m == 0) {
		cout << dp[n] << '\n';
	}
	else {
		k *= dp[n - input];
		cout << k << '\n';
	}
	
	return 0;
}