#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/2293

#define M 1000001
#define next nx[i]
pair<int, int> map[M];
int n;

void printRoute(int day) {
	int cur = n;
	for (int i = 0; i < day; i++) {
		cout << cur << ' ';
		cur = map[cur].second;
	}
}

void bfs() {
	queue<pair<int, int>> q;
	map[1] = { 1, 1 };
	q.push(map[1]);

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();	// first가 day second가 position
		if (cur.second == n) { cout << cur.first - 1 << '\n'; printRoute(cur.first); return; }
		int nx[3] = { cur.second* 3, cur.second * 2, cur.second + 1 };

		for (int i = 0; i < 3; i++) {
			if (next < 0 || next >= M) { continue; }	// 범위 밖
			if (map[next].first >= 1) { continue; }	// 이미 방문
			map[next] = { cur.first + 1, cur.second };
			q.push({ cur.first + 1, next });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	bfs();
	
	return 0;
}