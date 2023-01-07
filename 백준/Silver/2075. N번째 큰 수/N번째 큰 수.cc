#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/2075

priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			pq.push(-input);
			if (pq.size() > n) {
				pq.pop();
			}
		}
	}

	cout << -pq.top() << '\n';


	return 0;
}