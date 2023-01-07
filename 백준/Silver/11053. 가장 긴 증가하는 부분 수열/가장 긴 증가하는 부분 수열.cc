#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001

int input[MAX];
int dp[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input[i];
	}

	int result = 0;

	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (input[j] < input[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}

		result = max(dp[i], result);
	}

	cout << result;

	return 0;
}