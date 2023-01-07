#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/2293

int dp[10'001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = v[i]; j <= k; j++) {
			dp[j] += dp[j - v[i]];
		}
	}

	cout << dp[k] << '\n';

	return 0;
}