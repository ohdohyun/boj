#include <iostream>
#include <algorithm>

using namespace std;

int input[1001];
int dp[1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			dp[j] = max(dp[j], input[i] + dp[j - i]);
		}

	}

	cout << dp[n] << '\n';


	return 0;
}
