#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
// https://www.acmicpc.net/problem/14002

int p[1001];
int dp[1001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	int m = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			// 이전 숫자들과 비교해서 더 작은경우
			if (p[i] > p[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
				m = max(dp[i], m);
			}
		}
	}
	cout << m << '\n';
	
	stack<int> s;
	
	int max_num = 0;
	for (int i = n; i > 0; i--) {
		if (max_num == 0 && dp[i] == m) {
			max_num = p[i];
			s.push(p[i]);
			m--;
		}
		else if(p[i] < max_num && dp[i]==m){
			max_num = p[i];
			s.push(p[i]);
			m--;
		}
	}
	
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}