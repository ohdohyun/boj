#include <iostream>
#include <algorithm>
using namespace std;
int dp[31][1'001];
int p[1001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, w;
	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		if (p[i] == 1) { dp[0][i] = dp[0][i - 1] + 1; }
		else { dp[0][i] = dp[0][i - 1]; }
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {dp[j][i] = max(dp[j - 1][i - 1], dp[j][i - 1]) + ((p[i] % 2 == (j + 1) % 2) ? 1 : 0);}
	}
	int m = 0;
	for (int i = 0; i <= w; i++) { m = max(m, dp[i][n]); }
	cout << m;
	return 0;
}