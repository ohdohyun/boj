#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// https://www.acmicpc.net/problem/17299

int cnt[1000002];		// 각 숫자의 개수 저장
int arr[1000002];		// 수열 저장
int ans[1000002];
stack<int> s;		// 수열의 인덱스를 저장   // arr[index] - 수열의 수,  cnt[arr[index]] - i번째 수의 개수

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	for (int i = 0; i < n; i++) {
		// arr[i]번째의 cnt가 i+1 보다 크면 스택으로
		if (cnt[arr[i]] >= cnt[arr[i + 1]]) {
			s.push(i);
			//cout << "s.push(" << i << ")\n";
		}
		else {
			ans[i] = arr[i + 1];
			//cout << "ans[" << i << "] = arr[" << i + 1 << "]\n";

			//cout << "\ncnt[arr[s.top()]] < arr[i+1]? " << s.top() << ", " << arr[s.top()] << ", " << cnt[arr[s.top()]] << ", " << arr[i + 1] << '\n';
			while (!s.empty() && cnt[arr[s.top()]] < cnt[arr[i + 1]]) {
				ans[s.top()] = arr[i + 1];
				//cout << "ans[" << s.top() << "] = arr[" << i + 1 << "  ]\n";
				s.pop();

			}
		}
	}

	while (!s.empty()) {
		//cout << "s.pop(" << s.top() << ") = " << -1 << '\n';
		ans[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}

	
	return 0;
}