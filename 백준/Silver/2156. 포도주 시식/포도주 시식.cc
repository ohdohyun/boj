#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10001

int arr[MAX];
int dp[MAX];


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}

	if (N >= 1) {
		cout << dp[N];
	}


	return 0;
}