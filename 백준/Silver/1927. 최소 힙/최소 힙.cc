#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/1927

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		if (n == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(n);
		}
	}

	return 0;
}