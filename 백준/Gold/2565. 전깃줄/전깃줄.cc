#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 101
int dp[100];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<pair<int, int>> v;

	int N; cin >> N;
	int a, b;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		v.push_back(pair(a, b));
	}

	sort(v.begin(), v.end());					// A라인 기준으로 오름차순 정렬

	int result = 0;
	for (int i = 0; i < N; i++) {				// 정렬된 B라인에서 수열의 최장길이 구함
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}

		result = max(result, dp[i]);
	}

	cout << N - result;							// 전체에서 최장길이 빼서 출력
	

	return 0;
}