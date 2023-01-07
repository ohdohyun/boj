#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][1000001] = {};
int N, K;
int weight[101], value[101];

/*
void showMap() {
	int cnt = 1;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	
	cout << '\n';
}*/

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> weight[i] >> value[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {

			if (weight[i] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - weight[i]] + value[i], dp[i - 1][j]);
			}
		}
	}

	cout << dp[N][K];




	return 0;
}
