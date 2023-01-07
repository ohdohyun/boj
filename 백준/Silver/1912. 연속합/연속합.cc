#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000

int input[MAX];
int dp[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	dp[0] = input[0];
	int result = input[0];

	for (int i = 1; i < N; i++) {

		if (dp[i-1] > 0) {
			dp[i] = dp[i - 1] + input[i];
		}
		else { dp[i] = input[i]; }
		result = max(result, dp[i]);
	}

	cout << result;
	

	return 0;
}