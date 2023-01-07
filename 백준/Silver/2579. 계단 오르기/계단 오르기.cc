#include <iostream>
#include <algorithm>
using namespace std;

int dp[301];
int arr[301];


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] =  arr[1] + arr[2];

	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
	}

	cout << dp[N] << '\n';
	

	return 0;
}