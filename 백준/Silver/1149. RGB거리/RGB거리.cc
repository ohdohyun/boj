#include <iostream>
#include <algorithm>
using namespace std;

int dp[3][1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin >> N;
	int inputA, inputB, inputC;
	cin >> inputA >> inputB >> inputC;
	dp[0][1] = inputA;
	dp[1][1] = inputB;
	dp[2][1] = inputC;

	for (int i = 2; i <= N; i++) {
		cin >> inputA >> inputB >> inputC;
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + inputA;
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + inputB;
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + inputC;
	}

	int result = min(dp[0][N], dp[1][N]);
	result = min(result, dp[2][N]);

	cout << result << '\n';


	return 0;
}