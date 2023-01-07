#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/1926

int map[501][501];
int visited[501][501];
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m;

int bfs(int x, int y) {
	queue<pair<int, int>> q;

	int paint_size = 1;
	q.push({ x,y });
	map[x][y] = 0;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int now_x = cur_x + dx[i];
			int now_y = cur_y + dy[i];

			if (now_x < 0 || now_x >= n || now_y < 0 || now_y >= m) { continue; }
			if (map[now_x][now_y] == 0) { continue; }

			q.push({ now_x, now_y });
			map[now_x][now_y] = 0;
			paint_size++;
		}
	}

	return paint_size;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int cnt = 0, size = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				size = max(size, bfs(i,j));
				cnt++;
			}
		}
	}

	cout << cnt << '\n' << size << '\n';

	return 0;
}