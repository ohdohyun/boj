#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	int last = 0;
	while (!q.empty()) {
		last = q.front();
		q.pop();

		if (q.empty()) { break; }
		int temp = q.front();
		q.pop();
		q.push(temp);
	}

	cout << last << '\n';

	return 0;
}