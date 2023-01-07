#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/11055

int arr[1001];
int dp[1001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	int result = dp[0];
	for (int i = 1; i < n; i++) {
		int m = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				m = max(m, dp[j]);
			}
		}
		dp[i] = arr[i] + m;
		result = max(result, dp[i]);
	}

	cout << result << '\n';
	return 0;
}