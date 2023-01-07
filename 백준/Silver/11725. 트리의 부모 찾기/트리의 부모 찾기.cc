#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/

vector<int> map[100'001];
int p[100'001];

void bfs() {
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto e : map[cur]) {
			if (p[e] == 0) {
				q.push(e);
				p[e] = cur;
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	bfs();

	for (int i = 2; i <= n; i++) {
		cout << p[i] << '\n';
	}


	return 0;
}