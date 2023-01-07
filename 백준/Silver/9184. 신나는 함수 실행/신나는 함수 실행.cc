#include <iostream>
#include <algorithm>

using namespace std;

int dp[21][21][21];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) { return 1; }

	if (a > 20 || b > 20 || c > 20) { return dp[20][20][20] = w(20, 20, 20); }

	if (dp[a][b][c] != 0) { return dp[a][b][c]; }

	if (a < b && b < c) { return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c); }

	return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int inputA, inputB, inputC;

	while (1) {
		cin >> inputA >> inputB >> inputC;
		if (inputA == -1 && inputB == -1 && inputC == -1) { break; }
		cout << "w(" << inputA << ", " << inputB << ", " << inputC << ") = " << w(inputA, inputB, inputC) << '\n';
	}

	return 0;
}


