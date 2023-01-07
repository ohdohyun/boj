#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	queue<int> q;

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";
	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			int a = q.front();
			q.pop();
			q.push(a);
		}

		
		cout << q.front();
		q.pop();
		if (!q.empty()) { cout << ", "; }

	}

	cout << ">\n";

	return 0;
}